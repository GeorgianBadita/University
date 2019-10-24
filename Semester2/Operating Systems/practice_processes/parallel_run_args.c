#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv){
	int i, j, k, n;
	char** a;
	n = 0;
	i = 1;
	while(i < argc){
		k = 0;
		while(i + k < argc && strcmp(argv[i + k], ";") != 0){
			k ++;
		}
		a = (char**)malloc((k+1)*sizeof(char*));
		for(j = 0; j<k; j++){
			a[j] = argv[i + j];
		}
		a[k] = NULL;
		n ++;
		if(fork() == 0){
			execvp(a[0], a);
			free(a);
			exit(1);
		}
		free(a);
		i += k + 1;
	}

	for(int i = 0; i<n; i++){
		wait(0);
	}
	return 0;
}
