#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv){

	if(fork() == 0){
		execvp(argv[1], argv + 1);
		wait(0);
		exit(1);
	}
	wait(0);
	return 0;
}
