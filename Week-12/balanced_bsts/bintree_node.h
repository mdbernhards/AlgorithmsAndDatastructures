#ifndef BSTS_BINTREE_NODE_H
#define BSTS_BINTREE_NODE_H

#include <ostream>
#include <vector>
#include <istream>

class bintree;
class bintree_tester;
class bintree_node_tester;

class bintree_node {
    friend class bintree;
    friend class bintree_tester;
    friend class bintree_node_tester;
public:
    bintree_node(int value);
    bintree_node(int value, bintree_node* left, bintree_node* right);

    int value() const;
    bintree_node*& left();
    const bintree_node* left() const;

    bintree_node*& right();
    const bintree_node* right() const;

    // Returns true if the node is a leaf (i.e. it has no child nodes), false otherwise
    bool is_leaf() const;

    // Returns true if the node has two child nodes, false otherwise
    bool is_full() const;

    bool has_left_child() const;
    bool has_right_child() const;

    // Returns true if the node is a child of this node, false otherwise
    bool is_child(const bintree_node* node) const;

    // Replaces the old_child with the new_child. The old_child must be a child of this node.
    void replace_child(const bintree_node* old_child, bintree_node* new_child);

    // Returns the height of the subtree rooted at this node. The height of a leaf node is 0.
    int height() const;

    // Returns the balance factor of the subtree rooted at this node. The balance factor of a leaf node is 0.
    // A positive balance factor means that the right subtree is higher than the left subtree, a negative
    // balance factor means that the left subtree is higher than the right subtree.
    int balance_factor() const;

    // Rotates the subtree rooted at this node to the left, i.e. makes the right child the new root
    bintree_node *rotate_left();

    // Rotates the subtree rooted at this node to the right, i.e. makes the left child the new root
    bintree_node *rotate_right();

    // Rebalances the subtree rooted at this node, so that the balance factor is between -1 and 1. Returns the new root of the subtree.
    bintree_node *rebalance();

    bool operator==(const bintree_node& node) const;
    bool operator!=(const bintree_node& node) const;
private:
    // copy ctor and copy assignment operator deleted
    bintree_node(const bintree_node& node) = delete;
    bintree_node& operator=(const bintree_node& node) = delete;

    // Updates the height of this node based on the heights of its children
    void update_height();

    int m_value;
    int m_height{1};

    bintree_node* m_left{};
    bintree_node* m_right{};
};


#endif //BSTS_BINTREE_NODE_H
