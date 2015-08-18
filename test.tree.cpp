#include "tree.hpp"
#include <iostream>

int main(int argc, char** argv){
    static const int TOTAL_SIZE = 1e1;

    ehtesh::tree et1;
    for (int i=0; i< TOTAL_SIZE; i++){
        et1.insert(i);
    }

    ehtesh::tree et2;
    et2.insert(TOTAL_SIZE/2);
    for (int i=0; i< TOTAL_SIZE/2; i++){
        et2.insert(i);
        et2.insert(TOTAL_SIZE-i);
    }

    std::cout << et1 << std::endl;
    std::cout << et2 << std::endl;
}
