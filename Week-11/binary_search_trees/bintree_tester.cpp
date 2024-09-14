#include "bintree_tester.h"
#include "bintree_node_tester.h"
#include "bintree.h"
#include <iostream>
#include <cassert>

void bintree_tester::test_contains() {
    bintree tree{};

    // create nodes with values 17, 23, 25, 31, 42, 62, 65, 67, 71
    bintree_node n17{17}, n23{23}, n25{25}, n31{31}, n42{42}, n62{62}, n65{65}, n67{67}, n71{71};

    tree.m_sentinel.m_left = tree.m_root = &n42;
    n42.m_left = &n23;
    n42.m_right = &n67;
    n23.m_left = &n17;
    n23.m_right = &n31;
    n31.m_left = &n25;
    n67.m_left = &n62;
    n67.m_right = &n71;
    n62.m_right = &n65;

    assert(tree.contains(17) == true);
    assert(tree.contains(23) == true);
    assert(tree.contains(25) == true);
    assert(tree.contains(31) == true);
    assert(tree.contains(42) == true);
    assert(tree.contains(62) == true);
    assert(tree.contains(65) == true);
    assert(tree.contains(67) == true);
    assert(tree.contains(71) == true);

    assert(tree.contains(tree.m_sentinel.value()) == false);
    assert(tree.contains(-100) == false);
    assert(tree.contains(100) == false);

    // clear the tree to prevent dynamic release of nodes
    tree.m_sentinel.m_left = tree.m_root = nullptr;

    std::cerr << "bintree_tester::test_contains() PASS" << std::endl;
}

void bintree_tester::test_insert() {
    bintree tree{};
    bool inserted;
    inserted = tree.insert(30);
    assert(inserted);
    assert((tree.m_sentinel.left() == tree.root()) != (tree.m_sentinel.right() == tree.root()));
    assert(tree.m_count == 1);
    assert(tree == bintree{"30"});

    inserted = tree.insert(20);
    assert(inserted);
    assert(tree.m_count == 2);
    assert(tree == bintree{"(20 30 ())"});

    inserted = tree.insert(30);
    assert(!inserted);
    assert(tree.m_count == 2);
    assert(tree == bintree{"(20 30 ())"});

    inserted = tree.insert(50);
    assert(inserted);
    assert(tree.m_count == 3);
    assert(tree == bintree{"(20 30 50)"});

    inserted = tree.insert(70);
    assert(inserted);
    assert(tree.m_count == 4);
    assert(tree == bintree{"(20 30 (() 50 70))"});

    inserted = tree.insert(10);
    assert(inserted);
    assert(tree.m_count == 5);
    assert(tree == bintree{"((10 20 ()) 30 (() 50 70))"});

    inserted = tree.insert(40);
    assert(inserted);
    assert(tree.m_count == 6);
    assert(tree == bintree{"((10 20 ()) 30 (40 50 70))"});

    inserted = tree.insert(25);
    assert(inserted);
    assert(tree.m_count == 7);
    assert(tree == bintree{"((10 20 25) 30 (40 50 70))"});

    inserted = tree.insert(22);
    assert(inserted);
    assert(tree.m_count == 8);
    assert(tree == bintree{"((10 20 (22 25 ())) 30 (40 50 70))"});

    inserted = tree.insert(28);
    assert(inserted);
    assert(tree.m_count == 9);
    assert(tree == bintree{"((10 20 (22 25 28)) 30 (40 50 70))"});

    assert(tree.insert(10) == false);
    assert(tree.insert(20) == false);
    assert(tree.insert(22) == false);
    assert(tree.insert(25) == false);
    assert(tree.insert(28) == false);
    assert(tree.insert(30) == false);
    assert(tree.insert(40) == false);
    assert(tree.insert(50) == false);
    assert(tree.insert(70) == false);
    assert(tree.m_count == 9);

    std::cerr << "bintree_tester::test_insert() PASS" << std::endl;
}

