#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NMAX 1000

typedef struct{
	int* arr;
	int from;
	int to;
}Div;
int n;

void merge(int arr[], int l, int m, int r){
	 int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
	
}

void* merge_sort(void* a){
	Div* c = (Div*)a;
	Div s, d;
	pthread_t ts, td;
	int m;
	if(c -> to > c->from ){
	m = (c->to + c->from)/2;
	s.arr = c->arr;
	s.from = c->from;
	s.to = m;
	pthread_create(&ts, NULL, merge_sort, (void*)&s);
	d.arr = c->arr;
	d.from = m + 1;
	d.to = c->to;
	pthread_create(&td, NULL, merge_sort, (void*)&d);
	merge(c->arr, c->from, m, c->to);

	pthread_join(ts, NULL);
	pthread_join(td, NULL);
	}
	//interclasare
	return NULL;
}

int main(){
	printf("Give the number of elements\n");
	scanf("%d", &n);
	Div div;
	div.arr = (int*)malloc(n*sizeof(int));
	div.from = 0;
	div.to = n - 1;
	for(int i = 0; i<n; i++){
		scanf("%d", &div.arr[i]);
	}

	pthread_t t;
	pthread_create(&t, NULL, merge_sort, (void*)&div); 
	pthread_join(t, NULL);
	printf("Sorted array:\n");

	for(int i = 0; i<n; i++){
		printf("%d ", div.arr[i]);
	}
	return 0;
}
