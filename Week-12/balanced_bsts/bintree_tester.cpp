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

void bintree_tester::test_balanced_insert() {
    bintree tree1;
    tree1.insert(31);
    assert(tree1 == bintree{"31"});

    tree1.insert(29);
    assert(tree1 == bintree{"(29 31 ())"});

    tree1.insert(11);
    assert(tree1 == bintree{"(11 29 31)"});

    tree1.insert(7);
    assert(tree1 == bintree{"((7 11 ()) 29 31)"});

    tree1.insert(13);
    assert(tree1 == bintree{"((7 11 13) 29 31)"});

    tree1.insert(17);
    assert(tree1 == bintree{"((7 11 ()) 13 (17 29 31))"});

    bintree tree2;
    tree2.insert(2);
    assert(tree2 == bintree{"2"});

    tree2.insert(3);
    assert(tree2 == bintree{"(() 2 3)"});

    tree2.insert(17);
    assert(tree2 == bintree{"(2 3 17)"});

    tree2.insert(19);
    assert(tree2 == bintree{"(2 3 (() 17 19))"});

    tree2.insert(13);
    assert(tree2 == bintree{"(2 3 (13 17 19))"});

    tree2.insert(11);
    assert(tree2 == bintree{"((2 3 11) 13 (() 17 19))"});

    std::cerr << "bintree_tester::test_balanced_insert() PASS" << std::endl;
}

void bintree_tester::test_balanced_remove() {
    bintree tree1{"((2 3 (5 7 11)) 13 (17 19 ()))"};
    bintree tree1111{"((2 3 5) 7 19)"};
    tree1.remove(13);
    assert(tree1 == bintree{"((2 3 5) 7 (11 17 19))"});

    tree1.remove(11);
    assert(tree1 == bintree {"((2 3 5) 7 (() 17 19))"});

    tree1.remove(17);
    assert(tree1 == tree1111);

    tree1.remove(19);
    assert(tree1 == bintree{"(2 3 (5 7 ()))"});

    tree1.remove(5);
    assert(tree1 == bintree{"(2 3 7)"});

    bintree tree2{"((() 7 11) 13 ((17 19 23) 29 31))"};
    tree2.remove(7);
    assert(tree2 == bintree{"((11 13 17) 19 (23 29 31))"});

    tree2.remove(17);
    assert(tree2 == bintree{"((11 13 ()) 19 (23 29 31))"});

    tree2.remove(13);
    assert(tree2 == bintree{"(11 19 (23 29 31))"});

    tree2.remove(11);
    assert(tree2 == bintree{"((() 19 23) 29 31)"});

    tree2.remove(31);
    assert(tree2 == bintree{"(19 23 29)"});

    std::cerr << "bintree_tester::test_balanced_remove() PASS" << std::endl;
}
