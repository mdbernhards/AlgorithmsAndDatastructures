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
    bintree_node(int value, bintree_node& left, bintree_node& right);

    int value() const;
    const bintree_node* left() const;
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

    bool operator==(const bintree_node& node) const;
    bool operator!=(const bintree_node& node) const;
private:
    // copy ctor and copy assignment operator deleted
    bintree_node(const bintree_node& node) = delete;
    bintree_node& operator=(const bintree_node& node) = delete;

    int m_value;

    bintree_node* m_left{};
    bintree_node* m_right{};
};


#endif //BSTS_BINTREE_NODE_H
