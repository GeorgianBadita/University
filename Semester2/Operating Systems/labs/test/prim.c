#include<stdio.h>
#include <stdlib.h>


int prim(int x) {
	int i;
	if(x < 2) return 0;
	if(x == 2) return 1;
	if(x % 2 == 0) return 0;
	for(i = 3; i*i<=x; i+=2) {
		if(x % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int* a;
	int i;
	a = malloc(4*sizeof(int));
	for(i = 0; i<4; i++) {
		scanf("%d", &a[i]);
		printf("%d", prim(a[i]));
	}

	free(a);
	return 0;
}
