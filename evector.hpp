#pragma once
#include <stddef.h>
#include <iostream>
#include <algorithm>
#include <iterator>

namespace ehtesh {
    // TODO
    // - [ ] allow alternative allocators
    // - [ ] push_front
    // - [ ] pop_front
    // - [ ] slice
    // - [ ] make vector from an iterator
    // - [ ] make vector from an iterator: begin(), end()
    // - [ ] disallow 0 as a capacity

    struct vector {

        size_t m_capacity;
        size_t m_size;
        int* m_elements;
        vector(): vector(10) {}

        vector(size_t length){
            m_capacity = length;
            m_elements = new int[length];
            m_size = 0;
        }

        ~vector()
        {
            m_capacity = 0;
            delete[] m_elements;
            m_size = 0;
        }

        void push_back(const int& value) {
            if (m_size == m_capacity && m_capacity == 0){
                resize(10);
            }
            else if (m_size == m_capacity && m_capacity != 0){
                resize(2*m_capacity);
            }

            m_elements[m_size++] = value;
        }

        void pop_back() {
            m_elements[m_size--] = 0;
        }

        void resize(const size_t n){
            static const size_t MIN_SIZE = 10;
            const size_t goal_capacity = std::max(n, MIN_SIZE);

            int* resized = new int[goal_capacity];
            size_t goal_size = std::min(n, m_size);
            std::copy(m_elements,
                      m_elements + goal_size,
                      resized);

            delete[] m_elements;
            m_elements = resized;
            m_size = goal_size;
            m_capacity = goal_capacity;
        }

        void clear(){
            for (int i=0; i < m_size; i++){
                m_elements[i] = 0;
            }
            m_size = 0;
        }

        int& operator[](const int index){
            return m_elements[index];
        }
        //// TODO is this needed?
        const int& operator[](const int index) const{
            return m_elements[index];
        }

        // http://accu.org/index.php/journals/389
        // is forward declaration redundant?
        struct iterator;
        typedef iterator self_type;
        typedef int value_type;
        typedef size_t size_type;
        typedef int* pointer;
        typedef int& reference;

        struct iterator {
            pointer m_ptr;
            iterator(pointer ptr): m_ptr(ptr) {}
            // TODO proper way for a destructor?
            ~iterator() {m_ptr = nullptr;}
            // prefix
            self_type operator++() { m_ptr++; return *this; } 
            // postfix
            self_type operator++(int what) {
                self_type current_ptr = *this;
                m_ptr++;
                return current_ptr;
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
            return iterator(m_elements);
        }

        iterator end(){
            return iterator(m_elements + m_size);
        }

    private:
    };

    std::ostream& operator<<(std::ostream &strm, const vector& v){
        static const int CUTOFF = 100;
        static const int SNEAK_PEEK = 6;
        // TODO can this be shorter?

        strm << "[";
        if (v.m_size == 0){
        }
        else if (v.m_size == 1){
            strm << v.m_elements[0];
        }
        else if (v.m_size < CUTOFF){
            for (size_t i=0; i<v.m_size-1; i++){
                strm << v.m_elements[i] << ", ";
            }
            strm << v.m_elements[v.m_size-1];
        }
        else {
            for (size_t i=0; i<SNEAK_PEEK; i++){
                strm << v.m_elements[i] << ", ";
            }
            strm << "..., ";
            for (size_t i=v.m_size - SNEAK_PEEK; i<v.m_size-1; i++){
                strm << v.m_elements[i] << ", ";
            }
            strm << v.m_elements[v.m_size-1];
        }
        strm << "]";
        return strm;
    }
}

