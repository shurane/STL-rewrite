#pragma once
#include <stddef.h>
#include <iostream>
#include <iterator>
#include <unistd.h>

namespace ehtesh {
    struct node {
        int* m_data;
        node* next;
        node* prev;
        node(int* data) {
            m_data = data;
            next = nullptr;
            prev = nullptr;
        }
        ~node() {
        }
    };

    std::ostream& operator<<(std::ostream &strm, const node& n){
        return strm << "Node(" 
            << "m_data=" << *n.m_data 
            << ",prev=" << n.prev
            << ",next=" << n.next
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
                current = current->next;
                delete temp->m_data;
                delete temp;
            }
        }

        // TODO make const
        void push_back(int* value) {
            node* n = new node(value);
            std::cout << "list.push_back(" << n << ")" << std::endl;
            if (m_size == 0){
                m_head = n;
                m_tail = n;
            }
            else {
                node* temp = m_tail;
                temp->next = n;
                m_tail = n;
            }
            m_size++;
        }

    };
}
