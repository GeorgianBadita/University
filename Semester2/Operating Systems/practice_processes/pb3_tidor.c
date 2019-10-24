/*
 * The client gives indefinetly many words as command line arguments
 * Write a programm, that makes a process which for every word checks
 * if it ends with an 'a', and returns to the parent the list of the
 * words ending in 'a', then the parent process calcualtes the mean value
 * of their lengths
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int ends_with_a(char* str){
	return str[strlen(str) - 1] == 'a';
}

int main(int argc, char** argv){
	int a2b[2];
	pipe(a2b);
	double mean = 0;

	if(fork() == 0){
		close(a2b[0]);
		for(int i = 1; i<argc; i++){
			if(ends_with_a(argv[i]) == 1){
				int k = strlen(argv[i]) + 1;
				write(a2b[1], &k, sizeof(int));
				write(a2b[1], argv[i], k*sizeof(char));
			}
		}
		int k = -1;
		write(a2b[1], &k, sizeof(int)); 	
		close(a2b[1]);
		exit(0);
	}	
	
	if(fork() == 0){
		close(a2b[1]);
		int num;
		int n_str = 0;
		int mean_val = 0;
		while(1){
			int val = read(a2b[0], &num, sizeof(int));
			if(val <= 0 || num < 0){
				break;
			}

			char* str = (char*)malloc(num*sizeof(char));
		    read(a2b[0], str, num*sizeof(char));
		    printf("%s\n", str);
			mean_val += strlen(str);
			n_str ++;
			free(str);
		}
	    if(n_str != 0){
			mean=(double)mean_val/n_str;
		}else{
			mean = 0;
		}
		
		printf("The mean is: %f\n", mean);	

		close(a2b[0]);
		exit(0);	
	}	
	
	close(a2b[0]); close(a2b[1]);
	wait(0); wait(0);
	return 0;
} 
