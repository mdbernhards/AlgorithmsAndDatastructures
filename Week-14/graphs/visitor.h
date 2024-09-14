//
// Created by rgr24 on 18/05/2022.
//

#ifndef GRAPHS_FULL_VISITOR_H
#define GRAPHS_FULL_VISITOR_H

#include <deque>
#include <unordered_set>
#include <set>
#include "graph.h"

using std::string;

class visitor {
public:
    visitor(data::graph& graph);

    bool find_path(const string &start_vertex, const string &goal = "");

    bool cycle_found() const;
private:

    data::graph& m_graph;

    bool m_cycle_found{false};

    std::vector<string> m_path;

    std::unordered_map<string, int> m_visited;

    // TODO: add more member variables here
};

#endif //GRAPHS_FULL_VISITOR_H