void bintree_tester::test_remove_leaf() {
    bintree tree{};

    // create nodes with values from 1 to 7
    auto v1 = new bintree_node{1};
    auto v2 = new bintree_node{2};
    auto v3 = new bintree_node{3};
    auto v4 = new bintree_node{4};
    auto v5 = new bintree_node{5};
    auto v6 = new bintree_node{6};
    auto v7 = new bintree_node{7};

    // create a complete bst from the seven nodes
    v4->m_left = v2;
    v4->m_right = v6;
    v2->m_left = v1;
    v2->m_right = v3;
    v6->m_left = v5;
    v6->m_right = v7;

    // set the root of the tree
    tree.m_sentinel.m_left = tree.m_root = v4;

    // remove the leaf nodes one by one
    tree.remove_leaf(v1, v2);
    assert(tree.root() == v4);
    assert(v4->left() == v2);
    assert(v2->left() == nullptr);
    assert(v2->right() == v3);
    assert(v2->value() == 2);

    tree.remove_leaf(v3, v2);
    assert(tree.root() == v4);
    assert(v4->left() == v2);
    assert(v2->left() == nullptr);
    assert(v2->right() == nullptr);

    tree.remove_leaf(v2, v4);
    assert(tree.root() == v4);
    assert(v4->left() == nullptr);
    assert(v4->right() == v6);

    tree.remove_leaf(v7, v6);
    assert(tree.root() == v4);
    assert(v4->left() == nullptr);
    assert(v4->right() == v6);
    assert(v6->left() == v5);
    assert(v6->right() == nullptr);

    tree.remove_leaf(v5, v6);
    assert(tree.root() == v4);
    assert(v4->left() == nullptr);
    assert(v4->right() == v6);
    assert(v6->left() == nullptr);
    assert(v6->right() == nullptr);

    tree.remove_leaf(v6, v4);
    assert(tree.root() == v4);
    assert(v4->left() == nullptr);
    assert(v4->right() == nullptr);

    tree.remove_leaf(v4, &tree.m_sentinel);
    assert(tree.root() == nullptr);
    assert(tree.m_sentinel.is_leaf());

    std::cerr << "bintree_tester::test_remove_leaf() PASS" << std::endl;
}

void bintree_tester::test_remove_half_node() {
    bintree tree{};

    // create nodes with values 1, 2, 3, 4, 5
    auto v1 = new bintree_node{1}, v2 = new bintree_node{2},
         v3 = new bintree_node{3}, v4 = new bintree_node{4},
         v5 = new bintree_node{5};

    // setup tree with two branches of length 2
    tree.m_sentinel.m_left = tree.m_root = v3;
    v3->m_left = v2;
    v2->m_left = v1;
    v3->m_right = v4;
    v4->m_right = v5;

    tree.remove_half_node(v4, v3);
    assert(tree.root() == v3);
    assert(v3->m_left == v2);
    assert(v3->m_right == v5);

    tree.remove_half_node(v2, v3);
    assert(tree.root() == v3);
    assert(v3->m_left == v1);
    assert(v3->m_right == v5);

    v3->m_left = nullptr;
    delete v1;

    tree.remove_half_node(v3, &tree.m_sentinel);
    assert(tree.root() == v5);
    tree.m_sentinel.replace_child(v5, nullptr);
    tree.m_root = nullptr;

    delete v5;

    std::cerr << "bintree_tester::test_remove_half_node() PASS" << std::endl;
}

