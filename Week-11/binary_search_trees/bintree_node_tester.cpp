#include <iostream>
#include <cassert>
#include "bintree_node_tester.h"

bool bintree_node_tester::valid_bst(const bintree_node* root) {
    if (root == nullptr) return true;
    if (root->left() != nullptr && root->left()->value() > root->value()) return false;
    if (root->right() != nullptr && root->right()->value() < root->value()) return false;
    return valid_bst(root->left()) && valid_bst(root->right());
}
