#include <iostream>
#include <cassert>
#include "bintree_node_tester.h"

void bintree_node_tester::test_update_height() {
    bintree_node node1{1}, node2{2}, node3{3}, node4{4}, node5{5};
    node3.m_left = &node2;
    node2.m_left = &node1;
    node3.m_right = &node4;
    node4.m_right = &node5;

    node1.m_height = node5.m_height = -5;
    node2.m_height = node4.m_height = -10;
    node3.m_height = -1;

    node1.update_height();
    assert(node1.height() == 1);    // height of leaf node should be 1

    node5.update_height();
    assert(node5.height() == 1);    // height of leaf node should be 1

    node3.update_height();
    assert(node3.height() == -9);   // height of node3 should only depend on heights of its children
    assert(node2.height() == -10);  // height of node2 should not change
    assert(node4.height() == -10);  // height of node4 should not change

    node1.m_height = node5.m_height = 42;
    node2.update_height();
    assert(node2.height() == 43);    // height of node2 should be updated to 43

    node4.update_height();
    assert(node4.height() == 43);    // height of node6 should be updated to 43

    std::cerr << "bintree_node_tester::test_update_height() PASS" << std::endl;
}

void bintree_node_tester::test_balance_factor() {
    bintree_node node1{1}, node2{2}, node3{3}, node4{4}, node5{5};
    node3.m_left = &node2;
    node2.m_left = &node1;
    node3.m_right = &node4;
    node4.m_right = &node5;

    node1.m_height = node5.m_height = 5;
    assert(node1.balance_factor() == 0);
    assert(node5.balance_factor() == 0);
    assert(node2.balance_factor() == -5);
    assert(node4.balance_factor() == 5);

    node2.m_height = 3;
    node4.m_height = 2;
    assert(node3.balance_factor() == -1);

    node2.m_height = 2;
    node4.m_height = 3;
    assert(node3.balance_factor() == 1);

    std::cerr << "bintree_node_tester::test_balance_factor() PASS" << std::endl;
}

void bintree_node_tester::test_rotate_left() {
    // set up the tree
    bintree_node n2{2}, n4{4}, n5{5}, n6{6}, n7{7};
    n4.m_left = &n2;
    n4.m_right = &n6;
    n6.m_left = &n5;
    n6.m_right = &n7;

    n7.m_height = 0;
    n5.m_height = 2;
    n2.m_height = 1;
    n6.m_height = 3;
    n4.m_height = 4;

    auto root = n4.rotate_left();
    assert(root == &n6);
    assert(root->left() == &n4);
    assert(root->right() == &n7);
    assert(root->left()->left() == &n2);
    assert(root->left()->right() == &n5);
    assert(root->left()->left()->left() == nullptr);
    assert(root->left()->left()->right() == nullptr);

    assert(root->left()->height() == 3);
    assert(root->height() == 4);

    std::cerr << "bintree_node_tester::test_rotate_left() PASS" << std::endl;
}

void bintree_node_tester::test_rotate_right() {
    // set up the tree
    bintree_node n1{1}, n2{2}, n3{3}, n4{4}, n6{6};
    n4.m_left = &n2;
    n2.m_left = &n1;
    n2.m_right = &n3;
    n4.m_right = &n6;

    n1.m_height = 0;
    n2.m_height = 3;
    n3.m_height = 2;
    n4.m_height = 4;
    n6.m_height = 0;

    auto root = n4.rotate_right();
    assert(root == &n2);
    assert(root->left() == &n1);
    assert(root->right() == &n4);
    assert(root->right()->left() == &n3);
    assert(root->right()->right() == &n6);
    assert(root->right()->left()->left() == nullptr);
    assert(root->right()->left()->right() == nullptr);

    assert(root->right()->height() == 3);
    assert(root->height() == 4);

    std::cerr << "bintree_node_tester::test_rotate_right() PASS" << std::endl;
}

