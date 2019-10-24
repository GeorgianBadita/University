/*
 * Supr*
 * First Binary Heap implementation
 */
#include <iostream>
#include <climits>

using namespace std;

void swap(int *x, int *y);

class MinHeap{

    int capacity;   // maximum possible size of min heap
    int heap_size;  // current number of elements in min heap
    int* harr;      // pointer to array of elements in heap

public:
    //Constructor
    MinHeap(int capacity);

    // to heapify a subtree with root at given index
    void MinHeapify(int );

    // to get index of the parent of node i
    int parent(int i) {return (i-1)/2; }

    // to get index of left child of node i
    int left(int i) { return (2*i + 1);}

    // to get index of right child of node i
    int right(int i){ return (2*i + 2);}

    // to extract the root which is the minimum element
    int extractMin();

    // returns the minimum key (key at root) from min heap
    int getMin() {return harr[0];}

    // delets a key stored at index i
    void deleteKey(int i);

    //inserts a new key k
    void insertKey(int k);
};

MinHeap::MinHeap(int capacity){
    heap_size = 0;
    capacity = capacity;
    harr = new int[capacity];
}

void MinHeap::insertKey(int k){
    if(heap_size == capacity){
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    //First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    //Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin(){
    if(heap_size <= 0){
        return INT_MAX;
    }
    if(heap_size == 1){
        heap_size --;
        return harr[0];
    }

    //Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}

//A recursive method to heapify a subtree with root at given index
//This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && harr[l] < harr[i]){
        smallest = l;
    }
    if(r < heap_size && harr[r] < harr[smallest]){
        smallest = r;
    }
    if(smallest != i){
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

//A utility function to swap two elements
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << ' ';
    cout << h.extractMin() << ' ';
    cout << h.extractMin() << ' ';
    cout << h.extractMin() << ' ';
    cout << h.extractMin() << ' ';
    cout << h.extractMin() << ' ';
    cout << h.extractMin() << ' ';
    return 0;
}

