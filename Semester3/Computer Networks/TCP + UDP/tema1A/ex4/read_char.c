#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int n;
	scanf("%d", &n);
	scanf("\n");
	char *str;
	str = (char*)malloc((n+1)*sizeof(char));
	fgets(str, n+1, stdin);
	for(int i = 0; i<n; i++){
		printf("%c", str[i]);
	}
	return 0;
}