void bintree_tester::test_remove_full_node() {
    bintree tree{};

    // create nodes with values 17, 23, 25, 31, 42, 62, 65, 67, 71
    auto v17 = new bintree_node{17}, v23 = new bintree_node{23},
         v25 = new bintree_node{25}, v31 = new bintree_node{31},
         v42 = new bintree_node{42}, v62 = new bintree_node{62},
         v65 = new bintree_node{65}, v67 = new bintree_node{67},
         v71 = new bintree_node{71};

    // setup tree structure
    tree.m_sentinel.m_left = tree.m_root = v42;
    v42->m_left = v23; v42->m_right = v67;
    v23->m_left = v17; v23->m_right = v31;
    v31->m_left = v25;
    v67->m_left = v62; v67->m_right = v71;
    v62->m_right = v65;

    tree.remove_full_node(v42);
    assert(tree.root() == v42); // the node should not be deleted, only its value should change
    assert(tree.root()->value() == 31 || tree.root()->value() == 62);
    assert(tree.root()->is_full());
    assert(bintree_node_tester::valid_bst(tree.root()));

    tree.remove_full_node(v42);
    assert(tree.root() == v42); // the node should not be deleted, only its value should change
    assert(tree.root()->value() == 25 || tree.root()->value() == 65);
    assert(tree.root()->is_full());
    assert(bintree_node_tester::valid_bst(tree.root()));

    tree.remove_full_node(v42);
    assert(tree.root() == v42); // the node should not be deleted, only its value should change
    assert(tree.root()->value() == 23 || tree.root()->value() == 67);
    assert(tree.root()->is_full());
    assert(bintree_node_tester::valid_bst(tree.root()));

    tree.remove_full_node(v42);
    assert(tree.root() == v42); // the node should not be deleted, only its value should change
    assert(tree.root()->value() == 17 || tree.root()->value() == 71);
    assert(!tree.root()->is_full());
    assert(bintree_node_tester::valid_bst(tree.root()));

    if (tree.root()->value() == 17) {
        delete v71;
        delete v67;
        delete v65;
        delete v62;
    }
    else {
        delete v17;
        delete v23;
        delete v25;
        delete v31;
    }

    tree.m_sentinel.replace_child(v42, nullptr);
    tree.m_root = nullptr;
    delete v42;

    std::cerr << "bintree_tester::test_remove_full_node() PASS" << std::endl;
}

void bintree_tester::test_remove() {
    // test whether the right removal function is called
    bintree tree{};

    // create nodes with values 17, 23, 25, 31, 42, 62, 65, 67, 71
    auto v17 = new bintree_node{17}, v23 = new bintree_node{23},
            v25 = new bintree_node{25}, v31 = new bintree_node{31},
            v42 = new bintree_node{42}, v62 = new bintree_node{62},
            v65 = new bintree_node{65}, v67 = new bintree_node{67},
            v71 = new bintree_node{71};

    // setup tree structure
    tree.m_sentinel.m_left = tree.m_root = v42;
    v42->m_left = v23; v42->m_right = v67;
    v23->m_left = v17; v23->m_right = v31;
    v31->m_left = v25;
    v67->m_left = v62; v67->m_right = v71;
    v62->m_right = v65;
    tree.m_count = 9;

    assert(!tree.remove(0));
    assert(tree.m_count == 9);

    assert(tree.remove(23));
    assert(bintree_node_tester::valid_bst(tree.root()));
    assert(tree.m_count == 8);

    assert(tree.remove(62));
    assert(bintree_node_tester::valid_bst(tree.root()));
    assert(tree.m_count == 7);

    assert(tree.remove(25));
    assert(bintree_node_tester::valid_bst(tree.root()));
    assert(tree.m_count == 6);

    assert(tree.remove(42));
    assert(bintree_node_tester::valid_bst(tree.root()));
    assert(tree.m_count == 5);

    assert(tree.remove(17));
    assert(bintree_node_tester::valid_bst(tree.root()));
    assert(tree.m_count == 4);

    assert(tree.remove(31));
    assert(bintree_node_tester::valid_bst(tree.root()));
    assert(tree.m_count == 3);

    assert(tree.remove(65));
    assert(bintree_node_tester::valid_bst(tree.root()));
    assert(tree.m_count == 2);

    assert(tree.remove(67));
    assert(bintree_node_tester::valid_bst(tree.root()));
    assert(tree.m_count == 1);

    assert(tree.remove(71));
    assert(bintree_node_tester::valid_bst(tree.root()));
    assert(tree.m_count == 0);

    assert(tree.root() == nullptr);
    assert(tree.remove(0) == false);
    assert(tree.m_count == 0);

    assert(tree.m_sentinel.is_leaf());
    assert(tree.m_root == nullptr);

    std::cerr << "bintree_tester::test_remove() PASS" << std::endl;
}
