#include <stdio.h>
#include <stdlib.h>

int get_max_mat(int** m, int rcount, int rlen){
	int i, j, maxim = -1;
	for(i = 0; i<rcount; i++){
		for(j = 0; j<rlen; j++){
			if(maxim < m[i][j]){
				maxim = m[i][j];
			}
		}
	}
	return maxim;
}

int get_min_col(int **a, int col, int rcount){
	int min = 1e9;
	int i = 0;
	for(i = 0; i<rcount; i++){
		if(a[i][col] < min){
			min = a[i][col];
		}
	}
	return min;
}

int main(){
	FILE *f = fopen("matrice7.in", "r");
	FILE *g = fopen("matrice7.out", "w");
	int junk, rlen, rcount = 0, i, j;
	int maxim;
	int** a;
	a = (int**)malloc((rcount+1)*sizeof(int*));
	int* p;
	fscanf(f, "%d%d", &junk, &rlen);	
	while(1){
		p = (int*)malloc((rlen+1)*(sizeof(int)));
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
			a = (int**)realloc(a, (rcount+2)*sizeof(int*));
			
			a[rcount++] = p;
		}
	}
	int minim = -1;
	maxim = get_max_mat(a, rcount, rlen);
	for(i = 0; i<rcount; i++){
		for(j = 0; j<rlen; j++){
			if(a[i][j] == maxim){
				minim = get_min_col(a, j, rcount);
				a[i][j] = minim;
			}
			fprintf(g, "%d ", a[i][j]);
		}
		fprintf(g, "\n");
	}
	for(i = 0; i<rcount; i++){
		free(a[i]);
	}
	free(a);
	fclose(f);
	fclose(g);
	return 0;
}

