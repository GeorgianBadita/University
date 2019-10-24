#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m, i, j, s = 0;
	int **a;
	scanf("%d%d", &n, &m);
	a = (int**)malloc(n*sizeof(int*));
	for(i = 0; i<n; i++){
		a[i] = (int*)malloc(m*sizeof(int));
	}
	
	for(i = 0; i<n; i++) {
		for(j = 0; j<m; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j] % 2 == 0){
				s += a[i][j];
			}
		}
	}
	printf("%d", s);
	return 0;
}
