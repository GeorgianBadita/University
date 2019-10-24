#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#define MAX_LINE 1000
#define MAX_TH 1000

pthread_t tid[MAX_TH];


void* make_cap(void* nume_in){
	printf("Threadul: %ld ..> %s\n", pthread_self(), (char*)nume_in);
	FILE* fi, *fo;

	char line[MAX_LINE], nume_out[MAX_LINE], *p;
	strcpy(nume_out, (char*) nume_in);
	strcat(nume_out, "_CAPIT.txt");
	fi = fopen((char*)nume_in, "r");
	fo = fopen(nume_out, "w");

	while(1){
		p = fgets(line, MAX_LINE, fi);
		line[MAX_LINE-1] = '\0';
		if(p == NULL){
			break;
		}
		if(strlen(line) == 0) continue;

		line[0] = toupper(line[0]);
		for(p = line; ; ){
			p = strstr(p, " ");
			if(p == NULL) break;
			p ++;
			if(*p == '\n') break;
			*p = toupper(*p);
		}
		fprintf(fo, "%s", line);
	}

	fclose(fi);
	fclose(fo);
	printf("Terminat threadul: %ld ...> %s\n", pthread_self(), (char*)nume_in);
	return 0;
}


int main(int argc, char** argv){
	int i;

	for(i = 1; argv[i]; i++){
		pthread_create(&tid[i], NULL, make_cap, (void*)argv[i]);
		printf("Creat threadul: %ld ...> %s\n", tid[i], argv[i]);
	}

	for(i = 1; argv[i]; i++){
		pthread_join(tid[i], NULL);
		printf("Terminat toate thread-urile\n");
	}
	
	return 0;
}
