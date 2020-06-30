#include <iostream>

/**
 * Function which sequentially finds an element into an array - complexity Theta(n)
 * @param a - array where to find the element
 * @param n - length of the array
 * @param value - value to be find
 * @return n if value is not in the array, the position of the element otherwise
 */
int cautaSecvNaiv(const int a[], int n, int value) {
    int p = n;
    for (int i = 0; i < n; i++) {
        if (a[i] == value && p == n) {
            p = i;
        }
    }

    return p;
}

/**
 * Function which sequentially finds an element into an array - complexity O(n)
 * @param a - array where to find the element
 * @param n - length of the array
 * @param value - value to be find
 * @return n if value is not in the array, the position of the element otherwise
 */
int cautaSecvOptim(const int a[], int n, int value) {
    int p = 0;
    while (p < n && a[p] != value) {
        p++;
    }

    return p;
}

/**
 * Binary search function - complexity O(nlogn)
 * @param a - array to search the value
 * @param n  - length of the array
 * @param value - value to be searched
 * @return - p s.t 0<p<n && a[p-1] < value <= a[p]
 */
int binSearch(const int a[], int n, int value) {
    int st = 0;
    int dr = n - 1;
    while (st + 1 < dr) {
        int m = (st + dr) / 2;
        if (a[m] < value) {
            st = m;
        } else if (a[m] > value) {
            dr = m;
        } else {
            return m;
        }
    }
    return dr;
}

/**
 * Function which binary finds an element into an array - complexity O(nlogn)
 * @param a - array where to find the element
 * @param n - length of the array
 * @param value - value to be find
 * @return n if value is not in the array, the position of the element otherwise
 */
int cautaBinar(const int a[], int n, int value) {
    if (value < a[0]) {
        return 0;
    }
    if (value > a[n - 1]) {
        return n;
    }
    return binSearch(a, n, value);
}

/**
 * Function to merge two sorted lists - complexity O(m + n)
 * @param a - first list (a0 <= a1 <= .. <= an-1)
 * @param n - length of list a
 * @param b - second list (b0 <= b1 <= .. <= bn-1)
 * @param m - length of list b
 * @param c - result c is the result of merging list a and b (c0 <= c1..<= cn+m-1), length of c is m + n
 */
void interclas(const int a[], int n, const int b[], int m, int c[]) {
    int i, j, k;
    i = j = k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < n) {
        c[k++] = a[i++];
    }

    while (j < m) {
        c[k++] = b[j++];
    }
}

/**
 * Function to sort a list using selection sort - complexity Theta(n^2)
 * @param a - list to be sorted
 * @param n - length of the list
 * @result a permutation of list a such that (a0 <= a1 <=...<= an-1)
 */
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int p = i;
        for (int j = i + 1; j < n; j++) {
            if (a[p] > a[j]) {
                p = j;
            }
        }
        int tmp = a[p];
        a[p] = a[i];
        a[i] = tmp;
    }
}

/**
 * Function to sort a list using bubble sort - complexity O(n^2)
 * @param a - list to be sorted
 * @param n - length of the list
 * @result a permutation of list a such that (a0 <= a1 <=...<= an-1)
 */
void bubbleSort(int a[], int n) {
    bool sorted = false;
    do {
        sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                sorted = false;
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
        }
    } while (!sorted);
}

/**
 * Function to sort a list using insertion sort - complexity O(n^2)
 * @param a - list to be sorted
 * @param n - length of the list
 * @result a permutation of list a such that (a0 <= a1 <=...<= an-1)
 */
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int p = i - 1;
        int j = i;
        while (j > 0 && a[j] < a[p]) {
            int tmp = a[p];
            a[p] = a[j];
            a[j] = tmp;
            p--;
            j--;
        }
    }
}

/**
 * Function to merge elements of array a between indexes [left,right] - Theta(right-left)
 * @param a - array whose elements to merge
 * @param left - left index
 * @param m - middle index
 * @param right - right index
 */
void merge(int a[], int left, int m, int right) {
    int *leftSide = new int[m - left + 1];
    int *rightSide = new int[right - m];
    int lLength, rLength;
    lLength = rLength = 0;
    for (int i = left; i <= m; i++) {
        leftSide[lLength++] = a[i];
    }
    for (int i = m + 1; i <= right; i++) {
        rightSide[rLength++] = a[i];
    }
    int i, j, c;
    i = j = 0;
    c = left;

    while (i < lLength && j < rLength) {
        if (leftSide[i] < rightSide[j]) {
            a[c++] = leftSide[i++];
        } else {
            a[c++] = rightSide[j++];
        }
    }

    while (i < lLength) {
        a[c++] = leftSide[i++];
    }

    while (j < rLength) {
        a[c++] = rightSide[j++];
    }

    delete[] leftSide;
    delete[] rightSide;
}

/**
 * Function to sort a list using merge sort - complexity Theta(nlogn)
 * @param a - list to be sorted
 * @param left - left index
 * @param right - right index
 * @result a permutation of list a such that (a0 <= a1 <=...<= an-1)
 */
void mergeSortAux(int a[], int left, int right) {
    if (left < right) {
        int m = (left + right) / 2;
        mergeSortAux(a, left, m);
        mergeSortAux(a, m + 1, right);
        merge(a, left, m, right);
    }
}

/**
 * Function to sort a list using merge sort - complexity Theta(nlogn)
 * @param a - list to be sorted
 * @param n - length of the list
 * @result a permutation of list a such that (a0 <= a1 <=...<= an-1)
 */
void mergeSort(int a[], int n) {
    mergeSortAux(a, 0, n - 1);
}


/**
 * Function to perform the quicksort partition - Theta(right-left)
 * @param a - array to be partitioned
 * @param left - left index
 * @param right - right index
 * @result p - index in a such that all elements a0..ap-1 <= ap and all elements ap+1..an-1 >= ap
 */
int partition(int a[], int left, int right) {
    int pivot = a[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (a[j] < pivot) {
            i++;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    int tmp = a[i + 1];
    a[i + 1] = a[right];
    a[right] = tmp;

    return i + 1;
}

/**
 * Function to sort a list using quicksort - complexity O(n^2) - avg Theta(nlogn)
 * @param a - list to be sorted
 * @param left - left index
 * @param right - right index
 * @result a permutation of list a such that (a0 <= a1 <=...<= an-1)
 */
void quickSortAux(int a[], int left, int right) {
    if (left < right) {
        int p = partition(a, left, right);
        quickSortAux(a, left, p - 1);
        quickSortAux(a, p + 1, right);
    }
}

/**
 * Function to sort a list using quicksort - complexity O(n^2) - avg Theta(nlogn)
 * @param a - list to be sorted
 * @param n - length of the list
 * @result a permutation of list a such that (a0 <= a1 <=...<= an-1)
 */
void quickSort(int a[], int n) {
    quickSortAux(a, 0, n - 1);
}

int main() {
    int arr1[] = {-1, 0, 9, 0, -2, 1, -100, 909, 32, 3};
    int n = 10;
    quickSort(arr1, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr1[i] << ' ';
    }
    return 0;
}
