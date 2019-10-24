#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define S 5
#define C 3
#define CSLEEP 2
#define SSLEEP 3

pthread_t tid[C + S];
int c[C], s[S], nt[C + S];
pthread_mutex_t mutcond, exclusafis;
pthread_cond_t cond;
int cititori;

void afiseaza(){
	int i;
	pthread_mutex_lock(&exclusafis);
	for(i = 0; i<C; i++) {
		printf("C%d_%d\t", i, c[i]);
	}
	for(i = 0; i<S; i++){
		printf("S%d_%d\t", i, s[i]);
	}
	printf("\n");
	fflush(stdout);
	pthread_mutex_unlock(&exclusafis);
}


void* cititor(void* nrc){
	int indc = *(int*)nrc;

	while(1){
		pthread_mutex_lock(&mutcond);
		cititori ++;
		c[indc] = 0; //citeste
		afiseaza();
		pthread_mutex_unlock(&mutcond);
		sleep(1 + rand() % CSLEEP);
		c[indc] = -2; //A citit si doarme
		pthread_mutex_lock(&mutcond);
		cititori --;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutcond);

		sleep(1 + rand() % CSLEEP);
	}
}

void* scriitor(void* nrs){
	int inds = *(int*)nrs;

	while(1){
		s[inds] = -1; //asteapta sa scrie

		pthread_mutex_lock(&mutcond);
		while(cititori != 0){
			pthread_cond_wait(&cond, &mutcond);
		}
		s[inds] = 0; //scrie
		afiseaza();
		sleep(1 + rand() % SSLEEP);
		s[inds] = -2; //a scris si doarme
		pthread_mutex_unlock(&mutcond);
		sleep(1 + rand() % SSLEEP);
	}
}

int main(){
	pthread_mutex_init(&mutcond, NULL);
	pthread_mutex_init(&exclusafis, NULL);
	pthread_cond_init(&cond, NULL);

	int i;
	for(int i = 0; i<C; i++){
		nt[i] = i;
		c[i] = -3; //nu a pornit inca
	}
	
	for(int i = 0; i<S; i++){
		nt[i + C] = i;
		s[i] = -3;
	}

	for(i = 0; i<C; i++){
		pthread_create(&tid[i], NULL, cititor, &nt[i]);
	}

	for(i = C; i<C + S; i++){
		pthread_create(&tid[i], NULL, scriitor, &nt[i]);
	}

	for(int i = 0; i<C + S; i++){
		pthread_join(tid[i], NULL);
	}	

	pthread_mutex_destroy(&mutcond);
	pthread_mutex_destroy(&exclusafis);
	pthread_cond_destroy(&cond);

	return 0;
}
