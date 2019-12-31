%{
#include <stdio.h>
#include <string.h>
// bison
#include "bison_syntax.tab.h"
// line number counter
int mylineno = 1;
%}

digit [0-9]
integer 0|([1-9])[0-9]*
character [a-zA-Z]
%option noyywrap

%%
"\n" {mylineno ++; }
"\t" // ignore
" " // ignore
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
"cin>>" {return(INOP);}
"cout<<" {return(OUTOP);} 
int {return(INTDECL);}
"<"|">"|"<="|">=" {return(RELATION);}
";" {return(SEMICOLON);}
"=" {return(EQUALS);}
{integer} {strcpy(yylval.id, yytext); return(INTEGER);}
{character}({digit}){0,249} {sscanf(yytext, "%s", yylval.id); return (ID);}
.      		     {return(OTHER);}

%%
