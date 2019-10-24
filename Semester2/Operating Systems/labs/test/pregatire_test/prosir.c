#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
	int f;
	int g;
	int k;
	f = open("prosir.in", O_RDONLY);
	g = open("prosir.out",O_TRUNC|O_WRONLY);
	char s[256];
	while(1){
		k = read(f, s, 256*sizeof(char));
		if(k <= 0){
			break;
		}
	}
	int i;
	for(i = 0; i<strlen(s)-1; i++){
		if(s[i] >= 'a' && s[i] <= 'z' && !(s[i+1] >= 'a' && s[i+1] <= 'z')){
			s[i] = '5';
		}
	}

	write(g, s, (strlen(s)-2)*sizeof(char));
	close(f);
	close(g);
	return 0;
}
