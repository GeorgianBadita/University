/*
 * Implement in C a parent process which has 3 child processes
 * A, B, C. A sends a value of 5 to B and B decrements it and sends the
 * value to C, C makes the same thing but sends the value to A, and so on
 * The processes ends when the value is <= 0
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int a2b[2], b2c[2], c2a[2], n;
	pipe(a2b);
	pipe(b2c);
	pipe(c2a);


	if(fork() == 0){
		close(b2c[0]); close(b2c[1]);
		close(a2b[0]); close(c2a[1]);

	    n = 5;
		write(a2b[1], &n, sizeof(int));		
		while(n >=0){
			read(c2a[0], &n, sizeof(int));
			printf("A : %d\n", n);
			n --;
			write(a2b[1], &n, sizeof(int));
		}	
	
		close(a2b[1]); close(c2a[0]);
		exit(0);
	}
	
	if(fork() == 0){
		close(a2b[1]); close(b2c[0]);
		close(c2a[0]); close(c2a[1]);

		while(n >= 0){
			read(a2b[0], &n, sizeof(int));
			printf("B : %d\n", n);
			n --;
			write(b2c[1], &n, sizeof(int));
		}
		close(a2b[0]); close(b2c[1]);
		exit(0);
	}

	if(fork() == 0){
		close(a2b[0]); close(a2b[1]);
		close(b2c[1]); close(c2a[0]);
		
		while(n >= 0){
			read(b2c[0], &n, sizeof(int));
			printf("C : %d\n", n);
			n --;
			write(c2a[1], &n, sizeof(int));
		}

		close(b2c[0]); close(c2a[1]);
		exit(0);
	}	

	close(a2b[0]); close(a2b[1]);
	close(b2c[0]); close(b2c[1]);
	close(c2a[0]); close(c2a[1]);
	wait(0); wait(0); wait(0);
	return 0;
}
