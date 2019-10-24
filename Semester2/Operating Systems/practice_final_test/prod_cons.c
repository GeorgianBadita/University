#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>
#define N 15
#define P 5
#define C 5
#define PSLEEP 4
#define CSLEEP 3

pthread_t tid[P+C];
pthread_mutex_t exclusval = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t exclusbuf = PTHREAD_MUTEX_INITIALIZER;
sem_t gol, plin;
int c[C], p[P], nt[P+C], buf[N], val, indPut, indGet;

void* cons(void* nrc){
	int indc = *(int*)nrc;
	while(1){
		c[indc] = -1; //asteapta sa citeasca
		sem_wait(&plin);
		pthread_mutex_lock(&exclusbuf);
		c[indc] = buf[indGet];
		buf[indGet] = 0;
		printf("[In consumer %d]: ", indc);
		for(int i = 0; i<N; i++){
			printf("%d ", buf[i]);
		}
		printf("\n");
		indGet = (1 + indGet) % N;
		c[indc] = 0; //elibereaza si doarme
		pthread_mutex_unlock(&exclusbuf);
		sem_post(&gol);

		sleep(1 + rand() % CSLEEP);
		
	}
	return NULL;
}

void* prod(void* nrp){
	int indp = *(int*)nrp;
	while(1){
		pthread_mutex_lock(&exclusval);
		val ++;
		p[indp] = -val; //asteapta sa depuna
		pthread_mutex_unlock(&exclusval);
		
		sem_wait(&gol);
		pthread_mutex_lock(&exclusbuf);
		//pun uin buffer
		buf[indPut] = -p[indp];
		p[indp] = -p[indp];

		printf("[In producer: %d]: ", indp);
		for(int i = 0; i<N; i++){
			printf("%d ", buf[i]);
		}
		printf("\n");
		p[indp] = 0; //a scris si doarme
		indPut = (1 + indPut) % N;
		pthread_mutex_unlock(&exclusbuf);
		sem_post(&plin);
		sleep(1 + rand() % PSLEEP);
		
	}
	return NULL;
}


int main(){
	sem_init(&gol, 0, N);
	sem_init(&plin, 0, 0);
	int i;
	indPut = 0;
	indGet = 0;
	val = 0;
	
	for(i = 0; i<N; i++){
		buf[i] = 0;
	}	

	for(i = 0; i<P; i++){
		p[i] = 0;
		nt[i] = i;
	}	
	for(i = 0; i<C; i++){
		c[i] = 0;
		nt[i + P] = i;
	}

	for(i = 0; i<P; i++){
		pthread_create(&tid[i], NULL, prod, &nt[i]);
	}
	
	for(i = P; i< P+C; i++){
		pthread_create(&tid[i], NULL, cons, &nt[i]);
	}

	for(i = 0; i<P+C; i++){
		pthread_join(tid[i], NULL);
	}

	sem_destroy(&gol);
	sem_destroy(&plin);
	return 0;
}
