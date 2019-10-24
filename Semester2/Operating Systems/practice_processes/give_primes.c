#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
	int a2b, b2a;
	a2b = open("second_fifo", O_RDONLY);
	b2a = open("second_fifo", O_WRONLY);
	int n;
	printf("Give a number: ");
	scanf("%d", &n);
	for(int i = 2; i<=n; i++){
		write(b2a, &i, sizeof(int));
	}

	close(a2b);
	close(b2a);
	return 0;
}
