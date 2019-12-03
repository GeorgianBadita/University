%{

#include <stdio.h>
#include <string.h>
#include "bison_parser.tab.h"
%}

digit [0-9]*
integer 0|([1-9])[0-9]*
character [a-zA-Z]
vecId ([1-9])[0-9]*

%%
" "  /* Consume space */
"\n" /* Consume new line */
"\t" /* Consume tab */
"#include" {return(INCLUDE);}
"<iostream>" {return(IOSTREAM);}
"using namespace std" {return(NAMESPACE);}
"main" {return(MAIN);}
"return" {return(RETURN);}
"(" {return(LEFT_PAR);}
")" {return(RIGHT_PAR);}
"{" {return(LEFT_BR);}
"}" {return(RIGHT_BR);}
"+" {return(PLUS);}
"-" {return(MINUS);}
"/" {return(DIV);}
"*" {return(MUL);}
"%" {return(MOD);}
cin" "*">>" {return(INOP);}
cout" "*"<<" {return(OUTOP);} 
"if" {return (IFSTMT);}
"while" {return(WHILESTMT);}
int {return(INTDECL);}
float {return(FLOATDECL);}
"<"|">" {return(RELATION);}
";" {return(SEMICOLON);}
"=" {return(EQUALS);}
{integer} {yylval.int_number = atoi(yytext); return(INTEGER);}
{integer}\.{digit}+ {yylval.float_number = atof(yytext); return(FLOAT);}
{character}|{character}({character}{digit}){0,249} {sscanf(yytext, "%s", yylval.id); return (ID);}
{character}|{character}({character}{digit}){0,249}"["{vecId}"]" {sscanf(yytext, "%s", yylval.id_vector); return (IDVECTOR);}
.      		     {return(OTHER);}

%%


int yywrap(){
    return 1;
}