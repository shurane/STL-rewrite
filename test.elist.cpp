#include "elist.hpp"
#include "prettyprint.hpp"
#include <iostream>
#include <list>

int main(int argc, char** argv){

    std::list<int> l;
    ehtesh::list el;

    static const int TOTAL_SIZE = 1e2;

    for (int i=0; i<TOTAL_SIZE; i++){
        el.push_back(i);
    }

    auto l_it = l.begin();
    ehtesh::list::iterator el_it = el.begin();
    ehtesh::list::iterator el_it_other = el.begin();
    std::cout << "std::list::iterator<int>:" << *l_it << std::endl;
    std::cout << "ehtesh::list::iterator:" << *el_it << std::endl;
    std::cout << "ehtesh::list::iterator.operator==()" << (el_it == el_it_other) << std::endl; // true
    el_it_other++;
    std::cout << "ehtesh::list::iterator.operator==()" << (el_it == el_it_other) << std::endl; // false
    std::cout << "ehtesh::list::iterator.operator==()" << (++el_it == el_it_other) << std::endl; // true
    std::cout << "ehtesh::list::iterator.operator==()" << (el_it == el_it_other++) << std::endl; // true
    std::cout << "ehtesh::list::iterator.operator==()" << (el_it == el_it_other) << std::endl; // false
    std::cout << "ehtesh::list::iterator.operator==()" << (el_it == el_it_other--) << std::endl; // false
    std::cout << "ehtesh::list::iterator.operator==()" << (el_it == el_it_other) << std::endl; // true
    std::cout << "ehtesh::list::iterator.operator==()" << (--el_it == el_it_other) << std::endl; // false

    for (auto i : el) {
        std::cout << i << std::endl;
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
