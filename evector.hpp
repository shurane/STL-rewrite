#pragma once
#include <stddef.h>
#include <iostream>
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
                int* resized = new int[2*m_capacity];
                //std::copy(std::begin(m_elements),
                          //std::end(m_elements),
                          //std::begin(resized));

                std::copy(m_elements,
                          m_elements + m_capacity,
                          resized);

                delete[] m_elements;
                m_elements = resized;
                m_capacity = 2*m_capacity;
            }

            m_elements[m_size++] = value;
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

