#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUFF_SIZE 1024

int main(){
	FILE* f = popen("ps -ef | awk {'print $1'} | sort | uniq", "r");
	char s[BUFF_SIZE];
	while(fgets(s, BUFF_SIZE, f) != NULL){
		printf("User: %s\n", s);
	}
	pclose(f);
	return 0;
}
