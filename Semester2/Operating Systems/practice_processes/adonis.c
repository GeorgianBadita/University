#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define   BUF_SIZE   100

int main()
{
  
    if(fork() == 0){
		int a2b = open("myfifo1", O_WRONLY);
		int b2a = open("myfifo2", O_RDONLY);
		while(1){
			int n, k;
			scanf("%d", &n);
			write(a2b, &n, sizeof(int));
			read(b2a, &k, sizeof(int));
			printf("Recieved from child 2: %d\n", k);
			if(n <= 5){
				exit(0);
			}
		}
		close(a2b);
		close(b2a);
	}

	if(fork() == 0){
		int a2b = open("myfifo1", O_RDONLY);
		int b2a = open("myfifo2", O_WRONLY);
		while(1){
			int n;
			read(a2b, &n, sizeof(int));
			write(b2a, &n, sizeof(int));
			if(n <= 5){
				exit(0);
			}
			printf("Recieved from child 1: %d\n", n);

		}
		close(a2b);
		close(b2a);
	}
   

	wait(0);
	wait(0);

    return 0;
}
