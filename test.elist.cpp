#include "elist.hpp"
#include "prettyprint.hpp"
#include <iostream>
#include <list>

int main(int argc, char** argv){

    std::list<int> l;
    ehtesh::list el;

    static const int TOTAL_SIZE = 1e3;

    for (int i=0; i<TOTAL_SIZE; i++){
        l.push_back(i);
        el.push_back(new int(i));
    }

    for (int i=0; i<TOTAL_SIZE; i++){
        el.pop_back();
    }

    ehtesh::node* current = el.m_head;
    while (current){
        current = current->m_next;
    }

    return 0;
}
