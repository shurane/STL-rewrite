#pragma once
#include <stddef.h>
#include <iostream>
#include <iterator>

namespace ehtesh {
    struct vector {
        size_t m_length;
        size_t last;
        int* elements;
        vector(): vector(0) {}
        vector(size_t length){
            m_length = length;
            elements = new int[length];
            last = 0;
        }
        // - [x] push_back
        // - [x] keep track of last inserted element
        // - [x] resize when the array gets filled up
        // - [ ] memory leaks? What.

        void push_back(const int& value) {
            if (last == m_length){
                int* resized = new int[2*m_length];
                //std::copy(std::begin(elements),
                          //std::end(elements),
                          //std::begin(resized));

                std::copy(elements,
                          elements + (sizeof(int) * m_length),
                          resized);

                delete[] elements;
                elements = resized;
                m_length = 2*m_length;
            }

            elements[last++] = value;
        }

        int& operator[](const int index){
            return elements[index];
        }

    private:
    };

    std::ostream& operator<<(std::ostream &strm, const vector& v){
        strm << "[";
        //// todo add .begin() and .end() function
        //for (auto i : v.elements){
            //strm << i << ", "
        //}
        if (v.m_length == 0){
        }
        else if (v.m_length == 1){
            strm << v.elements[0];
        }
        else {
            for (size_t i=0; i<v.m_length-1; i++){
                strm << v.elements[i] << ", ";
            }
            strm << v.elements[v.m_length-1];
        }
        strm << "]";
        return strm;
    }
}

