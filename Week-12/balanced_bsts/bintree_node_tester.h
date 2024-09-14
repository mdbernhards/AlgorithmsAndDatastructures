//
// Created by rgr24 on 07/05/2023.
//

#ifndef BSTS_BINTREE_NODE_TESTER_H
#define BSTS_BINTREE_NODE_TESTER_H


#include "bintree_node.h"

class bintree_node_tester {
public:
    static void test_update_height();
    static void test_balance_factor();
    static void test_rotate_left();
    static void test_rotate_right();
    static void test_rebalance();
    // tests whether the tree is a valid binary search tree, that is whether
    // the order invariant is maintained
    static bool valid_bst(const bintree_node* root);

    static bool heights_valid(const bintree_node* root);

    static bool balanced_bst(const bintree_node* root);
};


#endif //BSTS_BINTREE_NODE_TESTER_H
