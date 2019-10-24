#include <iostream>
#include "DLinkedList.h"

void create_lst(DLinkedList& lst){
    lst.add_elem_front(1);
    lst.add_elem_front(2);
    lst.add_elem_front(3);
    lst.add_elem_front(4);
    lst.add_elem_front(5);

}

void print_lst(const DLinkedList& lst){
    auto it = lst.iterator();
    while(it.valid()){
        std::cout << it.get_elem() << ' ';
        it.next();
    }
    std::cout << '\n';
}

int main() {
    auto lst = DLinkedList();
    create_lst(lst);
    print_lst(lst);
    lst.add_element_after(0, 6);
    print_lst(lst);
    return 0;
}