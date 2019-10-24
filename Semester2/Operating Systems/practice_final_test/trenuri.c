#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#define SLEEP 4

int N, M;
pthread_t* tid;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond;
int *lin, *tren;
int libere;

void* trece(void* a){
	int ind = *(int*)a;
	pthread_mutex_lock(&mtx);
	
	while(libere == 0){
		pthread_cond_wait(&cond, &mtx);
	}
	libere --;
	int l;
	for(l = 0; l<N; l++){
		if(lin[l] == -1){
			break;
		}
	}
	lin[l] = ind;
	printf("[Tren no %d] : ", ind);
	for(int k = 0; k<N; k++){
		printf("%d ", lin[k]);
	}
	printf("\n");
	pthread_mutex_unlock(&mtx);

	sleep(1 + rand() % SLEEP);

	pthread_mutex_lock(&mtx);
	lin[l] = -1; //eliberez linia
	libere++;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mtx);
	
	return NULL;
}


int main(){
	pthread_cond_init(&cond, NULL);
	printf("Dati numarul de linii N: \n");
	scanf("%d", &N);
	printf("Dati numarul de trenuri M > N: \n");
	scanf("%d", &M);
	tid = (pthread_t*)malloc(M*sizeof(pthread_t));
	lin = (int*)malloc(N*sizeof(int));
	tren = (int*)malloc(M*sizeof(int));	
	libere = N;	


	for(int i = 0; i<N; i++){
		lin[i] = -1;
	}
	for(int i = 0; i<M; i++){
		tren[i] = i;
		pthread_create(&tid[i], NULL, trece, &tren[i]);
	}

	for(int i = 0; i<M; i++){
		pthread_join(tid[i], NULL);
	}
	
	pthread_cond_destroy(&cond);
	free(lin);
	free(tren);
	free(tid);
	return 0;
}
