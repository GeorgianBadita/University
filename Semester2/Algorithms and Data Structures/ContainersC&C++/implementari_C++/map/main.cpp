#include <iostream>
#include <cassert>
#include "Map.h"


void create_map(Map& mp){
    mp.add_element({"Geo", 18});
    mp.add_element({"Tudor", 20});
    mp.add_element({"Matko", 19});
    mp.add_element({"Alexis", 21});
    assert(mp.search("Alexis") != -1);
    assert(mp.search("Alexandru") == -1);
    assert(mp.search("Geo") != -1);
    mp.delete_key("Geo");
    mp.delete_key("Alexis");
    mp.delete_key("Matko");
    mp.delete_key("Tudor");
    mp.delete_key("Tudor");
}

void print_map(const Map& mp){
    auto it = mp.iterator();
    while(it.valid()){
        auto pair = it.get_pair();
        std::cout << pair.key << " -> " << pair.value << '\n';
        it.next();
    }
}

int main() {
    auto new_map = Map();
    create_map(new_map);
    //print_map(new_map);
    return 0;
}