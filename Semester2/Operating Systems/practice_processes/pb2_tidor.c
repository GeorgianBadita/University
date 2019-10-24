/*
 * Client gives indfinetly many words as command line arguments
 * Make a process that takes every word and tells to its parent
 * how many words ends with an 'a'
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int ends_with_a(char* str){
	return str[strlen(str) - 1] == 'a';
}

int main(int argc, char** argv){
	int  p[2];
    
 	pipe(p);

	if(fork() == 0){
		close(p[0]);
		int num = 0;
		for(int i = 1; i<argc; i++){
			if(ends_with_a(argv[i])){
				num++;
			}
		}
		write(p[1], &num, sizeof(int));
		exit(0);
	}
	
	int nr_a = 0;
	read(p[0], &nr_a, sizeof(int));
	
	printf("Number of words ending in a: %d\n", nr_a);

	close(p[0]);
	close(p[1]);
	wait(0);
	return 0;
}
