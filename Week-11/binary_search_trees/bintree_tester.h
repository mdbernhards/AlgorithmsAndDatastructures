#ifndef BSTS_BINTREE_TESTER_H
#define BSTS_BINTREE_TESTER_H

#include "bintree_node.h"

class bintree_tester {
public:
    static void test_contains();
    static void test_insert();

    static void test_remove_leaf();
    static void test_remove_half_node();
    static void test_remove_full_node();
    static void test_remove();


};


#endif //BSTS_BINTREE_TESTER_H
