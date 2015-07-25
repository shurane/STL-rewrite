#include "evector.hpp"
#include "prettyprint.hpp"
#include <ostream>
#include <vector>

int main(int argc, char** argv){
    std::vector<int> v(10);
    v.push_back(-1);
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
    std::cout << "ehtesh::vector.push_back()*TOTAL_SIZE: " << ev.m_size << " " << ev.m_capacity << std::endl;
    ev.resize(SNEAK_PEEK);
    std::cout << "ehtesh::vector.resize(SNEAK_PEEK): " << ev.m_size << " " << ev.m_capacity << std::endl;
    ev.push_back(1);
    std::cout << "ehtesh::vector.push_back(1):" << ev.m_size << " " << ev.m_capacity << std::endl;
    ev.clear();
    std::cout << "ehtesh::vector.clear(): " << ev.m_size << " " << ev.m_capacity << std::endl;

    for (int i=10;i>0;i--){
        ev.push_back(i);
    }

    auto v_it = v.begin();
    ehtesh::vector::iterator ev_it = ev.begin();
    ehtesh::vector::iterator ev_it_other = ev.begin();
    std::cout << "std::vector::iterator<int>:" << *v_it << std::endl;
    std::cout << "ehtesh::vector::iterator:" << *ev_it << std::endl;
    std::cout << "ehtesh::vector::iterator.operator==()" << (ev_it == ev_it_other) << std::endl; // true
    ev_it_other++;
    std::cout << "ehtesh::vector::iterator.operator==()" << (ev_it == ev_it_other) << std::endl; // false
    std::cout << "ehtesh::vector::iterator.operator==()" << (++ev_it == ev_it_other) << std::endl; // true
    std::cout << "ehtesh::vector::iterator.operator==()" << (ev_it == ev_it_other++) << std::endl; // true
    std::cout << "ehtesh::vector::iterator.operator==()" << (ev_it == ev_it_other) << std::endl; // false
    std::cout << "ehtesh::vector::iterator.operator==()" << (ev_it == ev_it_other--) << std::endl; // false
    std::cout << "ehtesh::vector::iterator.operator==()" << (ev_it == ev_it_other) << std::endl; // true
    std::cout << "ehtesh::vector::iterator.operator==()" << (--ev_it == ev_it_other) << std::endl; // false

    for (auto i : ev) {
        std::cout << i << std::endl;
    }

    return 0;
}
