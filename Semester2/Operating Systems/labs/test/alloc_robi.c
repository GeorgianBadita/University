#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
	int **m = NULL;
	int *p;
	int rcount = 0, rlen, i, j;
	FILE *f = fopen("date.in", "rt");
	fscanf(f,"%d", &rlen);
	while(1){
		p = (int*)malloc(rlen*sizeof(int));
		for(i = 0; i<rlen; i++){
			if(fscanf(f, "%d", &p[i]) != 1){
				break;
			}	
		}
		if(i < rlen){
			free(p);
			break;
		}
		else{
			if(m == NULL){
				m = (int**)malloc((rcount+1)*sizeof(int*));
			}
			else{
				m = (int**)realloc(m, (rcount+1)*sizeof(int*));
			}
			m[rcount] = p;
			rcount++;
		}
	}
	for(i = 0; i<rcount; i++){
		for(j = 0; j<rlen; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	int fd;
	fd = open("date.dat", O_CREAT | O_TRUNC | O_WRONLY, 0600);
	write(fd, &rlen,sizeof(int));
	for(i = 0; i<rcount; i++){
		for(j = 0; j<rlen; j++){
			write(fd, &m[i][j], sizeof(int));
		}
	}
	for(i = 0; i<rcount; i++){
		free(m[i]);
	}
	free(m);
	close(fd);
	fclose(f);
	return 0;
}
