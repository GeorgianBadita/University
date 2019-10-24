#include <cstdio>
#include "collection.cpp"
using namespace std;

FILE *f = freopen("collection.in", "r", stdin);
FILE *g = freopen("collection.out", "w", stdout);


int n;

Collection add_data(Collection collection, int n) {
    for(int i = 1; i<=n; i++) {
        collection.add(i*i);
    }
    return collection;
}

void print_collection(Collection collection) {
    Iterator it = Iterator(collection);

    while(it.valid() == true) {

        printf("%d ", it.element());
        it.next();
    }
}

int main() {

    Collection collection = Collection();

    scanf("%d", &n);
    collection = add_data(collection, n);
    collection.del(625);
    print_collection(collection);
    return 0;
}
