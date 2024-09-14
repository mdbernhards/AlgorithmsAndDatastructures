#ifndef SHORTESTPATHS_DIJKSTRA_SIMPLE_H
#define SHORTESTPATHS_DIJKSTRA_SIMPLE_H

#include <string>
#include <unordered_map>
#include "graph.h"
#include "relaxer.h"

namespace sp {
    class dijkstra_simple {
    public:
        dijkstra_simple(const data::graph &graph, std::unordered_map<std::string, long int> &distances,
                        std::unordered_map<std::string, std::string> &predecessors);

        /// Computes the shortest paths from the start vertex to all other vertices in the graph.
        /// No parameter is needed - the start vertex is the one with the lowest distance (0).
        void compute();

    private:
        const data::graph &m_graph;
        std::unordered_map<std::string, long int> &m_distances;
        sp::relaxer m_relaxer;
    };
}

#endif //SHORTESTPATHS_DIJKSTRA_SIMPLE_H
