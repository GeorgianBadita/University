// Implement a C program that creates two child processes. The
// first child process reads strings from the console until it gets
// the string STOP, and sends them through pipe to the other child
// process which prints them out.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	char s[1024];
	int p[2];	
	pipe(p);
	if(fork() == 0){
		close(p[0]);
		while(fgets(s, 1024, stdin) != NULL && strcmp(s, "STOP\n") != 0){
			int k = strlen(s) + 1;
			write(p[1], &k, sizeof(int));
			write(p[1], s, k);
		}
		close(p[1]);
		exit(0);
	}
	
	if(fork() == 0){
		close(p[1]);
		
		while(1){
			int num;
			int val = read(p[0], &num, sizeof(int));
			if(val <= 0){
				break;
			}
			read(p[0], s, num);
			printf("%s\n", s);
		}
		close(p[0]);
		exit(0);
	}

	close(p[1]);
	close(p[0]);
	wait(0);
	return 0;
}
