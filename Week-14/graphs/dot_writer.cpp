#include <iomanip>
#include <fstream>
#include "dot_writer.h"

void dot_writer::write(const data::graph& graph, std::ostream &file) {
    file << "digraph g {" << std::endl
         << "\trankdir = LR;"
         << "\tnode[shape=circle style=filled];" << std::endl;

    // go over vertices, emit their name and colour
    for (const auto &v: graph.vertices()) {
        file << "\t" << v.name() << "[name=" << std::quoted(v.name());
        if (!v.label().empty()) {
            file << ", set_label=\"" << v.name() << "\\n" << v.label() << "\"";
        }
        file << ", fillcolor=" << std::quoted(to_string(v.colour())) << "];" << std::endl;
    }

    // go over edges
    file << std::endl << "\tedge[dir = " << (graph.is_directed() ? "forward" : "none") << "];" << std::endl;
    for (const auto &v: graph.vertices()) {
        for (const auto &edge: v.edges()) {
            if (graph.is_directed() || v.name() < edge.target().name()) {
                file << "\t" << v.name() << " -> " << edge.target().name() << "[";
                file << "penwidth=2, ";
                file << "color=" << std::quoted(to_string(edge.colour()));
                file << "];" << std::endl;
            }
        }
    }
    file << "}" << std::endl;
}

void dot_writer::write(const data::graph &graph, const std::string &filename) {
    std::ofstream file{filename};
    if (file.is_open()) {
        write(graph, file);
    } else
        throw std::runtime_error("Unable to open file " + filename);
}
