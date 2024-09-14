#include "bintree.h"
#include "bintree_writer.h"
#include <sstream>
#include <iomanip>

bintree::bintree(const std::string &textual_rep) {
    std::istringstream iss{textual_rep};
    m_sentinel.m_left = m_root = parse_subtree(iss, m_count);
    if (iss.fail()) throw std::invalid_argument("parse error");
    if (char c; iss >> c) throw std::invalid_argument("parse error - unexpected character: " + std::to_string(c));
}

bintree::bintree(bintree_node& node) : m_root{&node} {
    m_sentinel.m_left = m_root;
}

size_t bintree::count() const {
    return m_count;
}

const bintree_node *bintree::root() const {
    return m_root;
}

bool bintree::contains(int value) const {
    if (m_root == nullptr) return false;
    else return contains(m_root, value);
}

bool bintree::insert(int value) {
    if (m_root == nullptr) {
        m_sentinel.m_left = m_root = new bintree_node{value};
        m_count = 1;
        return true;
    }
    else {
        auto count = m_count;
        m_sentinel.m_left = m_root = balanced_insert(m_root, value);
        return m_count > count;
    }
}

bool bintree::remove(int value) {
    if (m_root == nullptr) return false;
    else {
        auto count = m_count;
        m_sentinel.m_left = m_root = balanced_remove(m_root, value);
        return m_count < count;
    }
}

bintree::~bintree() {
    destruct_subtree(m_root);
}

void bintree::destruct_subtree(bintree_node *root) 
{
    if (root == nullptr)
    {
        return;
    }

    if (root->has_left_child())
    {
        destruct_subtree(root->m_left);
    }
    
    if (root->has_right_child())
    {
        destruct_subtree(root->m_right);
    }
    
    delete root;
}

bool bintree::contains(const bintree_node *root, int value) const {
    if (root->m_value == value) return true;
    else if (value < root->m_value && root->has_left_child()) return contains(root->m_left, value);
    else if (value > root->m_value && root->has_right_child()) return contains(root->m_right, value);
    else return false;
}

bintree_node *bintree::balanced_insert(bintree_node *root, int value) 
{
    if (root == nullptr) 
    {
        m_count++;
        return new bintree_node{value};
    }

    if (root->m_value > value)
    {
        root->m_left = balanced_insert(root->m_left, value);
    }
    else if (root->m_value < value)
    {
        root->m_right = balanced_insert(root->m_right, value);
    }

    return root->rebalance();
}

bintree_node *bintree::balanced_remove_minimum(bintree_node *root, int &minimum) {
    if (root->m_left == nullptr) {
        // No smaller element exists, so we remove this node
        minimum = root->m_value;        // store the minimum value found
        auto new_root = root->m_right;  // the new root of the subtree is the right child of the node we are removing
        delete root;
        m_count--;
        if (new_root != nullptr) return new_root->rebalance();
        else return new_root;
    } else {
        // recursively remove the minimum from the left subtree
        root->m_left = balanced_remove_minimum(root->m_left, minimum);

        // rebalance this node, bottom-up
        // this may change the structure of the subtree rooted in this node,
        // so return its new root node
        return root->rebalance();
    }
}

bintree_node *bintree::balanced_remove(bintree_node *root, int value) 
{
    if (value == root->m_value) 
    {
        if (root->is_full()) 
        {
            int min;
            root->m_right = balanced_remove_minimum(root->m_right, min);
            root->m_value = min;
        }
        else
        {
            m_count--;

            if (root->has_left_child())
            {
                auto temp = root->m_left;
                delete root;
                root = temp;
            }
            else if (root->has_right_child())
            {
                auto temp = root->m_right;
                delete root;
                root = temp;
            }
            else   
            {
                delete root;
                return nullptr;
            }
        }
    }
    else if (value < root->m_value && root->has_left_child()) 
    {
        root->m_left = balanced_remove(root->m_left, value);
    }
    else if (value > root->m_value && root->has_right_child()) 
    {
        root->m_right = balanced_remove(root->m_right, value);
    }

    return root->rebalance();
}

bintree &bintree::operator<<(int value) {
    insert(value);
    return *this;
}

bintree_node *bintree::parse_subtree(std::istream &is, size_t &count) {
    char lbracket, rbracket;
    int value;
    if (is >> value) {
        // parse leaf node (only value)
        count++;
        return new bintree_node{value};
    }
    is.clear();
    if (!(is >> lbracket) || lbracket != '(') {
        is.setstate(std::ios::failbit);
        return nullptr;
    }
    if (is >> std::ws && is.peek() == ')') {
        // empty subtree
        is.get();
        return nullptr;
    }
    bintree_node * result = nullptr;
    bintree_node * left = parse_subtree(is, count);
    if (is >> value) {
        count++;
        result = new bintree_node{value};
        result->m_left = left;
        result->m_right = parse_subtree(is, count);
        result->update_height();
    }
    else is.clear();
    if (!(is >> rbracket) || rbracket != ')') {
        is.setstate(std::ios::failbit);
        destruct_subtree(result);
        result = nullptr;
    }
    return result;
}

bool bintree::operator==(const bintree &other) const {
    if (m_count != other.m_count) return false;
    if (m_root == nullptr && other.m_root == nullptr) return true;
    if (m_root == nullptr || other.m_root == nullptr) return false;
    return *m_root == *other.m_root;
}

std::ostream &operator<<(std::ostream &os, const bintree &tree) {
    bintree_writer::write_dot(os, tree);
    return os;
}

