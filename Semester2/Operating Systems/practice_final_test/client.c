#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int a2b = open("first_fifo", O_WRONLY);
	int b2a = open("second_fifo", O_RDONLY);
	char s[1024];
	while(1){
		int k, val;
		val = read(b2a, &k, sizeof(int));
		read(b2a, s, k);
		if(val <= 0 || strlen(s) == 0){
			break;
		}
		printf("Client: %s\n", s);
		s[strlen(s) - 1] = '\0';
		int n = strlen(s) + 1;
		write(a2b, &n, sizeof(int));
		write(a2b, s, n);
	}

	close(a2b);
	close(b2a);
	return 0;
}
