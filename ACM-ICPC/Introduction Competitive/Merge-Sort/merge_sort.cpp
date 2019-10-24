#include <iostream>
#define MAXCOUNT 1000
using namespace std;

int v[MAXCOUNT];

/**
  Functie pentru interclasarea a doi vectori sortati
  :param: -arr - our array
  :param: l - left index of subarray arr[l...m]
  :param: m - middle index of the subarray
  :param: r - right index of the subarray
*/
void merge(int arr[], int l, int m, int r){
  int totalLength = (r - l + 1)/2 + 1;
  int subarr1[totalLength], subarr2[totalLength];
  int length1 = m - l + 1;
  int length2 = r - m;

  for(int i = 0; i<length1; i++){
    subarr1[i] = arr[l + i];
  }

  for(int i = 0; i<length2; i++){
    subarr2[i] = arr[i + m + 1];
  }

  int i = 0, j = 0, dim = l;
  while(i < length1 && j < length2){
    if(subarr1[i] <= subarr2[j]){
      arr[dim++] = subarr1[i];
      i ++;
    }
    else{
      arr[dim++] = subarr2[j];
      j ++;
    }
  }
  while(i < length1){
    arr[dim++] = subarr1[i];
    i++;
  }

  while(j < length2){
    arr[dim++] = subarr2[j];
    j ++;
  }
}

/**
  Functie pentru sortarea unui vector folosind metoda merge_sort
  :param: arr - vectorul de sortat
  :param: l - indexul de start
  :param: r - indexul de final
*/
void mergeSort(int arr[], int l, int r){
  if(l < r){
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

/**
Functie pentru printarea unui array
:param: arr - vector de numere intregi
:param: n - dimensiunea vectorului
*/
void printArray(int arr[], int n){
  for(int i = 0; i<n; i++){
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

int main(){
  int arr[] = {5, 4, 3, 2, 1};
  mergeSort(arr, 0, 4);
  printArray(arr, 5);
  return 0;
}
