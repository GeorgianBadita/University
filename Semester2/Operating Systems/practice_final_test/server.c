#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int b2a = open("first_fifo", O_RDONLY);
	int a2b = open("second_fifo", O_WRONLY);

	char s[] = "I'mastring\0";
	
	printf("Server: %s\n", s);
	while(1){
		s[strlen(s) - 1] = '\0';
		int k = strlen(s) + 1;
		write(a2b, &k, sizeof(int));
		write(a2b, s, k);
		
		int n, val;
		val = read(b2a, &n, sizeof(int));
		read(b2a, s, n);
		if(val <= 0 || strlen(s) == 0){
			break;
		}
		printf("Server: %s\n", s);
	}

	close(b2a);
	close(a2b);
	return 0;
}
