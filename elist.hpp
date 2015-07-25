#pragma once
#include <stddef.h>
#include <iostream>
#include <iterator>

namespace ehtesh {
    struct list {
        size_t m_size;
        int* m_head;
        int* m_tail;
        list() {
            m_size = 0;
            m_head = nullptr;
            m_tail = nullptr;
        }
        ~list() {
            // TODO iterate through linked list and delete each element
        }
    };
}
