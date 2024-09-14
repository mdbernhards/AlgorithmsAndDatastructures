#ifndef GRAPHS_FULL_TOPOLOGICAL_SORT_H
#define GRAPHS_FULL_TOPOLOGICAL_SORT_H

#include <string>
#include <vector>
#include "graph.h"

namespace algos {

    class topological_sort {
    friend class traversal_tester;
    public:
        topological_sort(const data::graph &graph);
        bool compute();
        const std::vector<std::string> &result() const;
    private:
        void dfs(const std::string& vertex);
        const data::graph &m_graph;
        bool m_cycle_found{false};
        std::unordered_map<std::string, int> m_visited;
        std::vector<std::string> m_vertices{};

        // TODO: add more member variables here
    };
} // algos

#endif //GRAPHS_FULL_TOPOLOGICAL_SORT_H
