#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_BUF 1024
#define MAX_FILE 10
#define INF 1e9
pthread_t tid[MAX_FILE];
pthread_mutex_t mtx;
time_t start;
int best1, best2, best3;
int t1, t2, t3;
typedef struct{
	char file[MAX_BUF];
	int id;
}Pair;

Pair pair[MAX_FILE];

void* count(void* my_pair){
	char file[MAX_BUF];
	strcpy(file, ((Pair*)my_pair)->file);
	int id = ((Pair*)my_pair)->id;
	time_t start_time = time(NULL);
	int f  = open(file, O_RDONLY);
	int num_the = 0;
	for( ; ; ){
		char linie[MAX_BUF + 1];
		if(read(f, linie, MAX_BUF - 1) <= 0){
			break;
		}
		linie[MAX_BUF] = '\0';
		for(int i = 0; i<strlen(linie) - 2; i++){
			pthread_mutex_lock(&mtx);
//			printf("%c%c%c\n", linie[i], linie[i + 1], linie[i + 2]);
			if(linie[i] == 't' && linie[i + 1] == 'h' && linie[i + 2] == 'e'){
				num_the ++;
			}
			pthread_mutex_unlock(&mtx);
		}
	}
	time_t curr_time = time(NULL) - start_time;
	if(curr_time < best1){
		pthread_mutex_lock(&mtx);
		best3 = best2;
		t3 = t2;
		best2 = best1;
		t2 = t1;
		best1 = curr_time;
		t1 = id;
		pthread_mutex_unlock(&mtx);
	}else if(curr_time < best2){
		pthread_mutex_lock(&mtx);
		best3 = best2;
		t3 = t2;
		best2 = curr_time;
		t2 = id;
		pthread_mutex_unlock(&mtx);
	}else if(curr_time < best3){
		pthread_mutex_lock(&mtx);
		best3 = curr_time;
		t3 = id;
		pthread_mutex_unlock(&mtx);
	}
	pthread_mutex_lock(&mtx);
	printf("Thread %d found %d 'the' in file %s, and it took: %lu\n", id, num_the, file, curr_time); 
	pthread_mutex_unlock(&mtx);
	return NULL;
}

int main(int argc, char** argv){
	start = time(NULL);
	pthread_mutex_init(&mtx, NULL);
	best1 = best2 = best3 = INF;
	
	for(int i = 0; i< argc - 1; pair[i].id = i,  i++);

	for(int i = 0; i<argc - 1; i++){
		strcpy(pair[i].file, argv[i + 1]);
		pthread_create(&tid[i], NULL, count, (void*)&pair[i]);
	}
	
	for(int i = 0; i<argc - 1; i++){
		pthread_join(tid[i], NULL);
	}
	printf("Program took: %lu\n", time(NULL) - start);	
	printf("Best threads are: %d, %d, %d\n", t1, t2, t3);
	pthread_mutex_destroy(&mtx); 
	return 0;
}
