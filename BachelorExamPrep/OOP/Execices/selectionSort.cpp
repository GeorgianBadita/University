//
// Created by geo on 17.06.2020.
//

#include "selectionSort.h"


void selectionSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[pos]) {
                pos = j;
            }
        }
        int aux = arr[i];
        arr[i] = arr[pos];
        arr[pos] = aux;
    }
}