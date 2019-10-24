#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#define NMAX 2000

int A[NMAX][NMAX];
int B[NMAX][NMAX];
int C[NMAX][NMAX];
int current_num = 1;
int n_threads;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
time_t start;

void* multiply(void* ind){
	int t_num = (int)ind;
	int first_id = t_num;
	//printf("Thread no %d, started multiplying...\n", t_num);
	//pthread_mutex_unlock(&mtx);
	int line = t_num / NMAX; // current thread will calculate
	int col = t_num % NMAX;	//over n_threads again and again
	while(line < NMAX){
		//must calculate the element C[line][col];
		int sum = 0;
		for(int j = 0; j<NMAX; j++){
			sum = sum + A[line][j]*B[j][col];
		}
		C[line][col] = sum;
		t_num += n_threads;
		line = t_num/NMAX;
		col = t_num % NMAX;	
	}
		
	//printf("Thread no %d, stopped..\n", first_id);
	return NULL;
}

int main(){
	start = time(NULL);
	scanf("%d", &n_threads);
	pthread_t* tid;
	tid = (pthread_t*)malloc(n_threads*sizeof(pthread_t));
	int i, j;
	srand(time(NULL)); //create a seed to generate random numbers in matrix
	for(i = 0; i<NMAX; i++){
		for(j = 0; j<NMAX; j++){
			int x = rand() % 10;
			int y = rand() % 10;
			A[i][j] = x;
			B[i][j] = y;
		}
	}
	
/*	for(i = 0; i<NMAX; i++){
		for(j = 0; j<NMAX; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	for(i = 0; i<NMAX; i++){
		for(j = 0; j<NMAX; j++){
			printf("%d ",B[i][j]); 
		}
		printf("\n");
	}
*/
	for(i = 0; i<n_threads; i++){
		pthread_create(&tid[i], NULL, multiply, (void*)i);	
	}	

	for(i = 0; i<n_threads; i++){
		pthread_join(tid[i], NULL);
	}
	
	//printing the result matrix
/*
	for(i = 0; i<NMAX; i++){
		for(j = 0; j<NMAX; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
*/
	printf("Program took %lu\n", time(NULL) - start);
	free(tid);
	return 0;
}
