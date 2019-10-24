#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char**s = NULL;
	int rcount = 0, i, j;
	char *p;
	FILE *f = fopen("perechivocale1.in", "r");
	FILE *g = fopen("perechivocale1.out", "w");
	while(1){
		p = (char*)malloc(256*sizeof(char));
		if(fgets(p, 256, f)!= NULL){
			if(s == NULL){
				s = (char**)malloc((rcount+1)*sizeof(char*));
			}
			else{
				s = (char**)realloc(s,(rcount+1)*sizeof(char*)); 		
			}
			s[rcount] = p;
			rcount++;
		}
		else{
			free(p);
			break;
		}
	}
	int ** a;
	a = (int**)malloc(26*sizeof(int*));
	for(i = 0; i<26; i++){
		a[i] = (int*)malloc(26*sizeof(int));
	}
	for(i = 0; i<26; i++){
		for(j = 0; j<26; j++){
			a[i][j] = 0;
		}
	}
	
	for(i = 0; i<rcount; i++){
		for(j = 0; j<strlen(s[i]) - 1; j++){
			if(strchr("aeiou", s[i][j]) && strchr("aeiou", s[i][j+1])){
				a[s[i][j] - 'a'][s[i][j+1]-'a'] ++;
			}
		}
	}	
	int maxim = -1;
	for(i = 0; i<26; i++){
		for(j = 0; j<26; j++){
			if(a[i][j] != 0 && a[i][j] > maxim){
				maxim = a[i][j];
			}
		}
	}
	
	for(i = 0; i<26; i++){
		for(j = 0; j<26; j++){
			if(a[i][j] == maxim){
				fprintf(g, "%c%c ", (char)(i+'a'), (char)(j+'a'));
			}
		}
	}

	for(i = 0; i<26; i++){
		free(a[i]);
	}
	free(a);
	
	for(i = 0; i<rcount; i++){
		free(s[i]);
	}	
	free(s);
	fclose(f);
	fclose(g);
	return 0;

}
