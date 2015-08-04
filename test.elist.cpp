#include "elist.hpp"
#include "prettyprint.hpp"
#include <iostream>
#include <list>

int main(int argc, char** argv){

    std::list<int> l;
    ehtesh::list el;

    for (int i=0; i<10; i++){
        int* j = new int(i);
        el.push_back(j);
    }

    std::cout << "m_head=" << el.m_head << std::endl;
    std::cout << "m_tail=" << el.m_tail << std::endl;

    //ehtesh::node* current = el.m_head;
    //while (current){
        //std::cout << *current << std::endl;
        //current = current->next;
    //}

    return 0;
}
