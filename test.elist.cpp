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
        el.push_back(i);
    }

    std::cout << el << std::endl;

    el.resize(TOTAL_SIZE * 2);

    std::cout << el << std::endl;

    for (int i=0; i<TOTAL_SIZE; i++){
        el.pop_back();
    }
    return 0;
}
