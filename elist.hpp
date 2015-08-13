#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stddef.h>

namespace ehtesh {
    struct node {
        int m_data;
        node* m_next;
        node* m_prev;
        // TODO is there a way to use `const int&` here?
        node(const int data): m_data(data) {
            m_next = nullptr;
            m_prev = nullptr;
        }
        ~node() {
            //delete m_data;
        }
    };

    std::ostream& operator<<(std::ostream &strm, const node& n){
        return strm << "Node("
            << "m_data=" << n.m_data
            << ",m_prev=" << n.m_prev
            << ",m_next=" << n.m_next
            << ")";
    }

    struct list {
        size_t m_size;
        node* m_head;
        node* m_tail;
        list() {
            m_size = 0;
            m_head = nullptr;
            m_tail = nullptr;
        }
        ~list() {
            node* current = m_head;
            while (current) {
                //std::cout << "~list(): " << *current << std::endl;
                node* temp = current;
                current = current->m_next;
                delete temp;
            }
        }

        void push_back(const int& value) {
            node* n = new node(value);
            if (m_size == 0){
                m_head = n;
                m_tail = n;
            }
            else {
                node* temp = m_tail;
                temp->m_next = n;
                n->m_prev = temp;
                m_tail = n;
            }
            m_size++;
        }

        void pop_back() {
            if (m_size == 0) {
                // TODO undefined
            }
            else if (m_size == 1) {
                node* temp = m_tail;
                delete temp;
                m_head = nullptr;
                m_tail = nullptr;
                m_size--;
            }
            else {
                node* temp = m_tail;
                node* prev = m_tail->m_prev;
                prev->m_next = nullptr;
                delete temp;
                m_tail = prev;
                m_size--;
            }
        }

        void push_front(const int& value) {
            node* n = new node(value);
            if (m_size == 0){
                m_head = n;
                m_tail = n;
            }
            else {
                node* temp = m_head;
                temp->m_prev = n;
                n->m_next = temp;
                m_head = n;
            }
            m_size++;
        }

        void pop_front() {
            if (m_size == 0) {
                // TODO undefined
            }
            else if (m_size == 1) {
                node* temp = m_tail;
                delete temp;
                m_head = nullptr;
                m_tail = nullptr;
                m_size--;
            }
            else {
                node* temp = m_head;
                node* next = m_head->m_next;
                next->m_prev = nullptr;
                delete temp;
                m_head = next;
                m_size--;
            }
        }

        // TODO how to also include m_capacity?
        void resize(const size_t n){
            static const size_t MIN_SIZE = 10;
            size_t goal_size = std::max(n, MIN_SIZE);

            // if m_size < goal_size, pad with new elements from the end
            if (m_size < goal_size){
                node* current = m_tail;
                for (int i=m_size; i<goal_size; i++) {
                    node* n = new node(0);
                    current->m_next = n;
                    n->m_prev = current;
                    current = current->m_next;
                }
                m_tail = current;
                m_size = goal_size;
            }
            // if m_size > goal_size, truncate elements from the end
            else {
                node* current = m_tail;
                for (int i=m_size; i>goal_size; i--) {
                    current = current->m_prev;
                    delete current->m_next;
                }
                m_tail = current;
                m_size = goal_size;
            }
        }

        struct iterator;
        typedef iterator self_type;
        typedef int value_type;
        typedef size_t size_type;
        typedef int* pointer;
        typedef int& reference;

        struct iterator {
            node* m_ptr;
            iterator(node* ptr): m_ptr(ptr) {}
            // TODO proper way for a destructor?
            ~iterator() {m_ptr = nullptr;}
            // prefix
            self_type operator++() {
                m_ptr = m_ptr->m_next;
                return *this;
            }
            // postfix
            self_type operator++(int what) {
                self_type current_ptr = *this;
                m_ptr = m_ptr->m_next;
                return current_ptr;
            }
            // prefix
            self_type operator--() {
                m_ptr = m_ptr->m_prev;
                return *this;
            }
            // postfix
            self_type operator--(int what) {
                self_type current_ptr = *this;
                m_ptr = m_ptr->m_prev;
                return current_ptr;
            }

            reference operator*() { return m_ptr->m_data; }
            pointer operator->() { return &m_ptr->m_data; }
            bool operator==(const self_type& rhs) {
                return m_ptr == rhs.m_ptr;
            }
            bool operator!=(const self_type& rhs) {
                return m_ptr != rhs.m_ptr;
            }
        };

        iterator begin(){
            return iterator(m_head);
        }

        iterator end(){
            return iterator(m_tail);
        }


    };

    std::ostream& operator<<(std::ostream &strm, const list& v){
        static const int CUTOFF = 100;
        static const int SNEAK_PEEK = 6;
        // TODO unduplicate this and evector's operator<<() method
        // TODO can this be cleaner?
        // TODO can this be shorter?

        strm << "[";
        if (v.m_size == 0){
        }
        else if (v.m_size == 1){
            strm << v.m_head->m_data;
        }
        else if (v.m_size < CUTOFF){
            node* current = v.m_head;
            for (size_t i=0; i<v.m_size-1; i++){
                strm << current->m_data << ", ";
                current = current->m_next;
            }
            strm << v.m_tail->m_data;
        }
        else {
            node* current;
            current = v.m_head;
            for (size_t i=0; i<SNEAK_PEEK; i++){
                strm << current->m_data << ", ";
                current = current->m_next;
            }
            strm << "..., ";
            current = v.m_tail;
            for (size_t i=0; i<SNEAK_PEEK; i++){
                current = current->m_prev;
            }
            for(size_t i=0; i<SNEAK_PEEK; i++){
                strm << current->m_data << ", ";
                current = current->m_next;
            }
            strm << v.m_tail->m_data;
        }
        strm << "]";
        return strm;
    }

}
