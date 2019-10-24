#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

pthread_mutex_t a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t b = PTHREAD_MUTEX_INITIALIZER;

int n = 0;

void* fa(void* p){
	pthread_mutex_lock(&a);
	n ++;
	pthread_mutex_unlock(&a);
	return NULL;
}

void* fb(void* p){
	pthread_mutex_lock(&a);
	n ++;
	pthread_mutex_unlock(&a);
	return NULL;
}

int main(){
	int i;

	for(i = 0; i<6; i++){
		if(i % 3 == 1){
			fork();
		}
	}
	printf("here");
	return 0;
}
