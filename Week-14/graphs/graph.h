//
// Created by rgr24 on 18/05/2021.
//

#ifndef GRAPHS_FULL_GRAPH_H
#define GRAPHS_FULL_GRAPH_H

#include <ostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include "colours.h"

namespace data {
    class graph {
    public:
        class vertex;
        class edge;

        // constructor - constructs a directed or undirected graph
        graph(bool is_directed);

        // loads a graph from file
        static graph load(const std::string &filename);

        // move constructor - constructs a new graph from a temporary graph
        graph(graph &&other);

        // copy assignment
        graph &operator=(const graph &other);

        // returns true if the graph is directed, false otherwise
        bool is_directed() const;

        // returns the number of vertices
        size_t num_vertices() const;

        // returns the number of edges
        size_t num_edges() const;

        // adds a new vertex to the graph, returns its index in the m_vertices vector
        // throws an exception if a vertex with that name already exists
        size_t add_vertex(const std::string &name);

        // connects two vertices with an edge from <from> to <to>
        // if the graph is undirected, <to> will have an edge to <from> as well
        void add_edge(const std::string &from, const std::string &to);

        // returns the vertices of the graph
        const std::vector<vertex> &vertices() const;

        // looks up the vertex with the given name
        const vertex &find_vertex(const std::string &name) const;

        edge& find_edge(const std::string &from, const std::string &to);

        // looks up the vertex with the given name
        const vertex &operator[](const std::string &name) const;

        vertex &operator[](const std::string &name);
    private:

        size_t find_id(const std::string &label) const;

        bool m_directed;
        size_t m_num_edges{};

        std::vector<vertex> m_vertices;
        std::unordered_map<std::string, size_t> m_name_to_id;
    };

    class graph::vertex {
        friend class graph;

    public:
        vertex(vertex &&) = default;

        void set_label(const std::string &value);

        void set_colour(data::colour value);

        const std::string &label() const;

        const std::string &name() const;

        data::colour colour() const;

        const std::vector<edge> &edges() const;

    private:
        vertex(const std::string &name, size_t id);

        vertex(const vertex &) = delete; //default;

        size_t m_id;
        std::string m_name;
        std::string m_label;
        data::colour m_colour{data::colour::white};
        std::vector<edge> m_edges;
    };

    class graph::edge {
        friend class graph;

    public:
        const graph::vertex &target() const;

        data::colour colour() const;

        void set_colour(data::colour colour);

        edge(edge &&) = default;

        edge(edge &) = delete;

        edge &operator=(const edge &) = delete;

    private:

        edge(const graph &g, size_t adjacent_vertex);

        const graph *m_graph;
        size_t m_target;
        data::colour m_colour{data::colour::black};
    };
}
#endif //GRAPHS_FULL_GRAPH_H
