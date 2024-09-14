#include <algorithm>
#include <iomanip>
#include <fstream>
#include <set>
#include "shortest_paths.h"
#include "vertex_heap.h"
#include "topological_sort.h"
#include "sp_dfs.h"
#include "relaxer.h"
#include "dijkstra_heap.h"
#include "dijkstra_simple.h"

shortest_paths::shortest_paths(data::graph &graph)
        : m_graph{graph} {
}

void shortest_paths::compute(const std::string &source, algorithm algo) 
{
    m_predecessors.clear();
    for (const auto& v : m_graph.vertices()) m_distances[v.name()] = VERY_FAR;
    m_distances[source] = 0;
    
    sp::relaxer relaxer{m_graph, m_distances, m_predecessors};

    topological_sort topSort(m_graph);
    topSort.compute(source);

    if (!topSort.is_cyclic()) 
    {
        for (const auto& vertex : topSort.topological_order()) 
        {
            relaxer.scan_vertex(vertex);
        }
    } 
    else 
    {
        if (algo == algorithm::dfs) 
        {
            sp::sp_dfs dfs(m_graph, m_distances, m_predecessors);
            dfs.compute(source);
        }
        else if (algo == algorithm::dijkstra_simple)
        {
            sp::dijkstra_simple dijkstra(m_graph, m_distances, m_predecessors);
            dijkstra.compute();
        }
        else if (algo == algorithm::dijkstra_heap)
        {
            sp::dijkstra_heap dijkstra(m_graph, m_distances, m_predecessors);
            dijkstra.compute(source);
        }
        
    }
    // TODO Activity 2: run depth-first search (use the sp_dfs class)

    // TODO Activity 5: if graph is acyclic, compute shortest paths by scanning vertices
    //   in topological order. Use the topological_sort class to obtain the order.
    //   Use the relaxer class to scan vertices and relax edges.
    //   If graph is cyclic, compute shortest paths using:
    //    - depth-first search (Activity 2)
    //    - Dijkstra's algorithm (linear search) (Activity 6)
    //    - Dijkstra's algorithm (binary heap) (Activity 8)
    //  (Use the algo parameter to decide which algorithm to run)

    colour_paths(data::colour::green);
    label_distances();
}

void shortest_paths::colour_paths(data::colour colour) {
    for (const auto& [vertex, predecessor] : m_predecessors) {
        m_graph.find_edge(predecessor, vertex).set_colour(colour);
    }
}

void shortest_paths::label_distances() {
    for (const auto& [vertex, distance] : m_distances) {
        m_graph[vertex].set_label("d:" + std::to_string(distance));
    }
}