#include <iostream>
#include "MultiMap.h"

void create_multi_map(MultiMap& map){
    map.add_new_pair({"home", "familie"});
    map.add_new_pair({"book", "a rezerva"});
    map.add_new_pair({"blood", "neam"});
    map.add_new_pair({"book", "publicatie"});
    map.add_new_pair({"red", "rosu"});
    map.add_new_pair({"book", "carte"});
    map.add_new_pair({"blood", "sange"});
    map.add_new_pair({"home", "casa"});
    /*map.delete_pair({"home", "casa"});
    map.delete_pair({"red", "rosu"});
    map.delete_pair({"blood", "neam"});
    map.delete_pair({"blood", "sange"});
    map.delete_pair({"book", "carte"});
    map.delete_pair({"book", "a rezerva"});
    map.delete_pair({"book", "publicatie"});
    map.delete_pair({"home", "familie"});*/
}

void print_multi_map(const MultiMap& map){
    auto iterator = map.iterator();
    while(iterator.is_valid()){
        auto elem = iterator.get_pair();
        std::cout << elem.key << " -> " << elem.value << '\n';
        iterator.next();
    }
}

int main(){
    auto my_multi_map = MultiMap();
    create_multi_map(my_multi_map);
    print_multi_map(my_multi_map);
    return 0;
}