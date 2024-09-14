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

size_t bintree::count() const {
    return m_count;
}

const bintree_node *bintree::root() const {
    return m_root;
}

bool bintree::contains(int value) const 
{
    if (!m_root) return false;
    const bintree_node *node = m_root;

    while (true)
    {
        if (node->m_value == value)
        {
            return true;
        }
        else if (node->m_value > value)
        {
            if (node->has_left_child())
            {
                node = node->m_left;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (node->has_right_child())
            {
                node = node->m_right;
            }
            else
            {
                return false;
            }
        }
    }
}

bool bintree::insert(int value) 
{
    if (m_root == nullptr) 
    {
        m_sentinel.m_left = m_root = new bintree_node{value};
        m_count = 1;

        return true;
    } 
    else 
    {
        bintree_node *node = m_root;
        while (true)
        {
            if (node->m_value == value)
            {
                return false;
            }
            else if (node->m_value > value)
            {
                if (node->has_left_child())
                {
                    node = node->m_left;
                }
                else
                {
                    node->m_left = new bintree_node{value};
                    m_count++;
                    return true;
                }
            }
            else
            {
                if (node->has_right_child())
                {
                    node = node->m_right;
                }
                else
                {
                    node->m_right = new bintree_node{value};
                    m_count++;
                    return true;
                }
            }
        }
    }
}

bool bintree::remove(int value) 
{
    bintree_node * parent = &m_sentinel;
    auto node = m_root;

    if (contains(value))
    {
        while (true)
        {
            if (node->m_value == value)
            {
                if (node->is_full())
                {
                    remove_full_node(node);
                }
                else if (node->is_leaf())
                {
                    remove_leaf(node, parent);
                }
                else 
                {
                    remove_half_node(node, parent);
                }

                m_count--;
                return true;
            }
            else if (node->m_value > value)
            {
                parent = node;
                node = node->m_left;
            }
            else
            {
                parent = node;
                node = node->m_right;
            }
        }
    }

    return false;
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

void bintree::remove_leaf(bintree_node *node, bintree_node *parent) {
    if (!parent->is_child(node)) throw std::invalid_argument("parent is not the parent of the node");

    if (node == m_root) 
    {
        m_root = nullptr;
        m_sentinel.m_left = nullptr;
    } 
    else if (parent->m_left == node)
    {   
        parent->m_left = nullptr;
    }
    else
    {
        parent->m_right = nullptr;
    }

    delete node;
}

void bintree::remove_half_node(bintree_node *node, bintree_node *parent) {
    if (!parent->is_child(node)) throw std::invalid_argument("parent is not the parent of the node");

    bintree_node *tempNode = node->has_right_child() ? node->m_right : node->m_left;

    if (node == m_root) 
    {
        m_root = tempNode;
        m_sentinel.m_left = m_root;
    }
    else
    {
        parent->replace_child(node, tempNode);
    }

    delete node;
}

void bintree::remove_full_node(bintree_node *node) 
{
    bintree_node *replacementNode = node->m_left;
    bintree_node *parentNode = node;

    while (replacementNode->has_right_child())
    {
        parentNode = replacementNode;
        replacementNode = replacementNode->m_right;
    }

    node->m_value = replacementNode->m_value;
    
    remove_half_node(replacementNode, parentNode);
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

