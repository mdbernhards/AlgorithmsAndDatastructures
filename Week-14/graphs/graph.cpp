#include "graph.h"
#include <exception>
#include <fstream>
#include <iomanip>
#include "colours.h"

namespace data {

    bool graph::is_directed() const {
        return m_directed;
    }

    size_t graph::num_vertices() const {
        return m_vertices.size();
    }

    size_t graph::num_edges() const {
        return m_num_edges;
    }

    size_t graph::add_vertex(const std::string &name) {
        //if (std::all_of(name.begin(), name.end(), [&](const auto &item) { return std::iswspace(item); }))
           // throw std::invalid_argument("add_vertex: illegal vertex name");

        if (m_name_to_id.find(name) != m_name_to_id.end())
            throw std::invalid_argument("add_vertex: Vertex with name \"" + name + "\" already exists");

        m_name_to_id[name] = m_vertices.size();
        m_vertices.push_back(graph::vertex{name, m_vertices.size()});

        return m_vertices.size() - 1;
    }

    void graph::add_edge(const std::string &from, const std::string &to) {
        // lookup source
        auto it = m_name_to_id.find(from);
        auto source_id = it != m_name_to_id.end() ? it->second : add_vertex(from);

        // lookup target
        it = m_name_to_id.find(to);
        auto target_id = it != m_name_to_id.end() ? it->second : add_vertex(to);

        // add edge (source -> to)
        m_vertices[source_id].m_edges.emplace_back(graph::edge{*this, target_id});

        if (!m_directed) {
            // add an edge from 'to' to from
            m_vertices[target_id].m_edges.emplace_back(graph::edge{*this, source_id});
        }
        m_num_edges++;
    }

    const std::vector<graph::vertex> &graph::vertices() const {
        return m_vertices;
    }

    size_t graph::find_id(const std::string &label) const {
        auto entry = m_name_to_id.find(label);
        if (entry == m_name_to_id.end())
            throw std::invalid_argument("No vertex found with name \"" + label + "\"");

        return entry->second;
    }

    graph::edge& graph::find_edge(const std::string &from, const std::string &to) {
        auto &source = m_vertices[find_id(from)];
        for (auto & edge : source.m_edges) {
            if (edge.target().name() == to) return edge;
        }
        throw std::invalid_argument("No edge found from \"" + from + "\" to \"" + to + "\"");
    }

    const graph::vertex &graph::find_vertex(const std::string &name) const {
        return m_vertices[find_id(name)];
    }

    const graph::vertex &graph::operator[](const std::string &name) const {
        return m_vertices[find_id(name)];
    }

    graph::vertex &graph::operator[](const std::string &name) {
        return m_vertices[find_id(name)];
    }

    graph::graph(bool is_directed)
            : m_directed{is_directed}, m_num_edges{0} {
        m_vertices.reserve(50);
    }

    graph graph::load(const std::string &filename) {
        std::ifstream input{filename};
        if (!input) throw std::invalid_argument{"Could not open file"};
        std::string line;
        input >> line;
        bool directed;
        if ("directed" == line) directed = true;
        else if ("undirected" == line) directed = false;
        else throw std::logic_error{"first line in file must be directed/undirected"};
        std::getline(input, line); // skip rest of line
        if (line.find_first_not_of(" \t\n\v\f\r") != std::string::npos)
            throw std::logic_error{"first line in file must be directed/undirected"};

        graph result{directed};
        while (std::getline(input, line)) {
            std::istringstream iss{line};
            if (std::string from, to; iss >> from >> to) {
                if (!result.m_name_to_id.contains(from)) result.add_vertex(from);
                if (!result.m_name_to_id.contains(to)) result.add_vertex(to);
                result.add_edge(from, to);
            }
        }
        return result;
    }

    graph::graph(graph &&other)
            : m_directed{other.m_directed},
              m_num_edges{other.m_num_edges},
              m_vertices(std::move(other.m_vertices)),
              m_name_to_id(std::move(other.m_name_to_id)) {
        for (auto &v: m_vertices) {
            for (auto &vw: v.m_edges) {
                vw.m_graph = this;
            }
        }
    }

    graph &graph::operator=(const graph &other) {
        m_vertices.clear();
        m_name_to_id.clear();
        m_directed = other.m_directed;
        m_num_edges = 0;

        for (auto &v: other.m_vertices) {
            for (auto &vw: v.m_edges) {
                add_edge(v.name(), vw.target().name());
            }
            auto &thisv = m_vertices[find_id(v.name())];
            thisv.m_colour = v.m_colour;
            thisv.m_label = v.m_label;
        }
        return *this;
    }

    const graph::vertex &graph::edge::target() const {
        return m_graph->m_vertices[m_target];
    }

    data::colour graph::edge::colour() const {
        return m_colour;
    }

    void graph::edge::set_colour(data::colour colour) {
        m_colour = colour;
    }

    graph::edge::edge(const graph &g, size_t adjacent_vertex)
            : m_graph{&g},
              m_target{adjacent_vertex} {

    }

    graph::vertex::vertex(const std::string &name, size_t id)
            : m_id{id}, m_name{name}, m_colour{colour::white} {

    }

    const std::string &graph::vertex::name() const {
        return m_name;
    }

    const std::vector<graph::edge> &graph::vertex::edges() const {
        return m_edges;
    }

    data::colour graph::vertex::colour() const {
        return m_colour;
    }

    void graph::vertex::set_label(const std::string &value) {
        m_label = value;
    }

    void graph::vertex::set_colour(data::colour value) {
        m_colour = value;
    }

    const std::string &graph::vertex::label() const {
        return m_label;
    }

}

