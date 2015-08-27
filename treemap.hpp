#pragma once
#include "tree.hpp"

namespace ehtesh {
    template <typename K, typename V>
    struct treemap {
        tree<K>* t;
        treemap(){
            t = new tree<K>;
        }
        ~treemap(){
            delete t;
        }
    };

    template <typename K, typename V>
    std::ostream& operator<<(std::ostream &strm, const treemap<K,V>& t){
        return strm << "treemap<K,V>";
    }
}
