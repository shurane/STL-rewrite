#include "evector.hpp"
#include "prettyprint.hpp"
#include <ostream>
#include <vector>

int main(int argc, char** argv){
    std::vector<int> v(10);
    v.push_back(-1);
    v[1] = -2;
    std :: cout << "std::vector:" << v[15] << std::endl;
    ehtesh::vector ev(10);
    for (int i=0; i<20; i++){
        ev.push_back(i);
    }
    //ev[5] = -1;
    //std::cout << ev[5] << std::endl;
    std::cout << "ehtesh::vector:" << ev << std::endl;
    return 0;
}
