#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



void with_fgetc() {
	FILE* f;
	f = fopen("file.in", "rt");
	char c;
	int n = 0;
	while(1){
		c = fgetc(f);
		if(c == EOF){
			break;
		}
		else{
			if(c >= '0' && c <= '9'){
				n += 1;
			}
		}
	}
	fclose(f);
	printf("with fgetc: %d\n", n);
}

void with_fgets() {
	FILE *f;
	f = fopen("file.in", "rt");
	int n = 0, i;
	char s[1024];
	while(fgets(s, 1024, f) != NULL){	//parametrii: sirul, dim, file
		for(i = 0; i<strlen(s); i++){
			if(s[i] >= '0' && s[i] <='9'){
				n += 1;
			}
		}
	}
	fclose(f);
	printf("with fgets: %d\n", n);
}

void with_faraf(){
	int fd;
	int n=0, i, k;
	char buff[1024];
	n = 0;
	fd = open("file.in", O_RDONLY);
	while(1){
		k = read(fd, buff, 1024);	//file, buff, dim
		if(k <= 0){
			break;
		}
		for(i = 0; i<k; i++){
			if(buff[i] >= '0' && buff[i] <= '9'){
				n++;
			}
		}
	}
	close(fd);
	printf("with faraf: %d\n ", n);
}

int main() {
	with_fgetc();
	with_fgets();
	with_faraf();
	return 0;
}
