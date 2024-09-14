#include "dijkstra_simple.h"

sp::dijkstra_simple::dijkstra_simple(const data::graph &graph, std::unordered_map<std::string, long> &distances,
                                     std::unordered_map<std::string, std::string> &predecessors)
        : m_graph{graph}, m_distances{distances}, m_relaxer{graph, distances, predecessors} {}

void sp::dijkstra_simple::compute() 
{
    std::unordered_set<std::string> hashSet;

    while (true)
    {
        int minimumDistance;
        std::string startVertex;

        for (auto& vertex: m_graph.vertices()) 
        {
            auto vertexName = vertex.name();
            auto distance = m_distances[vertexName];

            if ((startVertex == "" || minimumDistance >= distance) && !hashSet.contains(vertexName))
            {
                minimumDistance = distance;
                startVertex = vertexName;
            }
        }

        if (startVertex == "")
        {
            return;
        }

        hashSet.insert(startVertex);
        m_relaxer.scan_vertex(startVertex);
    }
}
