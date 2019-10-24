#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
	int a2b, b2a;
	a2b = open("second_fifo", O_WRONLY);
	b2a = open("second_fifo", O_RDONLY);

	int b;
	while(read(b2a, &b, sizeof(int))){
		printf("%d\n", b);
	}
	
	close(a2b);
	close(b2a);
	return 0;
}