void bintree_node_tester::test_rebalance() {
    // Test with trees composed of seven nodes
    bintree_node n1{1}, n2{2}, n3{3}, n4{4}, n5{5}, n6{6}, n7{7};
    bintree_node *new_root;

    // Six cases: three left-heavy, three right-heavy
    // Case 1. left-heavy, left child -1
    n1.m_left = n1.m_right = n3.m_left = n3.m_right = n7.m_left = n7.m_right = n5.m_left = n5.m_right = nullptr;
    n4.m_left = &n2; n4.m_right = &n5;
    n2.m_left = &n1; n2.m_right = &n3;
    n6.m_left = &n4; n6.m_right = &n7;
    n1.m_height = n3.m_height = n5.m_height = n7.m_height = 1;
    n2.m_height = 2; n4.m_height = 3; n6.m_height = 4;

    new_root = n6.rebalance();
    assert(new_root == &n4);
    assert(new_root->left() == &n2);
    assert(new_root->right() == &n6);
    assert(new_root->left()->left() == &n1);
    assert(new_root->left()->right() == &n3);
    assert(new_root->right()->left() == &n5);
    assert(new_root->right()->right() == &n7);
    assert(n1.is_leaf());
    assert(n3.is_leaf());
    assert(n5.is_leaf());
    assert(n7.is_leaf());
    assert(heights_valid(new_root));

    // Case 2. left-heavy, left child 0
    n1.m_left = n1.m_right = n7.m_left = n7.m_right = n5.m_left = n5.m_right = nullptr;
    n4.m_left = nullptr; n4.m_right = &n5;
    n2.m_left = &n1; n2.m_right = nullptr;
    n3.m_left = &n2; n3.m_right = &n4;
    n6.m_left = &n3; n6.m_right = &n7;
    n1.m_height = n5.m_height = n7.m_height = 1;
    n2.m_height = n4.m_height = 2; n3.m_height = 3; n6.m_height = 4;

    new_root = n6.rebalance();
    assert(new_root == &n3);
    assert(new_root->left() == &n2);
    assert(new_root->right() == &n6);
    assert(new_root->left()->left() == &n1);
    assert(new_root->left()->right() == nullptr);
    assert(new_root->right()->left() == &n4);
    assert(new_root->right()->right() == &n7);
    assert(new_root->right()->left()->right() == &n5);
    assert(new_root->right()->left()->left() == nullptr);
    assert(n1.is_leaf());
    assert(n5.is_leaf());
    assert(n7.is_leaf());
    assert(heights_valid(new_root));

    // Case 3. left-heavy, left child +1
    n1.m_left = n1.m_right = n3.m_left = n3.m_right = n7.m_left = n7.m_right = n5.m_left = n5.m_right = nullptr;
    n2.m_left = &n1; n2.m_right = &n4;
    n4.m_left = &n3; n4.m_right = &n5;
    n6.m_left = &n2; n6.m_right = &n7;
    n1.m_height = n3.m_height = n5.m_height = n7.m_height = 1;
    n4.m_height = 2; n2.m_height = 3; n6.m_height = 4;

    new_root = n6.rebalance();
    assert(new_root == &n4);
    assert(new_root->left() == &n2);
    assert(new_root->right() == &n6);
    assert(new_root->left()->left() == &n1);
    assert(new_root->left()->right() == &n3);
    assert(new_root->right()->left() == &n5);
    assert(new_root->right()->right() == &n7);
    assert(n1.is_leaf());
    assert(n3.is_leaf());
    assert(n5.is_leaf());
    assert(n7.is_leaf());
    assert(heights_valid(new_root));

    // Case 4. right-heavy, right child +1
    n1.m_left = n1.m_right = n3.m_left = n3.m_right = nullptr;
    n5.m_left = n5.m_right = n7.m_left = n7.m_right = nullptr;
    n2.m_left = &n1; n2.m_right = &n4;
    n4.m_left = &n3; n4.m_right = &n6;
    n6.m_left = &n5; n6.m_right = &n7;
    n1.m_height = n3.m_height = n5.m_height = n7.m_height = 1;
    n6.m_height = 2; n4.m_height = 3; n2.m_height = 4;

    new_root = n2.rebalance();
    assert(new_root == &n4);
    assert(new_root->left() == &n2);
    assert(new_root->right() == &n6);
    assert(new_root->left()->left() == &n1);
    assert(new_root->left()->right() == &n3);
    assert(new_root->right()->left() == &n5);
    assert(new_root->right()->right() == &n7);
    assert(n1.is_leaf());
    assert(n3.is_leaf());
    assert(n5.is_leaf());
    assert(n7.is_leaf());
    assert(heights_valid(new_root));

    // Case 5. right-heavy, right child 0
    n1.m_left = n1.m_right = n3.m_left = n3.m_right = n7.m_left = n7.m_right = nullptr;
    n4.m_left = &n3; n4.m_right = nullptr;
    n2.m_left = &n1; n2.m_right = &n5;
    n6.m_left = nullptr; n6.m_right = &n7;
    n5.m_left = &n4; n5.m_right = &n6;
    n1.m_height = n3.m_height = n7.m_height = 1;
    n4.m_height = n6.m_height = 2; n5.m_height = 3; n2.m_height = 4;

    new_root = n2.rebalance();
    assert(new_root == &n5);
    assert(new_root->left() == &n2);
    assert(new_root->right() == &n6);
    assert(new_root->left()->left() == &n1);
    assert(new_root->left()->right() == &n4);
    assert(new_root->left()->right()->left() == &n3);
    assert(new_root->left()->right()->right() == nullptr);
    assert(new_root->right()->left() == nullptr);
    assert(new_root->right()->right() == &n7);
    assert(heights_valid(new_root));

    // Case 6. right-heavy, right child -1
    n1.m_left = n1.m_right = n3.m_left = n3.m_right = n7.m_left = n7.m_right = n5.m_left = n5.m_right = nullptr;
    n4.m_left = &n3; n4.m_right = &n5;
    n6.m_left = &n4; n6.m_right = &n7;
    n2.m_left = &n1; n2.m_right = &n6;
    n1.m_height = n3.m_height = n5.m_height = n7.m_height = 1;
    n4.m_height = 2; n6.m_height = 3; n2.m_height = 4;

    new_root = n2.rebalance();
    assert(new_root == &n4);
    assert(new_root->left() == &n2);
    assert(new_root->right() == &n6);
    assert(new_root->left()->left() == &n1);
    assert(new_root->left()->right() == &n3);
    assert(new_root->right()->left() == &n5);
    assert(new_root->right()->right() == &n7);
    assert(n1.is_leaf());
    assert(n3.is_leaf());
    assert(n5.is_leaf());
    assert(n7.is_leaf());
    assert(heights_valid(new_root));

    std::cerr << "bintree_node_tester::test_rebalance() PASS" << std::endl;
}

bool bintree_node_tester::valid_bst(const bintree_node* root) {
    if (root == nullptr) return true;
    if (root->left() != nullptr && root->left()->value() > root->value()) return false;
    if (root->right() != nullptr && root->right()->value() < root->value()) return false;
    return valid_bst(root->left()) && valid_bst(root->right());
}

bool bintree_node_tester::heights_valid(const bintree_node *root) {
    if (root == nullptr) return true;
    if (!heights_valid(root->left())) return false;
    if (!heights_valid(root->right())) return false;
    if (root->is_leaf()) return root->height() == 1;
    if (root->is_full()) return root->height() == 1 + std::max(root->left()->height(), root->right()->height());
    if (root->left() != nullptr) return root->height() == 1 + root->left()->height();
    return root->height() == 1 + root->right()->height();
}

bool bintree_node_tester::balanced_bst(const bintree_node *root) {
    if (root == nullptr) return true;
    if (!balanced_bst(root->left())) return false;
    if (!balanced_bst(root->right())) return false;
    if (root->is_leaf()) return true;
    if (root->is_full()) return std::abs(root->left()->height() - root->right()->height()) <= 1;
    if (root->left() != nullptr) return root->left()->height() <= 1;
    return root->right()->height() <= 1;
}
