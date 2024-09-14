#include "sp_dfs.h"

sp::sp_dfs::sp_dfs(data::graph &graph, std::unordered_map<std::string, long> &distances,
               std::unordered_map<std::string, std::string> &predecessors)
               : m_graph{graph}, m_distances{distances}, m_predecessors{predecessors} {
}

void sp::sp_dfs::compute(const std::string &start) 
{
    for (auto& edge : m_graph.find_vertex(start).edges()) 
    {
        auto edgeName = edge.target().name();
        auto newDistance = edge.weight() + m_distances[start];
        
        if (newDistance < m_distances[edgeName])
        {
            m_distances[edgeName] = newDistance;
            m_predecessors[edgeName] = start;

            compute(edgeName);
        }
    }
}
