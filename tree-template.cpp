#include <iostream>
#include <vector>
#include <string>

template <typename T>
struct node {
    const T m_data;

    node(const T& data): m_data(data) {}
};

template <typename T>
std::ostream& operator<<(std::ostream &strm, const node<T>& n){
    return strm <<  n.m_data;
}


int main(){

    node<int> ni(5);
    node<const char*> ncs("const char*");
    node<std::string> ns("std::string");
    std::cout << ni << std::endl;
    std::cout << ncs << std::endl;
    std::cout << ns << std::endl;

    //// setup vectors
    //auto* v1 = new std::vector<std::string>;
    //for (int i=0; i<10; i++){
        //v1->push_back("testing 1");
    //}
    //(*v1)[2] += " with modification";
    //std::string* last1 = &(*v1)[9];
    //v1->pop_back();

    //std::string* last2;
    //{
        //std::vector<std::string> v2;
        //for (int i=0; i<10; i++){
            //v2.push_back("testing 2");
        //}
        //v2[2] += " with modification";

        //last2 = &v2[9];
    //}
    //delete v1;

    //// grab reference and then remove those elements, then try to print out
    //// reference

    //std::cout << *last1 << std::endl;
    //std::cout << *last2 << std::endl;

}
