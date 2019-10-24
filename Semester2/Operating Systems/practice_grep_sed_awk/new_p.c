#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int r, w, n = 7;
	r = open("abc", O_RDONLY);
	n --;
	w = open("abc", O_WRONLY);
	n --;
	printf("%d\n", n);
	return 0;
}
