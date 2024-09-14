#ifndef GRAPHS_FULL_DOT_WRITER_H
#define GRAPHS_FULL_DOT_WRITER_H


#include <ostream>
#include "graph.h"

class dot_writer {
public:
    // writes the graph to the file name filedname, which can be visualized online
    static void write(const data::graph& graph, const std::string& filename);

    static void write(const data::graph& graph, std::ostream& os);
};


#endif //GRAPHS_FULL_DOT_WRITER_H
