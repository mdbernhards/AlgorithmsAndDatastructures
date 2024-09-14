#include "visitor.h"

visitor::visitor(data::graph &graph) : m_graph{graph} 
{
}

// Searches the graph for a path from start_vertex to goal.
// Returns true if it was found, false otherwise
bool visitor::find_path(const string &start_vertex, const string &goal) 
{
    // TODO:
    //  Make sure that the correct result is returned (Activity 3)
    //  Colour the path (Activity 4)
    //  Make sure that no vertices are visited twice (Activity 5)
    //  Keep track of number of visits to avoid cycles (Activity 6)
    //  Colour the cycle (Activity 7)
    m_visited[start_vertex]++;
    m_path.push_back(start_vertex);

    if (start_vertex == goal)
    {
        std::string tempVertex;
        for (const auto& vertex_name : m_path) 
        {
            m_graph[vertex_name].set_colour(data::colour::red);

            if (!tempVertex.empty())
            {
                auto& tempEdge = m_graph.find_edge(tempVertex, vertex_name);
                tempEdge.set_colour(data::colour::red);
            }

            tempVertex = vertex_name;
        }

        return true;
    }

    for (auto& edge : m_graph.find_vertex(start_vertex).edges()) 
    {
        const auto& vertex = edge.target().name();

        if (m_visited[vertex] == 0 && find_path(vertex, goal))
        {
            return true;
        }
        else if (m_visited[vertex] == 1 && !m_cycle_found)
        {
            m_cycle_found = true;
            auto cycleStarted = false;
            std::string tempVertex;

            for (const auto& pathVertex : m_path) 
            {
                if (vertex == pathVertex)
                {
                    cycleStarted = true;
                }
                
                if (cycleStarted)
                {
                    m_graph[pathVertex].set_colour(data::colour::blue);

                    if (!tempVertex.empty())
                    {
                        auto& tempEdge = m_graph.find_edge(tempVertex, pathVertex);
                        tempEdge.set_colour(data::colour::blue);
                    }
                    
                    tempVertex = pathVertex;
                }
            }

            auto& lastEdge = m_graph.find_edge(tempVertex, vertex);
            lastEdge.set_colour(data::colour::blue);
        }
    }

    m_path.pop_back();
    m_visited[start_vertex]--;

    return false;
}

bool visitor::cycle_found() const {
    return m_cycle_found;
}
