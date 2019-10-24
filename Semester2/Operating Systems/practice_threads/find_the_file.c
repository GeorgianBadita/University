#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#define NMAX 100
#define BUFF_SIZE 1024

time_t start;
typedef struct{
	char file[BUFF_SIZE];
	int ind;
}Pair;

Pair pair[NMAX];

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


void* count(void* my_pair){	
	time_t start_time = time(NULL);
	char f_name[BUFF_SIZE];
	int id;
	strcpy(f_name, ((Pair*)my_pair)->file);
	id = ((Pair*)my_pair)->ind;
	int fd = open(f_name, O_RDONLY);
	pthread_mutex_lock(&mtx);
	int num_the = 0;
	pthread_mutex_unlock(&mtx);
	
	while(1){
		char line[BUFF_SIZE];
		int val = read(fd, line, BUFF_SIZE*sizeof(char));
		int i;
		for(i = 0; i<strlen(line) - 2; i++){
			if(line[i] == 't' && line[i + 1] == 'h' && line[i + 2] == 'e'){ //strncpy(str, line + i, n) strcmp(str, word) == 0
					pthread_mutex_lock(&mtx);
					num_the ++;
					pthread_mutex_unlock(&mtx);
			}
		}		
		if(val <= 0){
			break;
		}
	}	
	pthread_mutex_lock(&mtx);
	printf("[Thread %d] found %d in %lu time\n", id, num_the, time(NULL) - start_time);
	pthread_mutex_unlock(&mtx);
	return NULL;
}

int main(int argc, char** argv){
	start = time(NULL);
	pthread_t tid[NMAX];
	int i;

	for(i = 1; i<argc; i++){
		strcpy(pair[i].file, argv[i]);
		pair[i].ind = i;
		pthread_create(&tid[i], NULL, count, (void*)&pair[i]);
	}

	for(i = 1; i<argc; i++){
		pthread_join(tid[i], NULL);
	}	

	printf("Program took %lu seconds\n", time(NULL) - start);
	return 0;
}	
