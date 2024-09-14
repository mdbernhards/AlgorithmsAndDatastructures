#include <algorithm>
#include "topological_sort.h"

topological_sort::topological_sort(const data::graph &graph) : m_graph{graph} {}

void topological_sort::dfs(const std::string &start, const std::string &previous) 
{
    m_visits[start]++;
    
    for (auto& edge : m_graph.find_vertex(start).edges()) 
    {
        auto edgeName = edge.target().name();

        if (m_visits[edgeName] == 0) 
        {
            dfs(edgeName, start);
        }
        else if (m_visits[edgeName] == 1 && edgeName != previous)
        {
            m_cyclic = true;
        }
    }
    
    m_visits[start]++;
    m_post_visited.push_back(start);
}

bool topological_sort::compute(const std::string &start) {
    m_post_visited.clear();
    m_visits.clear();
    dfs(start, "");
    std::reverse(m_post_visited.begin(), m_post_visited.end());
    return !m_cyclic;
}

const std::vector<std::string> &topological_sort::topological_order() const {
    return m_post_visited;
}

bool topological_sort::is_cyclic() const {
    return m_cyclic;
}

