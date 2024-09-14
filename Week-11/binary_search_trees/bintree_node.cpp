#include "bintree_node.h"
#include <vector>
#include <sstream>

bintree_node::bintree_node(int value) : m_value{value} {}

bintree_node::bintree_node(int value, bintree_node &left, bintree_node &right) : m_value(value), m_left(&left), m_right(&right) {}

int bintree_node::value() const {
    return m_value;
}

const bintree_node *bintree_node::left() const {
    return m_left;
}

const bintree_node *bintree_node::right() const {
    return m_right;
}

bool bintree_node::is_leaf() const {
    return m_left == nullptr && m_right == nullptr;
}

bool bintree_node::is_full() const {
    return m_left != nullptr && m_right != nullptr;
}

bool bintree_node::has_left_child() const {
    return m_left != nullptr;
}

bool bintree_node::has_right_child() const {
    return m_right != nullptr;
}

void bintree_node::replace_child(const bintree_node *old_child, bintree_node *new_child) {
    if (m_left == old_child) {
        m_left = new_child;
    } else if (m_right == old_child) {
        m_right = new_child;
    }
    else {
        throw std::invalid_argument("replace_child: old_child not found");
    }
}

bool bintree_node::is_child(const bintree_node *node) const {
    return m_left == node || m_right == node;
}

bool bintree_node::operator==(const bintree_node &node) const {
    if (m_value != node.m_value) return false;
    if ((m_left == nullptr) != (node.m_left == nullptr)) return false;
    if ((m_right == nullptr) != (node.m_right == nullptr)) return false;
    if (m_left != nullptr && *m_left != *node.m_left) return false;
    if (m_right != nullptr && *m_right != *node.m_right) return false;
    return true;
}

bool bintree_node::operator!=(const bintree_node &node) const {
    return !(*this == node);
}

