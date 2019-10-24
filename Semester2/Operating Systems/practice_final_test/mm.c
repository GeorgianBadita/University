#include <stdio.h>
#include <stdlib.h>
#define N 200

int arr[N];

int main(){
	
	FILE* g = fopen("ana.txt", "r");

	
	for(int i = 0; i<N; i++){
		int k;
		fscanf(g, "%d", &k);
		printf("%d\n", k);
	}
	
	//fclose(f);
	fclose(g);

	return 0;
}
