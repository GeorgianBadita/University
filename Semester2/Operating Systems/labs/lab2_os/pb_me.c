#include <stdio.h>
#include <stdlib.h>

void read_matrix() {
	FILE* f;
	int** a;
	f = fopen("file", "rt");
	if(f == NULL) {
		printf("Eror");
		return;
	}

	int n = 0, i, linie =0 , nr = 0, j;
	fscanf(f, "%d", &n);
	a = (int**)malloc(1*sizeof(int*)); 
	a[linie] = (int*)malloc(n*sizeof(int));
	while(1) {
		for(i = 0; i<n; i++) {
			fscanf(f, "%d", &nr);
			a[linie][i] = nr;
		}
		if (feof(f)) {
			break;
		}
		linie += 1;
	
		a = (int**)realloc(a, (linie+1)*sizeof(int*));
		a[linie] = (int*)malloc(n*sizeof(int));
	}
	
	for(i = 0; i<linie; i++) {
		for(j = 0; j<n; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	read_matrix();
	return 0;
}
