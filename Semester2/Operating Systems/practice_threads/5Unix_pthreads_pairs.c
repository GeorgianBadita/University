#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#define MAX_TH 1000
#define MAX_P 1000

pthread_t t[MAX_TH];
pthread_mutex_t mtx;
int num_even_sum = 0;
int num_odd_sum = 0;
int zeros = 0;

typedef struct{
	int x, y;
}Pair;

 Pair pair[MAX_P];

int get_num_str(char* str){
	int num = 0;
	for(int i = 0; i<strlen(str); i++){
		num = num*10 + (str[i] - '0');
	}
	return num;
}

void* make_pair(void* my_pair){
	int num1 = ((Pair*)my_pair)->x;
	int num2 = ((Pair*)my_pair)->y;
	printf("Thread %ld ---> %d, %d\n", pthread_self(), num1, num2);
	if((num1 + num2)%2 == 0){
		pthread_mutex_lock(&mtx);
		num_even_sum++;
		pthread_mutex_unlock(&mtx);
	}
	else if((num1 + num2) %2 == 1){
		pthread_mutex_lock(&mtx);
		num_odd_sum ++;
		pthread_mutex_unlock(&mtx);
	}
	if(num1*num2 == 0){
		pthread_mutex_lock(&mtx);
		zeros++;
		pthread_mutex_unlock(&mtx);
	}

	printf("Thread %ld ---> %d, %d FINISHED\n", pthread_self(), num1, num2);
	return NULL;
}

int main(int argc, char** argv){
	pthread_mutex_init(&mtx, NULL);
	int i;

	for(i = 1; i<argc - 1; i++){
		pair[i].x = get_num_str(argv[i]);
		pair[i].y = get_num_str(argv[i + 1]);
		pthread_create(&t[i], NULL, make_pair, (void*)&pair[i]);
		printf("Created thread %ld\n", t[i]);	
 	}
	
	for(i = 1; i<argc - 1; i++){
		pthread_join(t[i], NULL);
	}	
	printf("All threads done!\n");
	printf("Even sum: %d\nOdd sum: %d\nZeros: %d\n", num_even_sum, num_odd_sum, zeros);
	pthread_mutex_destroy(&mtx);
	return 0;
}
