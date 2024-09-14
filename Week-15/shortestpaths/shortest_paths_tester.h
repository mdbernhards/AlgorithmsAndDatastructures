#ifndef GRAPHS_FULL_SHORTEST_PATHS_TESTER_H
#define GRAPHS_FULL_SHORTEST_PATHS_TESTER_H


#include "shortest_paths.h"

class shortest_paths_tester {
public:
    static void test_topsort();
    static void test_scan_vertex();
    static void test_relax_edge();
    static void verify_paths(shortest_paths& paths);
    static bool is_reached_before(const data::graph &graph, const std::string &source, const std::string &vertex,
                                  const std::string &before, std::unordered_set<std::string> &visited);
    static bool is_valid_top_order(const data::graph& graph, const std::string& source, const std::vector<std::string>& top_order);
};


#endif //GRAPHS_FULL_SHORTEST_PATHS_TESTER_H
