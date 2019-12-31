%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//lexer
int yylex();
// error handling
void yyerror(char *s);
// file
extern FILE *yyin;
// from flex
extern int mylineno;

char DS[4096]; // data segment

char CS[4096]; // code segment

void addToDS(char *s);

void addToCS(char *s);

char *moveToPrintBuffer(char *s);

void writeToFile();

int tempnr = 1;

void newTempName(char *s);

%}

%token RETURN INCLUDE IOSTREAM NAMESPACE MAIN LEFT_PAR RIGHT_PAR LEFT_BR RIGHT_BR PLUS MINUS DIV MUL MOD INOP OUTOP INTDECL EQUALS OTHER SEMICOLON RELATION

%token <id> ID
%token <id> INTEGER
%union{
	char id[250];
}
%type <id> exp
%type <id> variabila

%%

prog: header lista_decl lista_instr final
;

header: INCLUDE IOSTREAM NAMESPACE SEMICOLON INTDECL MAIN LEFT_PAR RIGHT_PAR LEFT_BR

lista_decl:
	  | decl SEMICOLON lista_decl

decl: INTDECL variabila
{
	char *tmp = (char*)malloc(sizeof(char)*250);
	sprintf(tmp, "%s dd 0\n", $2);
	addToDS(tmp);
	free(tmp);
}

variabila: ID 
{
	strcpy($$, $1);
}	 
| INTEGER
{
	strcpy($$, $1);
}

lista_instr: 
	   | instr SEMICOLON lista_instr

instr: attr | inout

attr: ID EQUALS exp
{
	char *tmp = (char*)malloc(sizeof(char)*250);
	sprintf(tmp, "mov eax, [%s]\n", $3);
	addToCS(tmp);
	sprintf(tmp, "mov [%s], eax\n", $1);
	addToCS(tmp);
	free(tmp);
}
exp: variabila
   | variabila PLUS variabila
{
	char *temp = (char *)malloc(sizeof(char)*250);
	newTempName(temp);
	strcpy($$, temp); 
	char *tmp = (char *)malloc(sizeof(char)*250);
	sprintf(tmp, "mov eax, [%s]\n", $1);
	addToCS(tmp);
	sprintf(tmp, "add eax, [%s]\n", $3);
	addToCS(tmp);
	sprintf(tmp, "mov [%s], eax\n", temp);
	addToCS(tmp);
	free(temp);
	free(tmp);
}
   | variabila MINUS variabila
{
	char *temp = (char *)malloc(sizeof(char)*250);
	newTempName(temp);
	strcpy($$, temp);
	char *tmp = (char *)malloc(sizeof(char)*250);
	sprintf(tmp, "mov eax, [%s]\n", $1);
	addToCS(tmp);
	sprintf(tmp, "sub eax, [%s]\n", $3);
	addToCS(tmp);
	sprintf(tmp, "mov [%s], eax\n", temp);
	addToCS(tmp);
	free(temp);
	free(tmp);
}
   | variabila DIV variabila
{
	char *temp = (char *)malloc(sizeof(char)*250);
	newTempName(temp);
	strcpy($$, temp);
	char *tmp = (char *)malloc(sizeof(char)*250);
	sprintf(tmp, "mov eax, [%s]\n", $1);
	addToCS(tmp);
	sprintf(tmp, "div eax, [%s]\n", $3);
	addToCS(tmp);
	sprintf(tmp, "mov [%s], eax\n", temp);
	addToCS(tmp);
	free(temp);
	free(tmp);
}
   | variabila MUL variabila
{
	char *temp = (char *)malloc(sizeof(char)*250);
	newTempName(temp);
	strcpy($$, temp);
	char *tmp = (char *)malloc(sizeof(char)*250);
	sprintf(tmp, "mov eax, [%s]\n", $1);
	addToCS(tmp);
	sprintf(tmp, "mul eax, [%s]\n", $3);
	addToCS(tmp);
	sprintf(tmp, "mov [%s], eax\n", temp);
	addToCS(tmp);
	free(temp);
	free(tmp);
}

inout: INOP variabila
{
	char *tmp = (char *)malloc(sizeof(char)*250);
	sprintf(tmp, "push dword %s\npush dword format_decimal\ncall [scanf]\nadd esp,4*2\n" ,$2);
	addToCS(tmp);
}	 
     | OUTOP exp
{
	char *tmp = (char *)malloc(sizeof(char)*250);
	sprintf(tmp, "push dword [%s]\npush dword format_decimal\ncall [printf]\nadd esp,4*2\n", $2);
	addToCS(tmp);
}

final: RETURN INTEGER SEMICOLON RIGHT_BR {printf("Program syntax is OK.\n"); return 0;}
;


%%

//display error
void yyerror(char *s)
{
	//mylineno extern from flex
	printf("%s on line %d\n", s, mylineno);
	exit(0);
}

int main(int argc, char** argv)
{
    printf("okk");
    memset(DS, 0, 4096);
    memset(CS, 0 ,4096);
    
    //from file or from command line (line by line)
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        yyparse();
	printf("ok");
	writeToFile();
	system("sed -r 's/\\[([0-9]+)\\]/\\1/g' out.out > out.asm");
    }

    return 0;
}

void addToDS(char *s){
    strcat(DS, s);
}

void addToCS(char *s){
    strcat(CS, s);
}

char* moveToPrintBuffer(char *s){
    char *temp = (char*)malloc(sizeof(char)*250);
    sprintf(temp, "mov bx, %s\nmov buffer, bx\nmov buffer+2, '$'\n", s);
    return temp;
}

void writeToFile() {
	char *header = (char *) malloc(sizeof(char)*3000);
	char *segmentData = (char *) malloc(sizeof(char)*3000);
	char *segmentCode = (char *) malloc(sizeof(char)*3000);
	
	strcpy(header, "bits 32\n");
	strcat(header, "global start\nextern exit, scanf, printf\nimport exit msvcrt.dll\nimport scanf msvcrt.dll\nimport printf msvcrt.dll\n");
	strcpy(segmentData, "segment data\nformat_decimal db \"%d\",0\n");
	strcat(segmentData, DS);
	strcpy(segmentCode, "segment code\nstart:\n");
	strcat(segmentCode ,CS);
	strcat(segmentCode, "push dword 0\ncall [exit]\n");

	FILE *f = fopen("out.out", "w");
	if(f == NULL) {
		perror("Mayday -> file out.out has failed.");
		exit(1);
	}

	fwrite(header, strlen(header), 1, f);
	fwrite(segmentData, strlen(segmentData), 1, f);
	fwrite(segmentCode, strlen(segmentCode), 1, f);

	fclose(f);
	free(header);
	free(segmentData);
	free(segmentCode);
}


void newTempName(char *s) {
	sprintf(s, "temp%d dd 1\n", tempnr);
	addToDS(s);
	sprintf(s, "temp%d", tempnr);
	tempnr++;
}

