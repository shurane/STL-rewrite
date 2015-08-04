#include "elist.hpp"
#include "prettyprint.hpp"
#include <iostream>
#include <list>

int main(int argc, char** argv){

    std::list<int> l;
    ehtesh::list el;

    for (int i=0; i<10; i++){
        el.push_back(new int(i));
    }

    ehtesh::node* current = el.m_head;
    while (current){
        std::cout << "lol current" << *current << std::endl;
        current = current->next;
    }

    return 0;
}
