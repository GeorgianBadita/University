#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#define FILE_NAME 10
#define N 200

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int global_sum = 0;
int arr[N];

void* count(void* a){
	int ind = (int)a;
	//printf("%d %d\n", N/2*ind, N/2*(ind + 1));
	for(int i = N/2*ind; i < N/2*(ind + 1); i++){
		pthread_mutex_lock(&mtx);
		//printf("%d ", arr[i]);
		global_sum += arr[i];
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}


int main(){

	srand(time(NULL));

	FILE* f = fopen("ana.txt", "r");


	for(int i = 0; i<N; i++){
		fscanf(f, "%d", &arr[i]); 
		printf("%d\n", arr[i]);	
	}

	pthread_t t[2];
	for(int i = 0; i<2; i++){
		pthread_create(&t[i], NULL, count, (void*)i);
	}

	for(int i = 0; i<2; i++){
		pthread_join(t[i], NULL);
	}


	printf("%d\n%d", global_sum, 100*201);
//	fclose(g);
	fclose(f);
	
	return 0;
}
