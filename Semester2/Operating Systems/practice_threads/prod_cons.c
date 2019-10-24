#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define PSLEEP 5
#define CSLEEP 4
#define C 5
#define P 10

pthread_mutex_t read_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t write_mtx = PTHREAD_MUTEX_INITIALIZER;
sem_t gol, plin;

int buff[N], pr[P], co[C];
int value = 0;
int c_ind = 0;
int p_ind = 0;

void* produce(void* a){
	int indp = (int) a;

	for( ; ; ){
		pthread_mutex_lock(&write_mtx);
		value++;
		pr[indp] = -value; //producer waits to writei
		pthread_mutex_unlock(&write_mtx);
	
		sem_wait(&gol);
		pthread_mutex_lock(&write_mtx);
		buff[p_ind] = -pr[indp]; 
		printf("[Producer no %d], produced value %d\n", indp, -pr[indp]);
		p_ind = (p_ind + 1) % N;
		pthread_mutex_unlock(&write_mtx);

		sem_post(&plin);
		sleep(1 + rand() % PSLEEP);
		
	}	
	return NULL;
}

void* consume(void*a){
	int indc = (int)a;

	for(; ;){
		co[indc] = -1; //wait to read form buffer
		sem_wait(&plin);
		pthread_mutex_lock(&read_mtx);
		
		co[indc] = buff[c_ind];
		printf("[Consumer no %d] Consumed value %d\n", indc, co[indc]);

		buff[c_ind] = 0; //free buffer space
		co[indc] = 0; //consumer ended and must sleep
		
		c_ind = (c_ind + 1) % N;		
	
		pthread_mutex_unlock(&read_mtx);
		sem_post(&gol);
		sleep(1 + rand() % CSLEEP);

	}	
	return NULL;
}

int main(){
	srand(time(NULL));
	int i;
	sem_init(&gol, 0, N);
	sem_init(&plin, 0, 0);

	pthread_t prod[P];
	pthread_t cons[C];

	for(i = 0; i<P; i++){
		pthread_create(&prod[i], NULL, produce, (void*)i);
	}	
	
	for(i = 0; i<C; i++){
		pthread_create(&cons[i], NULL, consume, (void*)i);
	}

	for(i = 0; i<P; i++){
		pthread_join(prod[i], NULL);
	}

	for(i = 0; i<C; i++){
		pthread_join(cons[i], NULL);
	}	

	return 0;
}
