#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
	int seq = 0;
	if(fork() == 0){
		printf("Child! Seq=%d\n", ++seq);
		exit(0);
	}else{
		printf("Parent! Seq=%d\n", ++seq);
	}
	printf("Both! Seq %d\n", ++seq);
	wait(0);
	return 0;
}
