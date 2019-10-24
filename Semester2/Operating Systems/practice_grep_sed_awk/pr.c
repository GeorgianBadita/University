#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
	int k = fork();
	if(k == 0){
		printf("Hello from Child\n");
		exit(0);
	}else{
		printf("Hello from Parent\n");
	}
	printf("Hello from Both\n");
	return 0;
}
