#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define NUM 100

void *myThreadFun(void *vargp){
	int id = (int*)vargp;
	printf("Printing %d  from Thread\n", id);
	return NULL;
}



int main(){
	int i = 0;
	pthread_t my_thread[NUM];
	printf("Before Thread\n");
	for(i = 0; i<NUM; i++){
		pthread_create(&my_thread[i], NULL, myThreadFun, (void*)i);
	}	
	for(i = 0; i<NUM; i++){
		pthread_join(my_thread[i], NULL);
	}
	printf("After Thread\n");
	return 0;
}
