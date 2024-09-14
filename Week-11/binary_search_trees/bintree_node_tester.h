//
// Created by rgr24 on 07/05/2023.
//

#ifndef BSTS_BINTREE_NODE_TESTER_H
#define BSTS_BINTREE_NODE_TESTER_H


#include "bintree_node.h"

class bintree_node_tester {
public:
    // tests whether the tree is a valid binary search tree, that is whether
    // the order invariant is maintained
    static bool valid_bst(const bintree_node* root);
};


#endif //BSTS_BINTREE_NODE_TESTER_H
