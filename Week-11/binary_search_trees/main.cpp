
#include <fstream>
#include <iostream>
#include "bintree.h"
#include "bintree_writer.h"
#include "bintree_tester.h"
#include "bintree_node_tester.h"

void print_tree(const bintree_node* node) {
    if (node == nullptr) {
        return;
    }
    print_tree(node->left());
    std::cout << node->value() << std::endl;
}

int main() {
    // Activity 3
    bintree_tester::test_contains();

    // Activity 4
    bintree_tester::test_insert();

    // Activity 5
    bintree_tester::test_remove_leaf();
    bintree_tester::test_remove_half_node();

    // Activity 8
    bintree_tester::test_remove_full_node();
    bintree_tester::test_remove();


    // Activity 10
    bintree tree_one{};
    std::ifstream input{"numbers3.txt"};
    int number;
    while (input >> number) {
        tree_one.insert(number);
    }
    bintree_writer::write_dot("tree_three.dot", tree_one);

    return 0;
}
