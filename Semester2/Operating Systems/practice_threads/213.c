#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#define MAX_BUFF 1024

char str[MAX_BUFF];
int total_sum = 0;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t mtx1 = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
	char arg[MAX_BUFF];
	int id;
}Pair;

Pair pair[MAX_BUFF];

void* add_to_var(void* my_str){
	char* string = (char*)my_str;
	pthread_mutex_lock(&mtx);
	int to_add = 0;
	for(int i = 0; i<strlen(string); i++){
		if(string[i] >= '0' && string[i] <= '9'){
			to_add = to_add*10 + (string[i] - '0');
		}
	}
	total_sum += to_add;
	printf("Child thread 1 added %d to global variable, now it's value is: %d\n", to_add, total_sum);
	pthread_mutex_unlock(&mtx);
	return NULL;
}

void* sub_from_var(void* my_str){
	char* string = (char*)my_str;
	pthread_mutex_lock(&mtx);
	int to_sub = 0;
	for(int i = 0; i<strlen(string); i++){
		if(string[i] >= '0' && string[i] <= '9'){
			to_sub ++;
		}
	}
	total_sum -= to_sub;
	printf("Child thread 2 substracted %d from global variable, now it's value is: %d\n", to_sub, total_sum);
	pthread_mutex_unlock(&mtx);
	return NULL;
}

void* function(void* my_pair){
	char str[MAX_BUFF];
	strcpy(str, ((Pair*)my_pair)->arg);
	int id = ((Pair*)my_pair)->id;
	int i, has_dig = 0;

	printf("When enetered in father thread %d, global value was %d, string was %s\n", id, total_sum, str);
	for(i = 0; i<strlen(str); i++){
		if(str[i] >= '0' && str[i] <= '9'){
			pthread_t t[2];
			pthread_create(&t[0], NULL, add_to_var, (void*)str);
			pthread_create(&t[1], NULL, sub_from_var, (void*)str);
			pthread_join(t[0], NULL);
			pthread_join(t[1], NULL);
			has_dig = 1;
			break;
		}
	}
	if(has_dig == 0){
		int num = rand() % 20;
		sleep(3);
		total_sum -= num;
		printf("Father thread %d substracted %d from global variable, now it's value is: %d\n", id, num, total_sum);
		
	}
	printf("When father thread %d terminated, global variable was %d\n", id, total_sum);
	return NULL;
}


int main(int argc, char** argv){
	pthread_t* tid;

	tid = (pthread_t*)malloc(argc*sizeof(pthread_t));
	int num = 0;
	char to_read[MAX_BUFF];
	while(strcmp(fgets(to_read, MAX_BUFF, stdin), "STOP\n") != 0){
		strcpy(pair[num].arg, to_read);
		pair[num].id = num;
		pthread_create(&tid[num], NULL, function, (void*)&pair[num]);
		num++;
	}
/*	
	for(int i = 0; i<argc; i++){
		strcpy(pair[i].arg, argv[i]);
		pair[i].id = i;
		pthread_create(&tid[i], NULL, function, (void*)&pair[i]);
	}

	for(int i = 0; i<argc; i++){
		pthread_join(tid[i], NULL);
	}
	*/
	for(int i = 0; i<num; i++){
		pthread_join(tid[i], NULL);
	}
	free(tid);
	return 0;
}

