#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

int num_p;
pthread_mutex_t *mtx;


void* eat_think(void* a){
	int ind = (int)a;
	
	while(1){
		printf("[Philosopher no %d thinking...]\n", ind);
		sleep(1);
   		int first = ind;
		int second = (ind + 1) % num_p;
		if(first > second){
			int aux = first;
			first = second;
			second = aux;
		}
		pthread_mutex_lock(&mtx[first]);
		pthread_mutex_lock(&mtx[second]);
		printf("[Philosopher no %d is eating...]\n", ind);
		sleep(1);
		pthread_mutex_unlock(&mtx[second]);
		pthread_mutex_unlock(&mtx[first]);
	}	
	return NULL;
}


int main(){
	int i;
	printf("Give the number of philosphers: ");
	scanf("%d", &num_p);
	mtx = (pthread_mutex_t*)malloc((num_p+1)*sizeof(pthread_mutex_t));
	pthread_t* pid;
	pid = (pthread_t*)malloc((num_p+1)*sizeof(pthread_t));

	for(i = 0; i<num_p; i++){
		pthread_mutex_init(&mtx[i], NULL);
	}	

	for(i = 0; i<num_p; i++){
		pthread_create(&pid[i], NULL, eat_think, (void*)i);
	}
	
	for(i = 0; i<num_p; i++){
		pthread_join(pid[i], NULL);
	}

	free(mtx);
	free(pid);
	return 0;
}
