#include <stdio.h>
#include <stdlib.h>

int main() {
	int **a;
	int i, j, n, m;
	scanf("%d", &n); //nr linii
	scanf("%d", &m); // nr coloane
	a = (int**)malloc(n*sizeof(int*));
	for(i = 0; i<n; i++) {
		a[i] = (int*)malloc(m*sizeof(int));
	}
	
	for(i = 0; i<n; i++) {
		for(j = 0; j<m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int *s;
	s = (int*)malloc(n*sizeof(int));
	for(i = 0; i<n; i++) {
		for(j = 0; j<m; j++) {
			s[i] += a[i][j];
		}
	}
	
	for(i = 0; i<n; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");
	for(i = 0; i<n; i++) {
		for(j = 0; j<m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i<n; i++) {
		free(a[i]);
	}
	free(a);
	free(s);
	return 0;
}
