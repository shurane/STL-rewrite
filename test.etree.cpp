#include "etree.hpp"
#include <iostream>

// http://stackoverflow.com/a/12468109/198348
// though I'm surprised this chooses to use rand()
std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}
int main(int argc, char** argv){
    static const int TOTAL_SIZE = 1e1;

    ehtesh::Tree<int> et1;
    for (int i=0; i< TOTAL_SIZE; i++){
        et1.insert(i);
    }

    ehtesh::Tree<int> et2;
    et2.insert(TOTAL_SIZE/2);
    for (int i=0; i< TOTAL_SIZE/2; i++){
        et2.insert(i);
        et2.insert(TOTAL_SIZE-i);
    }

    ehtesh::Tree<std::string> et3;
    for (int i=0; i< TOTAL_SIZE; i++){
        et3.insert(random_string(10));
    }
    std::cout << et1 << std::endl;
    std::cout << et2 << std::endl;
    std::cout << et3 << std::endl;

    et3.erase("tzxlYvKWrO");

}
