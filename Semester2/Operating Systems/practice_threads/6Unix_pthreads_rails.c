//solution using semaphore

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define N 5
#define M 13
#define SLEEP 4

sem_t sem, mut;

int linie[N], tren[M];
pthread_t tid[M];
time_t start;

void* trece(void* tren){
	int t, l;
	t = *(int*)tren;
	
	sleep(1 + rand()%SLEEP); //inainte de ==> A

	sem_wait(&mut);
	printf("Moment %lu tren %d: ==> A\n", time(NULL)-start, t);
	sem_post(&mut);

	sem_wait(&sem); //In A ocupa linia
	
	sem_wait(&mut);
	for(l = 0; l<N; l++){
		if(linie[l] == -1){
			break;
		}
	}
	linie[l] = t;
	printf("\tMoment %lu tren %d: A ==> B linia %d\n", time(NULL)-start, t, l);

	sem_post(&mut);

	sleep(1 + rand()%SLEEP); //Trece trenul A ===> B

	sem_wait(&mut);

	printf("\tMoment %lu tren %d: B ==> liber linia %d\n", time(NULL)-start, t, l);
	linie[l] = -1;
	sem_post(&mut);

	sem_post(&sem); //In B elibereaza linia
	return NULL;
}

int main(){
	int i;
	sem_init(&sem, 0, N);
	sem_init(&mut, 0, 1);

	for(i = 0; i<N; linie[i] = -1, i++);
	for(i = 0; i<M; tren[i] = i, i++);
	start = time(NULL);

	for(i = 0; i<M; i++){
		pthread_create(&tid[i], NULL, trece, &tren[i]);
	}

	for(i = 0; i<M; i++){
		pthread_join(tid[i], NULL);
	}

	sem_destroy(&sem);
	sem_destroy(&mut);
	return 0;
}
