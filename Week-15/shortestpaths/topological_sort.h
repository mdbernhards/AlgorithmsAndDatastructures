#ifndef SHORTESTPATHS_TOPOLOGICAL_SORT_H
#define SHORTESTPATHS_TOPOLOGICAL_SORT_H

#include <string>
#include <vector>
#include <unordered_map>
#include "graph.h"

class topological_sort {
public:
    topological_sort(const data::graph& graph);

    /// Topologically orders the vertices reachable from start
    /// \param start the vertex from which to start the search
    /// \param previous the direct neighbour of start from which we reached it
    void dfs(const std::string& start, const std::string& previous);

    bool compute(const std::string& start);

    const std::vector<std::string>& topological_order() const;

    bool is_cyclic() const;
private:
    const data::graph& m_graph;

    bool m_cyclic{};

    std::unordered_map<std::string, int> m_visits{};

    // the vertices that have been visited, in post order
    std::vector<std::string> m_post_visited{};
};


#endif //SHORTESTPATHS_TOPOLOGICAL_SORT_H
