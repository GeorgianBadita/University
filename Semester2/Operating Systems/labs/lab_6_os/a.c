#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	int cond = 0, pid;
	pid = fork();
	execvp(argv[1], argv+1);
	
	while(1){
		if(cond == 1) {
			cond = 0;
			pid = fork();
			execvp(argv[1], argv+1);
		}
		//sleep(3);
		int res = kill(pid, 0);
		if(res != 0){
			wait(0);
			cond = 1;
			continue;
		}
	}
	return 0;
}
