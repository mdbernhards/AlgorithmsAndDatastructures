#include <cassert>
#include "traversal_tester.h"
#include "visitor.h"
#include "dot_writer.h"
#include "topological_sort.h"

namespace algos {
    bool traversal_tester::is_valid_top_order(const data::graph &graph, const std::vector<std::string> &top_order) {
        for (size_t i = 0; i < top_order.size(); ++i) {
            for (size_t j = i + 1; j < top_order.size(); ++j) {
                if (is_reachable(graph, top_order[i], top_order[j])) return false;
            }
        }
        return true;
    }

    size_t traversal_tester::count_edges(const data::graph &graph, data::colour colour) {
        size_t result = 0;
        for (const auto& v : graph.vertices()) {
            for (const auto & edge : v.edges()) {
                if (edge.colour() == colour) result++;
            }
        }
        return result;
    }

    size_t traversal_tester::count_vertices(const data::graph &graph, data::colour colour) {
        size_t result = 0;
        for (const auto& v : graph.vertices()) {
            if (v.colour() == colour) result++;
        }
        return result;
    }

    bool traversal_tester::is_reachable(const data::graph &graph, const std::string &vertex, const std::string &from) {
        std::unordered_set<std::string> reachable{};
        reachable.insert(from);
        bool changed;
        do {
            changed = false;
            for (const auto& v: reachable) {
                for (const auto &edge: graph[v].edges()) {
                    const auto &w = edge.target().name();
                    if (w == vertex) return true;

                    auto pair = reachable.insert(w);
                    if (pair.second) changed = true;
                }
            }
        }
        while (changed);
        return false;
    }

    bool traversal_tester::is_path(const data::graph &graph, const std::string &source, const std::string &target,
                                   data::colour colour) {
        struct degree {
            size_t in_degree{};
            size_t out_degree{};
        };
        std::unordered_map<std::string, degree> degrees{};
        for (const auto& v : graph.vertices()) {
            for (const auto & edge : v.edges()) {
                const auto & w = edge.target();
                if (edge.colour() == colour) {
                    degrees[w.name()].in_degree++;
                    degrees[v.name()].out_degree++;
                }
            }
        }

        if (!degrees.contains(source)) return false;
        if (!degrees.contains(target)) return false;
        if (degrees[source].in_degree != 0) return false;
        if (degrees[target].out_degree != 0) return false;
        degrees.erase(source);
        degrees.erase(target);
        for (const auto& [name, degree] : degrees) {
            if (degree.in_degree != 1 || degree.out_degree != 1) return false;
        }
        return true;
    }

    bool traversal_tester::has_cycle(const data::graph& graph, data::colour colour) {
        struct degree {
            size_t in_degree{};
            size_t out_degree{};
        };
        std::unordered_map<std::string, degree> degrees{};
        for (const auto& v : graph.vertices()) {
            for (const auto & edge : v.edges()) {
                const auto & w = edge.target();
                if (edge.colour() == colour) {
                    degrees[w.name()].in_degree++;
                    degrees[v.name()].out_degree++;
                }
            }
        }
        for (const auto& [name, degree] : degrees) {
            if (degree.in_degree != 1 || degree.out_degree != 1) return false;
        }
        return true;
    }

    void traversal_tester::test_find_path_result() {
        auto g = data::graph::load("act3.graph");

        // Test if path is found
        assert(visitor{g}.find_path("a", "d"));
        assert(visitor{g}.find_path("a", "g"));
        assert(visitor{g}.find_path("a", "h"));
        assert(visitor{g}.find_path("b", "d"));

        // Test if path is not found
        assert(!visitor{g}.find_path("e", "b"));
        assert(!visitor{g}.find_path("g", "h"));

        std::cerr << "Test find_path_result PASSED!" << std::endl;
    }

