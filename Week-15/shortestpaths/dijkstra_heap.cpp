#include "dijkstra_heap.h"
#include "vertex_heap.h"

sp::dijkstra_heap::dijkstra_heap(const data::graph &graph, std::unordered_map<std::string, long> &distances,
                                 std::unordered_map<std::string, std::string> &predecessors)
        : m_graph{graph}, m_distances{distances}, m_relaxer{graph, distances, predecessors} {}

void sp::dijkstra_heap::compute(const std::string &start) 
{
    std::unordered_set<std::string> hashSet;
    auto vertexHeap = new vertex_heap();

    vertexHeap->insert(start, 0);

    while (!vertexHeap->empty())
    {
        std::string startVertex = vertexHeap->min();
        vertexHeap->delete_min();

        if (!hashSet.contains(startVertex))
        {
            hashSet.insert(startVertex);

            for (const auto &edge : m_graph[startVertex].edges())
            {
                auto vertexName = edge.target().name();
                auto distance = m_distances[vertexName];

                m_relaxer.relax_edge(startVertex, vertexName);

                if (distance != m_distances[vertexName])
                {
                    vertexHeap->insert(vertexName, m_distances[vertexName]);
                }
            }
        }
    }
}
