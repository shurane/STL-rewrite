#include "elist.hpp"
#include "prettyprint.hpp"
#include <iostream>
#include <list>

int main(int argc, char** argv){

    std::list<int> l;
    ehtesh::list el;

    static const int TOTAL_SIZE = 1e3;

    for (int i=0; i<TOTAL_SIZE; i++){
        el.push_back(i);
    }

    std::cout << "push_back():" << el << std::endl;

    el.resize(TOTAL_SIZE * 2);

    std::cout << "resize():" << el << std::endl;

    for (int i=0; i<TOTAL_SIZE; i++){
        el.pop_back();
    }
    std::cout << "pop_back():" << el << std::endl;

    for (int i=0; i<TOTAL_SIZE; i++){
        el.pop_front();
    }

    std::cout << "pop_front():" << el << std::endl;

    for (int i=0; i<TOTAL_SIZE; i++){
        el.push_front(i);
    }

    std::cout << "push_front():" << el << std::endl;

    for (int i=0; i<TOTAL_SIZE; i++){
        el.pop_front();
    }

    std::cout << "pop_front():" << el << std::endl;

    return 0;
}
