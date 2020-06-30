//
// Created by geo on 17.06.2020.
//

#include "quickSort.h"


int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    int tmp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = tmp;

    return i + 1;
}

void quickSort(int left, int right, int *arr) {
    if (left < right) {
        int pIndex = partition(arr, left, right);

        quickSort(left, pIndex - 1, arr);
        quickSort(pIndex + 1, right, arr);
    }

    //partitionare
}