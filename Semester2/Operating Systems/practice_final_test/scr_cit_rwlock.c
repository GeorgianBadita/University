#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define C 7
#define S 5
#define CSLEEP 2
#define SSLEEP 3

pthread_t tid[C+S];
int c[C], s[S], nt[C+S];
pthread_rwlock_t rwlock;
pthread_mutex_t exclusafis = PTHREAD_MUTEX_INITIALIZER;

void afiseaza(){
	int i;
	pthread_mutex_lock(&exclusafis);
	for(i = 0; i<C; i++){
		printf("C %d_%d\t", i, c[i]);
	}

	for(i = 0; i<S; i++){
		printf("S %d_%d\t", i, s[i]);
	}
	printf("\n");
	fflush(stdout);
	pthread_mutex_unlock(&exclusafis);
}

void* cititor(void* nrc){
	int indc = *(int*)nrc;
	while(1){
		c[indc] = -1;
		pthread_rwlock_rdlock(&rwlock);
		c[indc] = 0; //citeste
		afiseaza();
		
		sleep(1 + rand() % CSLEEP);
		c[indc] = -2;
		pthread_rwlock_unlock(&rwlock);
		
		sleep(1 + rand() % CSLEEP);
	}	
}

void* scriitor(void* nrs){
	int inds = *(int*)nrs;
	while(1){
		s[inds] = -1;
	//asteapta sa scrie
		pthread_rwlock_wrlock(&rwlock);
		s[inds] = 0; //scrie
		afiseaza();
		s[inds] = -2; //a scris si doarme
		sleep(1 + rand() % SSLEEP);
		pthread_rwlock_unlock(&rwlock);

		
		sleep(1 + rand() % SSLEEP);
	}
}


int main(){
	pthread_rwlock_init(&rwlock, NULL);
	int i;
	for(i = 0; i<C; i++){
		c[i] = -3; nt[i] = i;
	}
	for(i = 0; i<S; i++){
		s[i] = -3; nt[i + C] = i;
	}

	for(i = 0; i<C;i ++){
		pthread_create(&tid[i], NULL, cititor, &nt[i]);
	}
	for(i = C; i < C+S; i++){
		pthread_create(&tid[i], NULL, scriitor, &nt[i]);
	}
	for(i = 0; i<C+S; i++){
		pthread_join(tid[i], NULL);
	}

	pthread_rwlock_destroy(&rwlock);
	return 0;
}
