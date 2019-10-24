#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//Handler when the parent dies, so doe the child
int pid;

void stop(int sig){
	kill(pid, SIGKILL);
	wait(0);
	exit(0);
}

int main(int argc, char** argv){
	signal(SIGINT, stop);

	if(fork() == 0){
		execvp(argv[1], argv + 1);
		exit(1);
	}
	
	while(1){
		sleep(1);
		wait(0);

		if(fork() == 0){
			execvp(argv[1], argv + 1);
			exit(1);
		}
	}
	
	return 0;
}
