#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <math.h>
#define DEFAULT_VAL 10

int get_num(char* str){
	int num = 0;
	for(int i = 0; i<strlen(str); i++){
		num = num*10 + (str[i] - '0');
	}
	return num;
}

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
	for(i = 3; i<=sqrt((double)x); i+=2){
		if(x % i == 0){
			return 0;
		}
	}
	return 1;
}

int main(int argc, char** argv){
	int num_proc = 10;
	int total_prime = 0;
	int p[2];
	pipe(p);
	
	if(argc > 1){
		num_proc = get_num(argv[1]);
	}
	
	int range=10000000/num_proc;
	
	for(int i = 0; i<num_proc; i++){
		if(fork() == 0){
			close(p[0]);
			int num_prime = 0;
			//printf("%d %d\n", i*range + 1, i*range + range);
			for(int j = i*range + 1; j <= i*range+range; j++){
				if(is_prime(j)){
					num_prime++;
				}
			}
			write(p[1], &num_prime, sizeof(int));
			close(p[1]);
			exit(0);
		}				
	}

	for(int i = 0; i<num_proc; i++){
		int num;
		read(p[0], &num, sizeof(int));
		total_prime += num;
	}

	for(int i = 0; i<num_proc; i++){
		wait(0);
	}
	close(p[0]);
	close(p[1]);
	
	printf("Total prime_numbers: %d\n", total_prime);
	
	return 0;
}	
