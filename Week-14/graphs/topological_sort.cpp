#include <algorithm>
#include "topological_sort.h"

namespace algos {
    topological_sort::topological_sort(const data::graph &graph)
    : m_graph{graph} {

    }

    bool topological_sort::compute() 
    {
        m_cycle_found = false;
        m_vertices.clear();
        
        for (const auto& vertex : m_graph.vertices()) 
        {
            auto vertexName = vertex.name();
            
            if (m_visited[vertexName] == 0) 
            {
                dfs(vertexName);
            }
        }
        
        if (m_cycle_found) 
        {
            return false;
        }
        
        std::reverse(m_vertices.begin(), m_vertices.end());
        
        return true;
    }

    const std::vector<std::string> &topological_sort::result() const {
        // The m_vertices contains the vertices in reverse post-order.
        return m_vertices;
    }

    void topological_sort::dfs(const std::string& vertex) 
    {
        m_visited[vertex]++;
        
        for (auto& edge : m_graph.find_vertex(vertex).edges()) 
        {
            auto edgeName = edge.target().name();

            if (m_visited[edgeName] == 0) 
            {
                dfs(edgeName);
            }
            else if (m_visited[edgeName] == 1)
            {
                m_cycle_found = true;
            }
        }
        
        m_visited[vertex]++;
        m_vertices.push_back(vertex);
    }
}