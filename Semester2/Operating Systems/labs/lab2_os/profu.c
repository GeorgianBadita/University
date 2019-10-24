#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	FILE* fin;
	FILE *fd;
	int rlen, i, j, go, rcount = 0;	
	int **m;	

	fin = fopen("data.txt", "rt");
	fscanf(fin, "%d", &rlen);
	printf("%d\n", rlen);
	m = (int**)malloc(1*sizeof(int*));
	rcount = 1;
	go = 1;
	while(go) {
		m[rcount-1] = (int*)malloc(rlen*sizeof(int));
		for(i = 0; i<rlen; i++){
			if(fscanf(fin, "%d", &m[rcount-1][i])<=0) {
				go = 0;
				break;
			}
		}
		if(go) {
			rcount ++;
			m = (int**)realloc(m, (rcount+1)*sizeof(int*));
		}
	}
	
	for(i = 0; i<rcount-1; i++) {
		for(j = 0; j<rlen; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	
	fclose(fin);
	
	fd = open("open.dat", O_CREAT | O_TRUNC | O_WRONLY);
	write(fd, &rlen, sizeof(int));
	
	for(i = 0; i<rcount-1; i++) {
		for(j = 0; j<rlen; j++) {
			write(fd, &m[i][j], sizeof(int));
		}
	}

	for(i = 0; i<rcount; i++) {
		free(m[i]);
	}
	free(m);
	return 0;
}
