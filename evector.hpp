#pragma once
#include <stddef.h>
#include <iostream>
#include <algorithm>
#include <iterator>

namespace ehtesh {
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
        // - [x] push_back
        // - [x] keep track of last inserted element
        // - [x] resize when the array gets filled up
        // - [ ] use heap allocator

        void push_back(const int& value) {
            if (m_size == m_capacity){
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

        int& operator[](const int index){
            return m_elements[index];
        }

    private:
    };

    std::ostream& operator<<(std::ostream &strm, const vector& v){
        static const int CUTOFF = 100;
        static const int SNEAK_PEAK = 6;
        // TODO add .begin() and .end() function
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
            for (size_t i=0; i<SNEAK_PEAK; i++){
                strm << v.m_elements[i] << ", ";
            }
            strm << "..., ";
            for (size_t i=v.m_size - SNEAK_PEAK; i<v.m_size-1; i++){
                strm << v.m_elements[i] << ", ";
            }
            strm << v.m_elements[v.m_size-1];
        }
        strm << "]";
        return strm;
    }
}

