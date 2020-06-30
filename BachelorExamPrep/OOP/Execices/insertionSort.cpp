//
// Created by geo on 17.06.2020.
//

#include "insertionSort.h"


void insertionSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        int p = i;
        while (j >= 0 && arr[j] > arr[p]) {
            int tmp = arr[p];
            arr[p] = arr[j];
            arr[j] = tmp;
            j--;
            p--;
        }
    }
}