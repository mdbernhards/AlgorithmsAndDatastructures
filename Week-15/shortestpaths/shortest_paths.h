//
// Created by rgr24 on 29/05/2021.
//

#ifndef GRAPHS_FULL_SHORTEST_PATHS_H
#define GRAPHS_FULL_SHORTEST_PATHS_H

#include "graph.h"

enum class algorithm {
    dfs,
    dijkstra_simple,
    dijkstra_heap
};

class shortest_paths {
    friend class shortest_paths_tester;
public:
    shortest_paths(data::graph &graph);

    // computes the shortest paths from the source vertex
    void compute(const std::string &source, algorithm algo = algorithm::dfs);

    // writes the graph and found shortest paths + distances to a dot file
    //bool to_dot(const std::string& filename);
    static constexpr long int VERY_FAR = 123456789;
private:
    void scan_vertex(const std::string &vertex);

    void colour_paths(data::colour colour);

    void label_distances();

    // a reference to the graph for which this instance computes the shortest path
    data::graph& m_graph;

    std::unordered_map<std::string, long int> m_distances{};

    std::unordered_map<std::string, std::string> m_predecessors{};
};


#endif //GRAPHS_FULL_SHORTEST_PATHS_H
