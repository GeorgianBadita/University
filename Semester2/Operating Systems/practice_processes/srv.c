#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int srv2cl, cl2srv;
	int num_par = 0;
	srv2cl = open("first_fifo", O_WRONLY);
	cl2srv = open("first_fifo", O_RDONLY);

	while(1){
		int num;
		int val = read(cl2srv, &num, sizeof(int)); 
		if(val < 0 || num < 0){
			break;
		}
		if(num % 2 == 0){
			printf("Numarul %d este par\n", num);
			num_par ++;
		}
	}	
	
	write(srv2cl, &num_par, sizeof(int));

	close(srv2cl);
	close(cl2srv);

	return 0;
}
