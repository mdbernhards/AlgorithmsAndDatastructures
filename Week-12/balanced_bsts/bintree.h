#ifndef BSTS_BINTREE_H
#define BSTS_BINTREE_H

#include "bintree_node.h"
#include <ostream>
#include <set>

class bintree {
    friend class bintree_tester;
public:
    // default constructor - creates an empty tree
    bintree() = default;

    bintree(const std::string& textual_rep);
    bintree(bintree_node& node);

    // destructor - releases memory of all the nodes in the tree
    ~bintree();

    // copy constructor - makes a deep copy of the tree
    bintree(const bintree&) = delete;

    // copy assignment operator
    bintree& operator=(const bintree&) = delete;

    size_t count() const;

    // returns the root of the tree
    const bintree_node* root() const;

    // Returns true if the value is contained in the tree, false otherwise
    bool contains(int value) const;

    // If the tree does not yet contain the value, then insert the value into the tree & return true.
    // Returns false if the tree already contains the value
    bool insert(int value);

    // Convenience operator for inserting a value into the tree
    bintree& operator<<(int value);

    // Removes the value from the tree. Returns true if the value was indeed present and is now removed, false
    // otherwise
    bool remove(int value);

    bool operator==(const bintree& other) const;
private:
    void destruct_subtree(bintree_node* root);

    bool contains(const bintree_node *root, int value) const;

    // Inserts a new node with the given value into the subtree rooted at root, and returns
    // the new root of the (potentially rebalanced) subtree
    bintree_node *balanced_insert(bintree_node *root, int value);

    // Removes the node with the minimum value from the subtree rooted at root, and returns
    // the new root of the (potentially rebalanced) subtree.
    // Writes the minimum value found into the integer referred to by minimum
    bintree_node *balanced_remove_minimum(bintree_node *root, int& minimum);

    // Removes the node with the given value from the subtree rooted at root, and returns
    // the new root of the (potentially rebalanced) subtree
    bintree_node *balanced_remove(bintree_node *root, int value);

    bintree_node *parse_subtree(std::istream& is, size_t &count);

    // The number of elements in the tree
    size_t m_count{};

    // The true root of the tree
    bintree_node* m_root{nullptr};

    // A sentinel node that is the parent of the root node
    // The sentinel node is not "part" of the tree, but it makes the implementation of the tree easier
    // In particular, it simplifies the implementation of removal of nodes
    bintree_node m_sentinel{0xbadbad};
};

// stream output operator
std::ostream& operator<<(std::ostream& os, const bintree& tree);

#endif //BSTS_BINTREE_H
