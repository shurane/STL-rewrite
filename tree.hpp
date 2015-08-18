#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>

// plain 'ol binary search tree
namespace ehtesh {
    struct node {
        int m_data;
        node* m_parent;
        node* m_left;
        node* m_right;
        // TODO is there a way to use `const int&` here?
        node(const int data): m_data(data) {
            m_parent = nullptr;
            m_left = nullptr;
            m_right = nullptr;
        }
        ~node() {
        }
        node* leftmost() {
            if (this->m_left)
                return this->m_left->leftmost();
            else
                return nullptr;
            
        }
    };

    struct tree {
        node* m_root;
        int m_size;

        tree() {
            m_root = nullptr;
            m_size = 0;
        }
        void tree_destructor_helper(node* start){
            if (start->m_left){
                tree_destructor_helper(start->m_left);
            }
            if (start->m_right){
                tree_destructor_helper(start->m_right);
            }
            delete start;
        }
        ~tree() {
            if (m_root){
                tree_destructor_helper(m_root);
            }
        }

        void insert_helper(node* start, node* n){
            if (n->m_data < start->m_data){
                if (start->m_left){
                    insert_helper(start->m_left, n);
                }
                else {
                    start->m_left = n;
                    n->m_parent = start->m_left;
                }
            }
            else {
                if (start->m_right){
                    insert_helper(start->m_right, n);
                }
                else {
                    start->m_right = n;
                    n->m_parent = start->m_right;
                }
            }
        }

        void insert(const int& data){
            node* n = new node(data);
            if (m_root == nullptr){
                m_root = n;
            }
            else {
                insert_helper(m_root, n);
            }
            m_size++;
        }

        void remove_node(node* start){
            if (!start->m_left && !start->m_right){
                delete start;
            }
            if (!start->m_left){
                // TODO
            }
        }
    };

    // http://stackoverflow.com/a/8948691/198348
    void ostream_helper(std::ostream &strm, const node* n, std::string prefix, bool is_tail){
        strm << prefix + (is_tail ? "└── " : "├── ") << n->m_data << std::endl;

        if (n->m_left && !n->m_right){
            ostream_helper(strm, n->m_left, prefix + (is_tail ? "    " : "│   "), true);
        }
        else if (n->m_left && n->m_right){
            ostream_helper(strm, n->m_left, prefix + (is_tail ? "    " : "│   "), false);
            ostream_helper(strm, n->m_right, prefix + (is_tail ? "    " : "│   "), true);
        }
        else if (!n->m_left && n->m_right){
            ostream_helper(strm, n->m_right, prefix + (is_tail ? "    " : "│   "), true);
        }
    }

    // TODO how to print out the shape of the tree?
    std::ostream& operator<<(std::ostream &strm, const tree& t){
        if (t.m_root) {
            ostream_helper(strm, t.m_root, std::string(), true);
        }
        return strm;
    }

}
