#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int n;
int* pid;

void stop(int sig){
	int i;
	for(i = 0; i<n; i++){
		kill(pid[i], SIGKILL);
		wait(0);
	}
	free(pid);
	exit(0);
}

int main(int argc, char** argv){
	int i,  k;
	pid = (int*)malloc(sizeof(argc));
	n = 0;
	i = 1;
	while(i < argc){
		k = 0;
		while(i + k < argc && strcmp(argv[i+k], ";")!=0){
			k++;
		}
		argv[k] = NULL;
		n ++;
		pid[n - 1] = fork();
		if(pid[n - 1] == 0){
			execvp(argv[i], argv + i);
			exit(1);
		}
		i += k + 1;
	}

	signal(SIGALRM, stop);
	alarm(10);
	for(int i = 0; i<n; i++){
		wait(0);
	}
	return 0;
}
