#include "bintree_node.h"
#include <vector>
#include <sstream>

bintree_node::bintree_node(int value) : m_value{value} {}

bintree_node::bintree_node(int value, bintree_node *left, bintree_node *right)
: m_value(value), m_left(left), m_right(right) {
    update_height();
}

int bintree_node::value() const {
    return m_value;
}

bintree_node *&bintree_node::left() {
    return m_left;
}

const bintree_node *bintree_node::left() const {
    return m_left;
}

bintree_node *&bintree_node::right() {
    return m_right;
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
    if (m_height != node.m_height) return false;
    if ((m_left == nullptr) != (node.m_left == nullptr)) return false;
    if ((m_right == nullptr) != (node.m_right == nullptr)) return false;
    if (m_left != nullptr && *m_left != *node.m_left) return false;
    if (m_right != nullptr && *m_right != *node.m_right) return false;
    return true;
}

bool bintree_node::operator!=(const bintree_node &node) const {
    return !(*this == node);
}

int bintree_node::height() const {
    return m_height;
}

int bintree_node::balance_factor() const 
{
    auto right = 0;
    auto left = 0;

    if (has_left_child())
    {
        left = m_left->m_height;
    }

    if (has_right_child())
    {
        right = m_right->m_height;
    }

    return right - left;
}

void bintree_node::update_height() 
{
    int height = 1;

    if (has_left_child())
    {
        height = m_left->m_height + 1;
    }

    if (has_right_child() && height <= m_right->m_height)
    {
        height = m_right->m_height + 1;
    }
    
    m_height = height;
}

bintree_node *bintree_node::rotate_left() 
{
    if (m_right == nullptr) throw std::invalid_argument("rotate_left: right child is null");
    
    auto newRoot = m_right;
    auto leftChild = m_right->m_left;
    
    newRoot->m_left = this;
    newRoot->m_left->m_right = leftChild;

    update_height();
    newRoot->update_height();

    return newRoot;
}

bintree_node *bintree_node::rotate_right() 
{
    if (m_left == nullptr) throw std::invalid_argument("rotate_right: left child is null");
    
    auto newRoot = m_left;
    auto rightChild = m_left->m_right;
    
    newRoot->m_right = this;
    newRoot->m_right->m_left = rightChild;

    update_height();
    newRoot->update_height();

    return newRoot;
}

bintree_node *bintree_node::rebalance() 
{   
    bintree_node* temp = this;
    
    if (balance_factor() > 1)
    {
        if (right()->balance_factor() < 0)
        {
            replace_child(right(), right()->rotate_right());
        }
        
        temp = rotate_left();
    }
    else if (balance_factor() < -1)
    {
        if (left()->balance_factor() > 0)
        {
            replace_child(left(), left()->rotate_left());
        }

        temp = rotate_right();
    }
    
    update_height();
    return temp;
}

