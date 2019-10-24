#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_voc(char c){
	if(c == 'a' || c == 'e' || c == 'i' ||
	   c == 'o' || c == 'u'){
		return 1;
	}
	return 0;
}

int count_voc(char** s, int line){
	int voc = 0;
	int i;
	for(i = 0; i<strlen(s[line]); i++){
		voc += check_voc(s[line][i]);
	}
	return voc;
}

int main(){
	int n;
	FILE* f = fopen("vocmax.in", "r");
	FILE* g = fopen("vocmax.out", "w");
	
	fscanf(f, "%d", &n);	//nr de propozitii
	char **s = NULL;
	int rcount = 0, i;
	s = (char**)malloc((rcount+1)*sizeof(char*));
	while(1){
		s[rcount] = (char*)malloc(256*sizeof(char));
		if(fgets(s[rcount], 256, f) != NULL){
			s = (char**)realloc(s,(rcount+2)*sizeof(char*));
			rcount++;
		}
		else{
			break;
		}
	}
	int maxim = -1e9, line = 0;
	for(i = 0; i<rcount; i++){
		if(count_voc(s, i) > maxim){
			maxim = count_voc(s, i);
			line = i;
		}
	}
	fprintf(g,"%s", s[line]);
	
	for(i = 0; i<rcount; i++){
		free(s[i]);
	}
	
	free(s);
	fclose(g);
	fclose(f);
	return 0;
}
