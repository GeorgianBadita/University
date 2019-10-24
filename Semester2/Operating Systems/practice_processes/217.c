#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int a2b[2], b2a[2];
	
	pipe(a2b);
	pipe(b2a);

	if(fork() == 0){
		close(b2a[1]);
		int n;
		while(1){
			printf("Give a number: ");
			scanf("%d", &n);
			write(a2b[1], &n, sizeof(int));
			if(n == -1){
				break;
			}
			int par;
			int val = read(b2a[0], &par, sizeof(int));
			if(val > 0 && par != -1){
				printf("%d\n", par);
			}
		}
		close(a2b[0]);
		close(a2b[1]);
		close(b2a[0]);
		exit(0);
	}
	
	if(fork() == 0){
		
		int n;
		close(b2a[0]);
		while(1){
			read(a2b[0], &n, sizeof(int));
			if(n == -1){
				break;
			}
			if(n % 2 == 0){
				n*=2;
				write(b2a[1], &n, sizeof(int));
			}
			else{
				int p = -1;
				write(b2a[1], &p, sizeof(int));
			}
		}
		close(a2b[0]);
		close(a2b[1]);
		close(b2a[1]);
		exit(0);
	}

	close(a2b[0]);
	close(a2b[1]);
	close(b2a[0]);
	close(b2a[1]);
	wait(0); wait(0);
	return 0;
}
