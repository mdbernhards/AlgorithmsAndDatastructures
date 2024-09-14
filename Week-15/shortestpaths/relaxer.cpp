#include "relaxer.h"

namespace sp {
    relaxer::relaxer(const data::graph &graph, std::unordered_map<std::string, long> &distances,
                     std::unordered_map<std::string, std::string> &predecessors)
                     : m_graph{graph}, m_distances{distances}, m_predecessors{predecessors} {
    }

    void relaxer::scan_vertex(const std::string &vertex) 
    {
        for (auto& edge : m_graph.find_vertex(vertex).edges()) 
        {
            auto edgeName = edge.target().name();
            
            if (relax_edge(vertex, edgeName))
            {
                m_predecessors[edgeName] = vertex;
            }
        }
    }

    bool relaxer::relax_edge(const std::string &from, const std::string &to) 
    {
        auto newDistance = m_graph.find_edge(from, to).weight() + m_distances[from];
        
        if (newDistance < m_distances[to])
        {
            m_distances[to] = newDistance;

            return true;
        }
        
        return false;
    }
} // sp