#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#define MAX_LEN 1024

sem_t sem;
pthread_barrier_t bar;
char req[MAX_LEN];


void* worker(void* a){
	int id = (int)a;
	pthread_barrier_wait(&bar);
	while(1){
		sem_wait(&sem);
		if(strstr(req, "STOP") || strstr(req, "stop")){
			kill(getpid(), SIGKILL);
		}	
		if(strlen(req)){
			printf("[Thread no %d] Your request: %s\n",id, req);
			req[0] = 0;
		}
		sem_post(&sem);
	}
	return NULL;
}

int main(){
	int i;
	pthread_t w[10];
	req[0] = 0;
	sem_init(&sem, 0, 1);
	pthread_barrier_init(&bar,NULL, 11);
	for(i = 0; i<10; i++){
		pthread_create(&w[i], NULL, worker, (void*)i);
	}

	pthread_barrier_wait(&bar);
	while(1){
		sem_wait(&sem);
		if(req[0] == 0){
			printf("Give a new request\n");
			fgets(req, MAX_LEN, stdin);
		}
		sem_post(&sem);
	}

	for(int i = 0; i<10; i++){
		pthread_join(w[i], NULL);
	}
	return 0;
}
