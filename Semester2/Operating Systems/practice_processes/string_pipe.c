#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int main(){
	int a2b[2];
	char s[1024];
	pipe(a2b);

	if(fork() == 0){
		close(a2b[0]);
		while(fgets(s, 1024, stdin) > 0){
			int k = strlen(s);
			s[k - 1] = '\0';
		//	printf("[%s]\n", s) 
			write(a2b[1], &k, sizeof(int));
			write(a2b[1], s, k*sizeof(char));
		}
		close(a2b[1]);
		exit(0);
	}
	
	if(fork() == 0){
		close(a2b[1]);
		int k;
		while(read(a2b[0], &k, sizeof(int)) > 0){
			read(a2b[0], s, k);
			
			s[k - 1] = s[k - 2];
			s[k] = '\0';
			printf("[%s]\n", s);
		}
	
		close(a2b[0]);
		exit(0);
	}

	close(a2b[0]);
	close(a2b[1]);
	wait(0); wait(0);
	return 0;
}
