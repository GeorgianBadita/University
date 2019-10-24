/*
 *
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

int is_prime(int x){
	if(x < 2){
		return 0;
	}
	if(x == 2){
		return 1;
	}
	if(x % 2 == 0){
		return 0;
	}
	int i;
	for(i = 3; i<=sqrt(x); i+=2){
		if(x % i == 0){
			return 0;
		}
	}
	return 1;
}


void* work(void* id){
	int num = (int)id;
	if(is_prime(num) == 1){
		printf("[Thread %d is prime]\n", num);
	}
	else{
		printf("[Thread %d is not prime]\n", num);
	}
	return NULL;
}

int main(){
	int n;
	printf("Give n:\n");
	scanf("%d", &n);
	pthread_t* t;
	t = (pthread_t*)malloc(n*sizeof(pthread_t));
	printf("Starting work:\n");
	int i;
	for(i = 0; i<n; i++){
		pthread_create(&t[i], NULL, work, (void*)i);
	}

	for(i = 0; i<n; i++){
		pthread_join(t[i], NULL);
	}
	
	free(t);
	return 0;
}
