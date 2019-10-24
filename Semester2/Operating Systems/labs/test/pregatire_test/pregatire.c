#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	
	FILE* f;
	int **m = NULL;
	int* p;
	int rlen, rcount, i, j, fd;
	
	f = fopen("file.in", "r");
	fscanf(f, "%d", &rlen);
	
	rcount = 0;
	

	while(1) {

	p = (int*)malloc(sizeof(int));
		for(i = 0; i<rlen; i++){
			if(fscanf(f, "%d", &p[i]) != 1) {
				break;
			}
		}
		
		if(i < rlen) {
			free(p);
			break;
		}
		else {
			if(m == NULL){
				m = (int**)malloc((rcount+1)*sizeof(int*));
			}
			else{
				m = (int**)realloc(m, (rcount+1)*sizeof(int*));
			}
			m[rcount++] = p;
		}
	}
	
	for(i = 0; i < rcount; i++){
		printf("%d: ", i);
		for(j = 0; j<rlen; j++){
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	fclose(f);
	
	fd = open("data.dat", O_CREAT | O_TRUNC | O_WRONLY, 0600);
	write(fd, &rlen, sizeof(int));
	for(i = 0; i<rcount; i++){
		for(j = 0; j<rlen; j++){
			write(fd, &m[i][j], sizeof(int));
		}
	}
	close(fd);

	for(i = 0; i<rcount; i++){
		free(m[i]);
	}
	free(m);

	return 0;
}
