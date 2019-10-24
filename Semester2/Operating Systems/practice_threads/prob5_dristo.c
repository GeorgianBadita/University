#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

typedef struct{
	int first;
	int second;
	int ind;
}Pair;

Pair pair;
int has_ended = 0, n = 0;

void* count(void* my_pair){
	int first = ((Pair*)my_pair)->first;
	int second =((Pair*)my_pair)->second;
	int id = ((Pair*)my_pair)->ind;
	printf("On thread %d start the sum was: %d, first was %d, second was %d\n", id, n, first, second);
	pthread_mutex_lock(&mtx);
	n += first;
	n += second;
	pthread_mutex_unlock(&mtx);
	printf("On thread %d final the sum was: %d, first was %d, second was %d\n", id, n, first, second);
	return NULL;
}


int main(){
	pthread_t* tid;
	int size = 1;
	tid = (pthread_t*)malloc(size*sizeof(pthread_t));
	int i = 0;
	while(has_ended == 0){
		//srand(time(NULL));
		int r = rand() % 5;
		pair.first = r;
		r = rand()%5;
		pair.second = r;
		pair.ind = i;
		pthread_create(&tid[i], NULL, count, (void*)&pair);
		i++;
		if(n >= 20){
			has_ended = 1;
		}
		//n += 10;
		size ++;
		tid = (pthread_t*)realloc(tid, size*sizeof(pthread_t));		
	}
	int j;
	for(j = 0; j<i; j++){
		pthread_join(tid[i], NULL);
	}	
	free(tid);
	return 0;
}
