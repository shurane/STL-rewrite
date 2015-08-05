#pragma once
#include <stddef.h>
#include <iostream>
#include <iterator>
#include <unistd.h>

namespace ehtesh {
    struct node {
        const int* m_data;
        node* m_next;
        node* m_prev;
        node(const int* data) {
            m_data = data;
            m_next = nullptr;
            m_prev = nullptr;
        }
        ~node() {
            delete m_data;
        }
    };

    std::ostream& operator<<(std::ostream &strm, const node& n){
        return strm << "Node(" 
            << "m_data=" << *n.m_data 
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
                std::cout << "~list(): " << *current << std::endl;
                node* temp = current;
                current = current->m_next;
                delete temp;
            }
        }

        // TODO make way to provide primitive types without using `new`
        void push_back(const int* value) {
            node* n = new node(value);
            //std::cout << "list.push_back(" << *n << ")" << std::endl;
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
            //std::cout << "list.pop_back(" << *m_tail << ")" << std::endl;
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

    };
}
