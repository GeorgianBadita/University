#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

int a[1024];
pthread_barrier_t bar[9];

void* f(void* a){
	int k = (int)a;
	int e;
	for(e = 0; e <9; e++){
		if(k % (1<<e) != 0){
			return NULL;
		}
		a[k*(1<<(e+1))] += a[k*(1<<(e+1))+ 1<<e];
		pthread_barrier_wait(&bar[e]);
	}
	return NULL;
}

int main(){
	pthread_t t[512];
	int i;
	for(i = 0; i<9; i++){
		pthread_barrier_int(&bar[i], NULL, 1 << (9-i));
	}

	for(i = 0; i<1024; i++){
		a[i] = i;
	}

	for(i = 0; i<512; i++){
		pthread_create(&t[i], NULL, f, (void*)i);
	}
	
	for(i = 0; i<512; i++){
		pthread_join(t[i], NULL);
	}
	printf("%d", a[0]);
	return 0;
}
