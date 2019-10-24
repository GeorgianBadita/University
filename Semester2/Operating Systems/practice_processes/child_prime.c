/*
 * Write a parent/child programs where the child checks if a number is
 * prime, parent prints prime numbers from 2..N, N - from stdin
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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

int main(){
	int a2b[2], b2a[2];
	pipe(a2b);
	pipe(b2a);
	int i = 2, n;
	scanf("%d", &n);
	while(i <= n){
		write(a2b[1], &i, sizeof(int));
		i++;
	}
	
	if(fork() == 0){
	    close(b2a[0]); close(a2b[1]);
		while(1){
			int num;
			int val = read(a2b[0], &num, sizeof(int));
			printf("%d\n", num);
			if(is_prime(num) == 1){
				write(b2a[1], &num, sizeof(int));
			}
		}
		close(b2a[1]);
		close(a2b[0]);
		exit(0);
	}
	
	close(a2b[1]); close(a2b[0]);
	close(b2a[0]); close(b2a[1]);
	wait(0);
	return 0;
}






