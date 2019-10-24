#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv){
	for(int i = 1; i<argc; i++){
		if(fork() == 0){
			execlp(argv[i], argv[i], NULL);
			exit(1);
		}
	}
	for(int i = 1; i<argc; i++){
		wait(0);
	}
	return 0;
}
