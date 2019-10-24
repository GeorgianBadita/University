#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define P 12
#define C 1
#define PSLEEP 5
#define CSLEEP 4
int buf[N], p[P], c[C], nt[P+C];
pthread_t tid[P + C];
int indPut, indGet, val;
sem_t exclusBuf, exclusVal, gol, plin;

void afiseaza(){
	int i;
	for(i = 0; i<P; i++){
		printf("P %d_%d\t", i, p[i]);
	}

	for(i = 0; i<C; i++){
		printf("C %d_%d\t", i, c[i]);
	}
	
	printf("B:\n");
	for(i = 0; i<N; i++){
		if(buf[i] != 0){
			printf("%d", buf[i]);
		}
		printf("\n");
		fflush(stdout);
	}
}

//rutina unui thread producator

void* producator(void* nrp){
	int indp = *(int*)nrp;
	for( ; ; ){
		sem_wait(&exclusVal);
		val ++;
		p[indp] = -val; //asteapta sa depua val in buf
		sem_post(&exclusVal);

		sem_wait(&gol);
		sem_wait(&exclusBuf);

		buf[indPut] = -p[indp]; //A depus val in buf
		p[indp] = -p[indp];
		afiseaza();
		p[indp] = 0; //Elibereaa buff si adoarme

		indPut = (indPut + 1)% N;
		sem_post(&exclusBuf);
		sem_post(&plin);

		sleep(1 + rand() % PSLEEP);
	}
}

//rutina unui thread consumator
void* consumator(void* nrc){
	int indc = *(int*)nrc;
	
	for( ; ; ) {
		c[indc] = -1;
		//asteapta sa citeasca din bug
		sem_wait(&plin);
		sem_wait(&exclusBuf);
		c[indc] = buf[indGet]; //scoate valoarea din bug
		buf[indGet] = 0; //elibereaza locul idn buf
		afiseaza();
		c[indc] = 0; //elibereaza valoarea
		sem_post(&exclusBuf);
		sem_post(&gol);
		indGet = (indGet + 1) % N;
		sleep(1 + rand() % CSLEEP);
	}
}

int main(){
	sem_init(&exclusBuf, 0, 1);
	sem_init(&exclusVal, 0, 1);
	sem_init(&gol, 0, N);
	sem_init(&plin, 0, 0);
	int i;
	val = 0;
	indPut = 0;
	indGet = 0;
	for(i = 0; i<N; buf[i] = 0, i++);
	for(i = 0; i<P; p[i] = 0, nt[i] = i, i++);
	for(i = 0; i < C; c[i] = 0, nt[i+P] = i, i++);
	
	for(i = 0; i<P; i++){
		pthread_create(&tid[i], NULL, producator, &nt[i]);
	}
	
	for(i = P; i<P + C; i++){
		pthread_create(&tid[i], NULL, consumator, &nt[i]);
	}

	for(i = 0; i<P+C; i++){
		pthread_join(tid[i], NULL);
	}

	sem_destroy(&exclusBuf);
	sem_destroy(&exclusVal);
	sem_destroy(&gol);
	sem_destroy(&plin);
	return 0;
}
