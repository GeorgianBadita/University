#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int total_len = 0;


void* count(void* str){
	char* string;
	string =  (char*)str;
	
	pthread_mutex_lock(&mtx);
	total_len += strlen(string);
	pthread_mutex_unlock(&mtx);
	return NULL;
}

int main(int argc, char** argv){
	
	pthread_t* tid;
	tid = (pthread_t*)malloc(sizeof(pthread_t)*argc);
	int i;
	for(i = 0; i<argc; i++){
		pthread_create(&tid[i], NULL, count, (void*)argv[i]);
	}

	for(i = 0; i<argc; i++){
		pthread_join(tid[i], NULL);
	}
	free(tid);
	printf("Total len = %d\n", total_len);
	printf("Program terminated with exit 0\n");
	return 0;
}
