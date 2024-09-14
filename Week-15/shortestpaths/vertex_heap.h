#ifndef GRAPHS_FULL_HEAP_DATA_H
#define GRAPHS_FULL_HEAP_DATA_H

#include <string>
#include <vector>

namespace sp {
    struct vertex_with_known_distance {
        std::string vertex;
        int distance;

        // less-than operator so that the heap can compare vertex_with_known_distance values
        bool operator<(const vertex_with_known_distance &other) const {
            return distance > other.distance;
        }
    };

/// A heap that orders vertices by their (current known) shortest distance
    class vertex_heap {
    public:
        // returns true if the heap is empty, false otherwise
        bool empty() const;

        // returns the vertex that lies at the shortest distance
        std::string min() const;

        // inserts a vertex and its associated distance
        void insert(const std::string &vertex, int distance);

        // removes the vertex that lies at the shortest distance
        void delete_min();

    private:
        std::vector<vertex_with_known_distance> m_data;
    };
} // sp
#endif //GRAPHS_FULL_HEAP_DATA_H
