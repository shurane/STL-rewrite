#include "elist.hpp"
#include "prettyprint.hpp"
#include <iostream>
#include <list>

int main(int argc, char** argv){

    std::list<int> l;
    ehtesh::list el;

    for (int i=0; i<10; i++){
        int* j = new int(i);
        //std::cout << *j << std::endl;
        el.push_back(j);
    }

    //ehtesh::node* current = el.m_head;
    //while (current){
        //std::cout << *current->m_data << std::endl;
        //current = current->next;
    //}

    return 0;
}
