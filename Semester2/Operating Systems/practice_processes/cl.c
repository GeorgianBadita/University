#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int srv2cl, cl2srv;
	srv2cl = open("first_fifo", O_RDONLY);
	cl2srv = open("first_fifo", O_WRONLY);

	int number = 0;

	while(number >= 0){
		scanf("%d", &number);
		write(cl2srv, &number, sizeof(int));
		if(number < 0){
			break;
		}
	}
	
	int num_par = 0;
	
	read(srv2cl, &num_par, sizeof(int));
	
	printf("Au fost introduse %d numere pare\n", num_par);

	close(srv2cl);
	close(cl2srv);
	return 0;
}
