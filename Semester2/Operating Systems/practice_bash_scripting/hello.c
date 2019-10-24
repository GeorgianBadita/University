#include <stdio.h>

int main(){
	FILE* g = fopen("out.txt", "w");
	int x = 4;
	fprintf(g, "%d", x);
	return 0;
}
