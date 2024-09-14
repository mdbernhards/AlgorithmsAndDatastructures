#ifndef GRAPHS_FULL_TRAVERSAL_TESTER_H
#define GRAPHS_FULL_TRAVERSAL_TESTER_H

#include <string>
#include "colours.h"
#include "graph.h"

namespace algos {

    class traversal_tester {
    public:
        static void test_find_path_result();
        static void test_path_colouring();
        static void test_avoid_cycle();
        static void test_detect_cycle();
        static void test_colour_cycle();
        static void test_post_order();
        static void test_topological_sort();
        static bool is_path(const data::graph& graph, const std::string& source, const std::string& target, data::colour colour);
        static bool has_cycle(const data::graph& graph, data::colour colour);
        static bool is_reachable(const data::graph& graph, const std::string& vertex, const std::string& from);
        static size_t count_edges(const data::graph& graph, data::colour colour);
        static size_t count_vertices(const data::graph& graph, data::colour colour);
        static bool is_valid_top_order(const data::graph& graph, const std::vector<std::string>& top_order);
    };

} // alogs

#endif //GRAPHS_FULL_TRAVERSAL_TESTER_H
