#include <iostream>
#include <cassert>
#include "graph.h"
#include "shortest_paths.h"
#include "shortest_paths_tester.h"
#include "dot_writer.h"

int main() {
    // Activity 2: depth-first shortest paths
    auto g2 = data::graph::load("activity2.graph");
    dot_writer::write(g2, "activity2.dot");
    shortest_paths sp2{g2};
    sp2.compute("a", algorithm::dfs);
    shortest_paths_tester::verify_paths(sp2);

    // Activity 3: vertex scanning and edge relaxation
    shortest_paths_tester::test_relax_edge();
    shortest_paths_tester::test_scan_vertex();

    // Activity 4: Depth-first traversal in undirected graphs
    shortest_paths_tester::test_topsort();

    // Activity 5: Shortest paths in acyclic graphs
    auto g5 = data::graph::load("activity5.graph");
    shortest_paths sp5{g5};
    sp5.compute("a", algorithm::dfs);
    shortest_paths_tester::verify_paths(sp5);
    dot_writer::write(g5, "activity5.dot");

    // Activity 6: Dijkstra's algorithm - linear search
    auto g6 = data::graph::load("activity6.graph");
    dot_writer::write(g6, "activity6.dot");
    shortest_paths sp6{g6};
    sp6.compute("a", algorithm::dijkstra_simple);
    shortest_paths_tester::verify_paths(sp6);

    // Activity 8: Dijkstra's algorithm - binary heap
    auto g8 = data::graph::load("activity8.graph");
    dot_writer::write(g8, "activity8.dot");
    shortest_paths sp8{g8};
    sp8.compute("a", algorithm::dijkstra_heap);
    shortest_paths_tester::verify_paths(sp8);

    // Activity 5: Shortest paths in acyclic graphs
    auto gn = data::graph::load("negative.graph");
    shortest_paths spn{gn};
    spn.compute("a", algorithm::dijkstra_heap);
    shortest_paths_tester::verify_paths(spn);
    dot_writer::write(gn, "negative.dot");

    auto g5n = data::graph::load("negative.graph");
    shortest_paths sp5n{g5n};
    sp5n.compute("a", algorithm::dfs);
    shortest_paths_tester::verify_paths(sp5n);
    dot_writer::write(g5n, "negative2.dot");


    // Activity 10: Dijkstra's algorithm - negative edge weights
    // - load the graph "negative.graph"
    // - compute shortest paths from vertex "a"
    // - visualize the paths using the dot_writer class
    auto g_neg = data::graph::load("negative.graph");
    dot_writer::write(g_neg, "negative5.dot");
    shortest_paths sp_neg{g_neg};
    sp_neg.compute("a", algorithm::dijkstra_heap);

    return 0;
}
