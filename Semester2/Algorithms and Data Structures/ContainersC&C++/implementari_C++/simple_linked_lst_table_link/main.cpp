#include <iostream>
#include "LinkedList.h"

void create_lst(LinkedList& lst){
    lst.add_elem(1);
    lst.add_elem(2);
    lst.add_elem(3);
    lst.add_elem(4);
    lst.add_elem(5);

}

void print_lst(const LinkedList& lst){
    auto it = lst.iterator();
    while(it.valid()){
        std::cout << it.get_element() << ' ';
        it.next();
    }

}

int main(){
    auto link_lst = LinkedList();
    create_lst(link_lst);
    print_lst(link_lst);
    std::cout << '\n';
    std::cout << link_lst.size() << '\n';
    std::cout << link_lst.search_elem(1) << ' ' << link_lst.search_elem(12);

    std::cout << '\n';
    print_lst(link_lst);
    return 0;
}