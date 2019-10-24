/*
 * Write a program using pthreads which takes as command line argumnents
 * two numbers, representing the right extremity of an interval 
 * (the left one being 2), and the number of threads to be made
 * The program should output the number of prie numbers in the interval 
 */
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <math.h>

int right_interval, num_th;
int interval = 0;
int prime_num = 0;
int is_prime(int x);

/*
 * Mutex thread
 */
pthread_mutex_t mtx;


//thread function
void* get_primes(void* param){
	int num = (int)param;
	int num_primes = 0;
	for(int i = num*interval + 1; i<=(num + 1)*interval; i++){
			if(i > right_interval){
				break;
			}
			if(is_prime(i) == 1){
				pthread_mutex_lock(&mtx);
				num_primes ++;
				pthread_mutex_unlock(&mtx);
			}
	}
	pthread_mutex_lock(&mtx);
	prime_num += num_primes;
	pthread_mutex_unlock(&mtx);
	return NULL;
}

//function to extract a number from a string
int get_num_str(char* str){
	int num = 0;
	for(int i = 0; i<strlen(str); i++){
		num = num* 10 + (str[i] - '0');
	}
	return num;

}

//function to check if a number is prime
//returns 0 if x is not prime, 1 otherwise
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

	for(int i = 3; i<=sqrt(x); i+=2){
		if(x % i == 0){
			return 0;
		}
	}
	return 1;
}

//main function
int main(int argc, char** argv){	
	if(argc >= 3){	
		right_interval = get_num_str(argv[1]);
		num_th = get_num_str(argv[2]);
	}
	else{
		right_interval = 100000;
		num_th = 10;
	}
	if(right_interval % num_th == 0){
		interval = right_interval / num_th;
	}
	else{
		interval = right_interval / num_th + 1;
	}
	pthread_t t[num_th];
	
	pthread_mutex_init(&mtx, NULL);
	
	for(int i = 0; i<num_th; i++){
		pthread_create(&t[i], NULL, get_primes, (void*)i);
	}
	
	for(int i = 0; i<num_th; i++){
		pthread_join(t[i], NULL);
	}
	
	pthread_mutex_destroy(&mtx);
	printf("Total number of primes: %d\n", prime_num);
	return 0;
}
