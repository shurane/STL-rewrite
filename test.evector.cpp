#include "evector.hpp"
#include "prettyprint.hpp"
#include <ostream>
#include <vector>

int main(int argc, char** argv){
    //std::vector<int> v(10);
    //v.push_back(-1);
    //v[1] = -2;
    //std :: cout << "std::vector:" << v[15] << std::endl;
    static const int TOTAL_SIZE = 1e3;
    static const int SNEAK_PEEK = 5;
    ehtesh::vector ev(10);
    for (int i=0; i<TOTAL_SIZE; i++){
        ev.push_back(i);
    }
    //ev[5] = -1;
    //std::cout << ev[5] << std::endl;
    std::cout << "ehtesh::vector:" << ev << std::endl;
    std::cout << "ehtesh::vector:" << ev.m_size << " " << ev.m_capacity << std::endl;
    //for (int i=0; i<TOTAL_SIZE-SNEAK_PEEK; i++){
        //ev.pop_back();
    //}
    ev.resize(TOTAL_SIZE + SNEAK_PEEK);
    for (int i=0;i<15; i++){
        ev.push_back(i);
    }
    std::cout << "ehtesh::vector:" << ev.m_size << " " << ev.m_capacity << std::endl;
    ev.resize(SNEAK_PEEK);
    std::cout << "ehtesh::vector:" << ev.m_size << " " << ev.m_capacity << std::endl;
    ev.push_back(1);
    std::cout << "ehtesh::vector:" << ev.m_size << " " << ev.m_capacity << std::endl;

    return 0;
}