    void traversal_tester::test_path_colouring() {
        auto g = data::graph::load("act4.graph");

        assert(!visitor{g}.find_path("f", "e"));
        assert(count_edges(g, data::colour::red) == 0);
        assert(count_vertices(g, data::colour::red) == 0);

        assert(visitor{g}.find_path("a", "g"));
        // Write graph to file for visual inspection
        dot_writer::write(g, "test_path_colouring.dot");
        assert(count_edges(g, data::colour::red) > 0);
        assert(count_vertices(g, data::colour::red) > 0);
        assert(count_vertices(g, data::colour::red) == count_edges(g, data::colour::red) + 1);
        assert(is_path(g, "a", "g", data::colour::red));

        std::cerr << "Test path_colouring PASSED!" << std::endl;
    }

    void traversal_tester::test_avoid_cycle() {
        // load cylic graph
        auto g = data::graph::load("act5.graph");
        assert(visitor{g}.find_path("a", "f"));
        assert(visitor{g}.find_path("a", "g"));

        std::cerr << "Test avoid_cycle PASSED!" << std::endl;
    }

    void traversal_tester::test_detect_cycle() {
        auto g = data::graph::load("act6.graph"); // acyclic graph

        visitor vis_acyclic{g};
        assert(!vis_acyclic.find_path("a", "z"));
        assert(!vis_acyclic.cycle_found());

        auto g2 = data::graph::load("act5.graph"); // cyclic graph
        visitor vis_cyclic{g2};
        assert(!vis_cyclic.find_path("a", "z"));
        assert(vis_cyclic.cycle_found());

        std::cerr << "Test detect_cycle PASSED!" << std::endl;
    }

    void traversal_tester::test_colour_cycle() {
        auto acyclic = data::graph::load("act6.graph"); // acyclic graph

        assert(!visitor{acyclic}.find_path("a", ""));
        assert(count_edges(acyclic, data::colour::blue) == 0);
        assert(count_vertices(acyclic, data::colour::blue) == 0);

        auto cyclic = data::graph::load("act5.graph"); // cyclic graph
        assert(!visitor{cyclic}.find_path("a", ""));
        // Write graph to file for visual inspection
        dot_writer::write(cyclic, "test_colour_cycle.dot");
        assert(count_edges(cyclic, data::colour::blue) > 0);
        assert(count_vertices(cyclic, data::colour::blue) > 0);
        assert(count_vertices(cyclic, data::colour::blue) == count_edges(cyclic, data::colour::blue));
        assert(has_cycle(cyclic, data::colour::blue));

        std::cerr << "Test colour_cycle PASSED!" << std::endl;
    }

    void traversal_tester::test_post_order() {
        auto acyclic = data::graph::load("act6.graph"); // acyclic graph
        {
            algos::topological_sort sort{acyclic};
            sort.dfs("a");
            std::vector<string> option1 = {"e", "d", "g", "c", "f", "b", "a"};
            std::vector<string> option2 = {"e", "d", "g", "c", "b", "f", "a"};
            std::vector<string> option3 = {"e", "g", "d", "c", "f", "b", "a"};
            std::vector<string> option4 = {"e", "g", "d", "c", "b", "f", "a"};
            assert(sort.m_vertices == option1 || sort.m_vertices == option2 ||
                   sort.m_vertices == option3 || sort.m_vertices == option4);
        }

        auto cyclic = data::graph::load("act5.graph"); // cyclic graph
        {
            algos::topological_sort sort{cyclic};
            sort.dfs("a");
            std::vector<string> option1 = {"f", "d", "g", "e", "c", "b", "a"};
            std::vector<string> option2 = {"g", "e", "f", "d", "c", "b", "a"};
            assert(sort.m_vertices == option1 || sort.m_vertices == option2);
        }

        std::cerr << "Test post_order PASSED!" << std::endl;
    }

    void traversal_tester::test_topological_sort() {
        auto cyclic = data::graph::load("act5.graph"); // cyclic graph
        {
            algos::topological_sort sort{cyclic};
            assert(!sort.compute());
        }

        auto acyclic = data::graph::load("act9.graph"); // acyclic graph
        {
            algos::topological_sort sort{acyclic};
            assert(sort.compute());
            assert(is_valid_top_order(acyclic, sort.result()));
        }

        std::cerr << "Test topological_sort PASSED!" << std::endl;
    }

} // alogs