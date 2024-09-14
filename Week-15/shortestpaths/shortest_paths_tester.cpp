#include <iostream>
#include <iomanip>
#include <cassert>
#include "shortest_paths_tester.h"
#include "graph.h"
#include "shortest_paths.h"
#include "relaxer.h"
#include "topological_sort.h"
#include "dot_writer.h"

void shortest_paths_tester::test_scan_vertex() {

}

void shortest_paths_tester::test_relax_edge() {
    bool result = true;
    // create a directed graph
    data::graph g{true};
    g.add_edge("a", "b", 3);
    g.add_edge("a", "c", 5);
    g.add_edge("b", "c", 1);

    std::unordered_map<std::string, long int> distances{};
    std::unordered_map<std::string, std::string> predecessors{};
    sp::relaxer relaxer{g, distances, predecessors};
    distances["a"] = 0;
    distances["b"] = distances["c"] = 100;

    // relax (a, b) and verify distance to b has decreased to 3
    // relax (a, c) and verify distance to c has decreased to 5
    for (auto &edge: g["a"].edges()) {
        bool relaxed = relaxer.relax_edge("a", edge.target().name());
        if (!relaxed) {
            std::cerr << "Relaxing edge (a, " << edge.target().name() << ") must return true" << std::endl;
            result = false;
        }
        if (auto dist = distances[edge.target().name()]; dist != edge.weight()) {
            std::cerr << "After relaxing edge (a, " + edge.target().name() + "), "
                      << "distance to " << edge.target().name() << " must be "
                      << edge.weight() << ", but it is " << dist << std::endl;
            result = false;
        }
        relaxed = relaxer.relax_edge("a", edge.target().name());
        if (relaxed) {
            std::cerr << "Second relaxation of edge (a, " << edge.target().name() << ") must return false" << std::endl;
            result = false;
        }
    }

    bool relaxed = relaxer.relax_edge("b", "c");
    if (!relaxed) {
        std::cerr << "Relaxing edge (b, c) must return true" << std::endl;
        result = false;
    }
    if (auto dist = distances["c"]; dist != 4) {
        std::cerr << "After relaxing edges (a, b) and (b, c), distance to c must be 4, but it is " << dist << std::endl;
        result = false;
    }

    assert(result);
    if (result) std::cerr << "test_relax_edge PASS" << std::endl;
}

void shortest_paths_tester::verify_paths(shortest_paths &paths) {
    bool result = true;
    // verify that the shortest path to each vertex is via the predecessor
    for (const auto &[vertex, via] : paths.m_predecessors) {
        if (!paths.m_graph.has_vertex(via)) {
            std::cerr << "Shortest path to vertex " << std::quoted(vertex) << " is via " << std::quoted(via) << ", but there is no such vertex." << std::endl;
            result = false;
        }

        if (!paths.m_graph.has_edge(via, vertex)) {
            std::cerr << "Shortest path to vertex " << std::quoted(vertex) << " is via " << std::quoted(via) << ", but there is no edge that connects them." << std::endl;
            result = false;
        }
        else {
            const auto &edge = paths.m_graph.find_edge(via, vertex);
            if (paths.m_distances[via] + edge.weight() != paths.m_distances[vertex]) {
                std::cerr << "Shortest path to vertex " << std::quoted(vertex) << " supposedly is via "
                          << std::quoted(via) << ", but the distances don't add up." << std::endl;
                result = false;
            }
        }
    }

    // verify that there are no shorter paths
    for (const auto &vertex: paths.m_graph.vertices()) {
        auto distance = paths.m_distances[vertex.name()];

        for (const auto &edge: vertex.edges()) {
            const auto &target = edge.target().name();
            auto distance_to_target = paths.m_distances[target];

            if (distance + edge.weight() < distance_to_target) {
                std::cerr << "Reported smallest distance to " << std::quoted(target) << " is " << distance_to_target;
                std::cerr << ", but taking path via " << std::quoted(vertex.name()) << " to " << std::quoted(target);
                std::cerr << " is a shorter path!" << std::endl;
                result = false;
            }
        }
    }

    assert(result);
    std::cerr << "verify_paths PASS" << std::endl;
}

void shortest_paths_tester::test_topsort() {
    auto g = data::graph::load("test_topsort-1.graph");
    dot_writer::write(g, "test_topsort-1.dot");

    topological_sort sorter{g};
    bool ordering_exists = sorter.compute("a");
    assert(ordering_exists);
    assert(is_valid_top_order(g, "a", sorter.topological_order()));

    ordering_exists = sorter.compute("aa");
    assert(!ordering_exists);

    auto g_dir = data::graph::load("test_topsort-2.graph");
    dot_writer::write(g_dir, "test_topsort-2.dot");

    topological_sort sorter_dir{g_dir};
    ordering_exists = sorter_dir.compute("a");
    assert(ordering_exists);
    assert(is_valid_top_order(g_dir, "a", sorter_dir.topological_order()));

    std::cerr << "test_topsort PASS" << std::endl;
}

bool shortest_paths_tester::is_valid_top_order(const data::graph &graph, const std::string& source, const std::vector<std::string> &top_order) {
    for (size_t i = 0; i < top_order.size(); ++i) {
        for (size_t j = i + 1; j < top_order.size(); ++j) {
            std::unordered_set<std::string> visited;
            if (is_reached_before(graph, source, top_order[j], top_order[i], visited)) return false;
        }
    }
    return true;
}

bool
shortest_paths_tester::is_reached_before(const data::graph &graph, const std::string &source, const std::string &vertex,
                                         const std::string &before, std::unordered_set<std::string> &visited) {
    if (vertex == "") return false;
    if (!visited.insert(source).second) return false;
    if (source == before) return false;
    else if (source == vertex) {
        for (const auto& edge : graph[source].edges()) {
            const auto& target = edge.target().name();
            if (is_reached_before(graph, target, before, "", visited)) return true;
        }
    }
    else {
        for (const auto& edge : graph[source].edges()) {
            const auto& target = edge.target().name();
            if (is_reached_before(graph, target, vertex, before, visited)) return true;
        }
    }
    return false;
}
