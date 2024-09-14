//
// Created by rgr24 on 11/06/2023.
//

#ifndef SHORTESTPATHS_RELAXER_H
#define SHORTESTPATHS_RELAXER_H

#include "graph.h"

namespace sp {

    class relaxer {
    public:
        relaxer(const data::graph &graph, std::unordered_map<std::string, long int> &distances,
                std::unordered_map<std::string, std::string> &predecessors);

        void scan_vertex(const std::string &vertex);
        bool relax_edge(const std::string &from, const std::string &to);
    private:
        const data::graph &m_graph;
        std::unordered_map<std::string, long int> &m_distances;
        std::unordered_map<std::string, std::string> &m_predecessors;
    };

} // sp

#endif //SHORTESTPATHS_RELAXER_H
