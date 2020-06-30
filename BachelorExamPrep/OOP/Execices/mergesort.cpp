//
// Created by geo on 17.06.2020.
//

#include "mergesort.h"

//arr = [1, 2, 3, 4, 5, 6];
//left = 0, right = 5, mid = 2;
//leftSide = [0, 1, 2]
//rightSide = [3, 4, 5]
void merge(int left, int mid, int right, int *arr) {
    int *leftSide = new int[mid - left + 1];
    int *rightSide = new int[right - mid];
    int lCount = 0;
    int rCount = 0;
    for (int i = left; i <= mid; i++) {
        leftSide[lCount++] = arr[i];
    }

    for (int i = mid + 1; i <= right; i++) {
        rightSide[rCount++] = arr[i];
    }
    int startPos = left;
    int i = 0, j = 0;
    while (i < lCount && j < rCount) {
        if (leftSide[i] < rightSide[j]) {
            arr[startPos] = leftSide[i];
            i++;
        } else {
            arr[startPos] = rightSide[j];
            j++;
        }
        startPos++;
    }

    while (i < lCount) {
        arr[startPos++] = leftSide[i++];
    }

    while (j < rCount) {
        arr[startPos++] = rightSide[j++];
    }

    delete[] leftSide;
    delete[] rightSide;
}

void mergeSort(int left, int right, int *arr) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid, arr);
        mergeSort(mid + 1, right, arr);
        merge(left, mid, right, arr);
    }
}