#ifndef SHORTESTPATHS_DIJKSTRA_HEAP_H
#define SHORTESTPATHS_DIJKSTRA_HEAP_H

#include "relaxer.h"

namespace sp {
    class dijkstra_heap {
    public:
        dijkstra_heap(const data::graph &graph, std::unordered_map<std::string, long int> &distances,
                        std::unordered_map<std::string, std::string> &predecessors);

        void compute(const std::string &start);

    private:
        const data::graph &m_graph;
        std::unordered_map<std::string, long int> &m_distances;
        sp::relaxer m_relaxer;
    };
}


#endif //SHORTESTPATHS_DIJKSTRA_HEAP_H
