#include <fstream>
#include <iostream>
#include "bintree.h"
#include "bintree_writer.h"
#include "bintree_tester.h"
#include "bintree_node_tester.h"

void print_tree(const bintree_node* node) 
{
    if (node == nullptr) 
    {
        std::cout << "-";
        return;
    }
    std::cout << node->value();
    print_tree(node->left());
    std::cout << node->value();
}

void printCnodeBalances(bintree_node* nodeC, bintree_node* root, int treeCount) 
{
    std::cout << "Tree " << treeCount << " C node Balance:" << std::endl;
    std::cout << "Before rotation: "  << nodeC->balance_factor() << std::endl;

    root->replace_child(root->right(), root->right()->rotate_right());

    std::cout << "After right rotation of right subtree: "  << nodeC->balance_factor() << std::endl;

    root = root->rotate_left();

    std::cout << "After left rotation of full: "  << nodeC->balance_factor() << std::endl;
}

int main() {
    // TODO: the bintree::destruct_subtree is not completed. Copy the (recursive) implementation you wrote
    //   in the previous week into the function definition in bintree.cpp

    // Activity 1
    bintree_node_tester::test_update_height();

    // Activity 3
    bintree_node_tester::test_balance_factor();

    // Activity 4
    bintree_node_tester::test_rotate_left();
    bintree_node_tester::test_rotate_right();

    // Activity 7
    bintree_node_tester::test_rebalance();

    // Activity 9
    bintree_tester::test_balanced_insert();
    bintree_tester::test_balanced_remove();


    // Activity 10
    // TODO: create a tree from the numbers 1..32 by inserting the numbers from low to high, then print the tree.
    //  Next, remove half of the values from the tree, and print the tree again.
    bintree tree{};

    for (int i = 1; i <= 32; ++i) 
    {
        tree.insert(i);
    }

    bintree_writer::write_dot("treeBefore.dot", tree);

    for (int i = 1; i <= 16; ++i) 
    {
        tree.remove(i);
    }

    bintree_writer::write_dot("treeAfter.dot", tree);
    
    /*

    
    bintree_node 
        nA{1},  
        nB{2, &nA, nullptr}, 
        nC{3, &nB, nullptr}, 
        nD{42}, 
        nE{4, &nC, &nD};

    print_tree(&nE);

    // Balance factor B =  2
    // Balance factor D = -1

    //Tree one
    // Balance factor C = -1
    bintree_node 
        n1F{'f'}, 
        n1C{'c', &n1F, nullptr}, 
        n1E{'e'}, 
        n1D{'d', &n1C, &n1E}, 
        n1A{'a'}, 
        n1B{'b', &n1A, &n1D};

    printCnodeBalances(&n1C, &n1B, 1);

    //Tree Two
    // Balance factor C = 0
    bintree_node 
        n2F{'f'},
        n2G{'g'},  
        n2C{'c', &n2F, &n2G}, 
        n2E{'e'}, 
        n2D{'d', &n2C, &n2E}, 
        n2A{'a'}, 
        n2B{'b', &n2A, &n2D};

    printCnodeBalances(&n2C, &n2B, 2);

    //Tree Three
    // Balance factor C = 1
    bintree_node 
        n3G{'g'},  
        n3C{'c', nullptr, &n3G}, 
        n3E{'e'}, 
        n3D{'d', &n3C, &n3E}, 
        n3A{'a'}, 
        n3B{'b', &n3A, &n3D};

    printCnodeBalances(&n3C, &n3B, 3);
    */
    return 0;
}
