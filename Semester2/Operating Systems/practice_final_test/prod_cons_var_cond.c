#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#define N 15
#define P 5
#define C 2
#define PSLEEP 4
#define CSLEEP 3

pthread_t tid[P+C];
pthread_mutex_t exclusval = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t exclusbuf = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutgol = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutplin = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t plin, gol;
int buf[N], c[C], p[P], nt[P+C], val, indPut, indGet, goale;


void* prod(void* nrp){
	int indp = *(int*)nrp;
	while(1){
		pthread_mutex_lock(&exclusval); //increment value
		val ++;
		p[indp] = -val; //waits to put the value in buff
		pthread_mutex_unlock(&exclusval);
	
		pthread_mutex_lock(&mutgol);	

		while(goale == 0){
			pthread_cond_wait(&gol, &mutgol);
		}
		
		pthread_mutex_unlock(&mutgol);

		pthread_mutex_lock(&exclusbuf);
		goale --;
		buf[indPut] = -p[indp];
		//should print here
		printf("[Producer %d]: ", indp);
		for(int i = 0; i<N; i++){
			printf("%d ", buf[i]);
		}
		printf("\n");
		p[indp] = 0;
		indPut = (1 + indPut) % N;
		pthread_mutex_unlock(&exclusbuf);

		pthread_mutex_lock(&mutplin);
		pthread_cond_signal(&plin);
		pthread_mutex_unlock(&mutplin);
		
		sleep(1 + rand() % PSLEEP);

	}
	return NULL;
}

void* cons(void* nrc){
	int indc = *(int*)nrc;
	while(1){
		c[indc] = -1; //waits to read
		
		pthread_mutex_lock(&mutplin);
		while(goale == N){
			pthread_cond_wait(&plin, &mutplin);
		}

		pthread_mutex_unlock(&mutplin);

		pthread_mutex_lock(&exclusbuf);
		goale ++;
		c[indc] = buf[indGet];
		buf[indGet] = 0;
		//print
		printf("[Consumer no %d]: ", indc);
		for(int i = 0; i<N; i++){
			printf("%d ", buf[i]);
		}
		printf("\n");
		c[indc] = 0;
		indGet  = (1 + indGet) % N;

		pthread_mutex_unlock(&exclusbuf);

		pthread_mutex_lock(&mutgol);
		pthread_cond_signal(&gol);
		pthread_mutex_unlock(&mutgol);
		sleep(1 + rand() % CSLEEP);
	}
	return NULL;
}

int main(){
	pthread_cond_init(&plin, NULL);
	pthread_cond_init(&gol, NULL);
	int i;
	val = 0;
	indPut = 0;
	indGet = 0;
	goale = N;

	for(i = 0; i<N; i++){
		buf[i] = 0;
	}
	for(i = 0; i<P; i++){
		nt[i] = i;
		p[i] = 0;
	}

	for(i = 0; i<C; i++){
		nt[i + P] = i;
		c[i] = 0;
	}

	for(i = 0; i<P; i++){
		pthread_create(&tid[i], NULL, prod, &nt[i]);
	}
	
	for(i = P; i<P+C; i++){
		pthread_create(&tid[i], NULL, cons, &nt[i]);
	}

	for(i = 0; i<P+C; i++){
		pthread_join(tid[i], NULL);
	}

	pthread_cond_destroy(&plin);
	pthread_cond_destroy(&gol);
	return 0;
}
