#include <iostream>

template <typename T>
struct node {
    const T& m_data;

    node(const T& data): m_data(data) {
    }
};

template <typename T>
std::ostream& operator<<(std::ostream &strm, const node<T>& n){
    return strm << n.m_data;
}


int main(){

    node<int> ni(5);
    node<const char*> ncs("const char*");
    node<std::string> ns("std::string");
    std::cout << ni << std::endl;
    std::cout << ncs << std::endl;
    std::cout << ns << std::endl;
}
