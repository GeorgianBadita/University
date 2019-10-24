#include <stdio.h>
#include <stdlib.h>

int main() {
  int **m;
  int i, j;
  m = (int**)malloc(5*sizeof(int*));
  for(i = 0; i<5; i++) {
	  m[i] = (int*)malloc(7*sizeof(int));
  }

  for(i = 0; i<5; i++) {
	  for(j = 0; j<7; j++) {
		  m[i][j] = i*j;
	  }
  }

  for(i = 0; i<5; i++) {
	  free(m[i]);
  }
  free(m);

  return 0;
}
