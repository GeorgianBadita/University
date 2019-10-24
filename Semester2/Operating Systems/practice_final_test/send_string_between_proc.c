#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(){
	char s[] = "I'mastring\0";
	int a2b[2], b2a[2];
	pipe(a2b);
	pipe(b2a);	


	if(fork() == 0){
		close(b2a[1]); close(a2b[0]);
		
		int k = strlen(s) + 1;
		write(a2b[1], &k, sizeof(int));
		write(a2b[1], s, k*sizeof(char));
		while(1){
			int n;
			read(b2a[0], &n, sizeof(int));
			if(n <= 0 || strlen(s) == 0){
				break;
			}
			read(b2a[0], s, n*sizeof(char));
			printf("A: %s\n", s);
			s[strlen(s) - 1] = '\0';
			n = strlen(s) + 1;
			write(a2b[1], &n, sizeof(int));
			write(a2b[1], s, sizeof(char)*n);
		}
		close(b2a[0]); close(a2b[1]);
		exit(0);
	}

	if(fork() == 0){
			
		close(b2a[0]); close(a2b[1]);
		while(1){
			int n;
			read(a2b[0], &n, sizeof(int));
			read(a2b[0], s, n*sizeof(char));
			if(n <= 0 || strlen(s) == 0){
				break;
			}
			printf("B: %s\n", s);
			s[strlen(s) - 1] = '\0';
			n = strlen(s) + 1;
			write(b2a[1], &n, sizeof(int));
			write(b2a[1], s, n*sizeof(char));
			
		}
		close(b2a[1]); close(a2b[0]);
		exit(0);
	}

	wait(0);
	wait(0);
	close(a2b[0]); close(a2b[1]);
	close(b2a[0]); close(b2a[1]);
	return 0;
}
