#include <iostream>
#include "RareMatrix.h"


void create_matrix(RareMatrix& mt){
    mt.add_new_elem({4, 5, -2});
    mt.add_new_elem({3, 5, -5});
    mt.add_new_elem({1, 2, -2});
    mt.add_new_elem({1, 3, -6});
    mt.add_new_elem({3, 2, -9});
}

void print_matrix(const RareMatrix& mt){
    auto it = mt.iterator();
    while(it.valid()){
        auto tr = it.get_elem();
        std::cout << tr.line << ' ' << tr.column << ' ' << tr.elem << '\n';
        it.next();
    }
}

int main(){
    auto mt = RareMatrix();
    create_matrix(mt);
    print_matrix(mt);
    return 0;
}




