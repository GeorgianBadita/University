#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

pthread_t *thr;
pthread_barrier_t* bar;
int* a;
int n; //number of elements
int m = 1; //smalles power of 2 >= m
int iter = 0;
int curr_iter = 0;

void* make_add(void *ind){
	int put = (int*)ind;

	for(int e = 0; e < iter - 1; e++){
		if(put % (1 << iter) != 0){
			return NULL;
		}
		a[put*(1<<(e + 1))] += a[put*(1<<(e+1)) + (1<<e)];
		pthread_barrier_wait(&bar[e]);
	}
	return NULL;

}

int main(int argc, char** argv){
	scanf("%d", &n);
	while(1){
		if(m >= n){
			break;
		}
		iter++;
		m *= 2;
	}
	//iter++;
	a = (int*)malloc(m*sizeof(int));
	thr = (pthread_t*)malloc(m*sizeof(pthread_t));
	bar = (pthread_barrier_t*)malloc(iter*sizeof(pthread_barrier_t));	

	for(int i = 0; i<n; i++){
		a[i] = 1;	
	}
	for(int i = n; i<m; i++){
		a[i] = 0;
	}
	for(int i = 0; i<iter - 1; i++){
		pthread_barrier_init(&bar[i], NULL, 1 <<(iter - i - 1));
		//printf("%d\n", 1 << (iter - i - 1));
	}
	
	for(int i = 0; i<m; i++){
		if(i % 2 == 0){
			pthread_create(&thr[i], NULL, make_add, (void*)i);
		}
	}
	
	printf("The sum is %d\n", a[0]);
	for(int i = 0; i<m; i++){
		if(i % 2 == 0){
			pthread_join(thr[i], NULL);
		}
	}

	free(a);
	free(thr);
	free(bar);	
	return 0;
}
