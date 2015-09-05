#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>

namespace ehtesh {
    enum DIRECTION { LEFT, RIGHT, NONE };

    template <typename T>
    struct Node {
        // TODO see if I can bring const back
        T m_data;
        Node<T>* m_parent = nullptr;
        Node<T>* m_left = nullptr;
        Node<T>* m_right = nullptr;
        Node(const T& data): m_data(data) {}
        ~Node() {}

    };

    template <typename T>
    struct Tree {
        Node<T>* m_root;
        int m_size;

        Tree() {
            m_root = nullptr;
            m_size = 0;
        }

        ~Tree() {
            if (m_root)
                tree_destructor_helper(m_root);
        }

        void tree_destructor_helper(Node<T>* parent){
            if (parent->m_left)
                tree_destructor_helper(parent->m_left);
            if (parent->m_right)
                tree_destructor_helper(parent->m_right);
            delete parent;
        }

        void insert(const T& data){
            auto* node = new Node<T>(data);
            if (m_root == nullptr)
                m_root = node;
            else
                insert_helper(m_root, node);
            m_size++;
        }

        void insert_helper(Node<T>* parent, Node<T>* node){
            if (node->m_data < parent->m_data){
                if (parent->m_left){
                    insert_helper(parent->m_left, node);
                }
                else {
                    parent->m_left = node;
                    node->m_parent = parent;
                }
            }
            else {
                if (parent->m_right){
                    insert_helper(parent->m_right, node);
                }
                else {
                    parent->m_right = node;
                    node->m_parent = parent;
                }
            }
        }

        bool erase(const T& data){
            if (erase_helper(NONE, m_root, data)){
                m_size--;
                return true;
            }
            else 
                return false;
        }

        // https://en.wikipedia.org/wiki/Binary_search_tree#Deletion
        // TODO verify
        bool erase_helper(DIRECTION d, Node<T>* current, const T& data){
            if (current->m_data < data){
                if (!current->m_left)
                    return false;
                else
                    return erase_helper(LEFT, current->m_left, data);
            }
            else if (current->m_data > data){
                if (!current->m_right)
                    return false;
                else
                    return erase_helper(RIGHT, current->m_right, data);
            }
            else {
                // How to make this code less verbose?
                if (!current->m_left && !current->m_right){
                    if (d == LEFT)
                        current->m_parent->m_left = nullptr;
                    else if (d == RIGHT)
                        current->m_parent->m_right = nullptr;
                }
                else if (!current->m_left){
                    if (d == LEFT){
                        current->m_parent->m_left = current->m_right;
                        current->m_right->m_parent = current->m_parent;
                    }
                    else if (d == RIGHT){
                        current->m_parent->m_right = current->m_right;
                        current->m_right->m_parent = current->m_parent;
                    }
                }
                else if (!current->m_right){
                    if (d == LEFT){
                        current->m_parent->m_left = current->m_right;
                        current->m_right->m_parent = current->m_parent;
                    }
                    else if (d == RIGHT){
                        current->m_parent->m_right = current->m_right;
                        current->m_right->m_parent = current->m_parent;
                    }
                }
                else {
                    // grab the leftmost child to the right of the current
                    // node, swap nodes, and then delete the current node
                    auto* leftmost = current->m_right;
                    while (leftmost->m_left)
                        leftmost = leftmost->m_left;
                    current->m_data = leftmost->m_data;
                    erase(leftmost->m_data);
                }

                delete current;
                return true;
            }
        }

        // TODO styling of this iterator is different than in elist. Synchronize the two.
        struct iterator;
        typedef iterator self_type;
        typedef T value_type;
        typedef size_t size_type;
        typedef Node<T>* pointer;
        typedef Node<T>& reference;

        struct iterator {
            Node<T>* m_ptr;
            iterator(pointer ptr): m_ptr(ptr) {}

            // http://stackoverflow.com/a/12851421/198348
            self_type increment() {
                if (m_ptr->m_right) {
                    m_ptr = m_ptr->m_right;
                    while (m_ptr->m_left)
                        m_ptr = m_ptr->m_left;
                    return *this;
                }
                else {
                    while (true){
                        if (!m_ptr->m_parent){
                            m_ptr = nullptr;
                            return *this;
                        }
                        if (m_ptr->m_parent->m_left == m_ptr){
                            m_ptr = m_ptr->m_parent;
                            return *this;
                        }
                        m_ptr = m_ptr->m_parent;
                    }
                }
            }

            // prefix
            self_type operator++() { 
                return increment();
            } 
            // postfix
            self_type operator++(int what) {
                //increment();
                //return *this;
                return increment();
            }
            // prefix
            self_type operator--() { m_ptr--; return *this; } 
            // postfix
            self_type operator--(int what) {
                self_type current_ptr = *this;
                m_ptr--;
                return current_ptr;
            }

            reference operator*() { return *m_ptr; }
            pointer operator->() { return m_ptr; }
            bool operator==(const self_type& rhs) { return m_ptr == rhs.m_ptr; }
            bool operator!=(const self_type& rhs) { return m_ptr != rhs.m_ptr; }
        };

        iterator begin(){
            auto* leftmost = m_root;
            std::cout << "iterator::begin()" << *leftmost << std::endl;
            while (leftmost && leftmost->m_left){
                leftmost = leftmost->m_left;
                std::cout << "iterator::begin()" << *leftmost << std::endl;
            }
            return iterator(leftmost);
        }

        iterator end(){
            auto* rightmost = m_root;
            while (rightmost && rightmost->m_right)
                rightmost = rightmost->m_right;
            return iterator(rightmost);
        }

    };

    // http://stackoverflow.com/a/8948691/198348
    template <typename T>
    void ostream_helper(std::ostream &strm, const Node<T>* n, std::string prefix, bool is_tail){
        
        strm << prefix + (is_tail ? "└── " : "├── ")  << n->m_data << std::endl;

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

    template <typename T>
    std::ostream& operator<<(std::ostream &strm, const Node<T>& t){
        return strm << "Node(" + t.m_data + ")";
    }

    template <typename T>
    std::ostream& operator<<(std::ostream &strm, const Tree<T>& t){
        if (t.m_root) {
            ostream_helper(strm, t.m_root, "", true);
        }
        return strm;
    }

}
