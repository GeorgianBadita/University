#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int pid;
void stop(int sig){
	kill(pid, SIGKILL);
	wait(0);	
	exit(0);
}

int cnt = 0;

void stop1(int sig){
	cnt ++;
}

int main(int argc, char** argv){
	
	signal(SIGALRM, stop1);
	alarm(3);
	while(1){
		pid = fork();
		if(pid == 0){	
			sleep(2);
			execvp(argv[1], argv + 1);
			exit(1);
		}
		printf("%d\n", cnt);
		wait(0);
	}
	return 0;
}
