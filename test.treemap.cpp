#include "treemap.hpp"

int main(int argc, char** argv){
    static const int TOTAL_SIZE = 1e1;

    ehtesh::treemap<std::string, int> tmap;
    std::cout << tmap << std::endl;
}
