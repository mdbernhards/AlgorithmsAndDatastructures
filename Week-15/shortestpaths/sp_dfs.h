//
// Created by rgr24 on 09/06/2023.
//

#ifndef SHORTESTPATHS_SP_DFS_H
#define SHORTESTPATHS_SP_DFS_H

#include "graph.h"

/// Class to compute shortest paths using DFS
namespace sp {
    class sp_dfs {
    public:
        sp_dfs(data::graph &graph, std::unordered_map<std::string, long int> &distances,
               std::unordered_map<std::string, std::string> &predecessors);

        void compute(const std::string &start_vertex);

    private:
        data::graph &m_graph;
        std::unordered_map<std::string, long int> &m_distances;
        std::unordered_map<std::string, std::string> &m_predecessors;
    };
} // sp

#endif //SHORTESTPATHS_SP_DFS_H
