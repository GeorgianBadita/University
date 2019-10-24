#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int pid;

void stop(int sig){
	kill(pid, SIGKILL);
	wait(0);
	exit(0);
}

int main(int argc, char** argv){
	signal(SIGINT, stop);
	while(1){
		pid = fork();
		if(pid == 0){
			execvp(argv[1], argv+1);
			exit(1);
		}
		wait(0);
	}
	return 0;
}
