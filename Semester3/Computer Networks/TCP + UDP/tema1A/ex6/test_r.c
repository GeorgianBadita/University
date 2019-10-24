#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	char *str;
	scanf("%d", &n);
	str = (char*)malloc(n*sizeof(char));
	str[0] = '\0';
	int i;
	for(i = 0; i<n; i++){
		char ch;
		scanf("%c", &ch);
		str[i] = ch;
	}
	for(i = 0; i<n; i++){
		printf("%c", str[i]);
	}
	free(str);
	return 0;
}
