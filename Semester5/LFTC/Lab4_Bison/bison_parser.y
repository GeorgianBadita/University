
%{
#include <stdio.h>

int yylex();
int yyerror(char *s);

%}

%token RETURN INCLUDE IOSTREAM NAMESPACE MAIN LEFT_PAR RIGHT_PAR LEFT_BR RIGHT_BR PLUS MINUS DIV MUL MOD INOP OUTOP IFSTMT WHILESTMT INTDECL FLOATDECL EQUALS INTEGER FLOAT OTHER SEMICOLON ID IDVECTOR RELATION
%left <operator> EQUALS
%type <id> ID
%type <id_vector> IDVECTOR
%type <int_number> INTEGER
%type <float_number> FLOAT

%union{
	  char id[250];
      char id_vector[250];
      int int_number;
      float float_number;
}

%%

prog:
  | header lista_decl lista_isntr final
;

header: INCLUDE IOSTREAM NAMESPACE SEMICOLON INTDECL MAIN LEFT_PAR RIGHT_PAR LEFT_BR

lista_decl:
            | decl SEMICOLON lista_decl

decl: tip variabila 
tip: INTDECL | FLOATDECL

variabila: ID
    | IDVECTOR


lista_isntr: 
    | instr SEMICOLON lista_isntr

instr: | attr | inout | if_exp | while_exp

attr: ID EQUALS exp

exp: 
    | const
    | variabila
    | exp PLUS variabila
    | exp MINUS variabila
    | exp DIV variabila
    | exp MOD variabila
    | exp MUL variabila

const: INTEGER | FLOAT

inout: INOP variabila | OUTOP exp
if_exp: IFSTMT LEFT_PAR condition RIGHT_PAR LEFT_BR lista_isntr RIGHT_BR
while_exp: WHILESTMT LEFT_PAR condition RIGHT_PAR LEFT_BR lista_isntr RIGHT_BR
condition: exp RELATION exp

final: RETURN INTEGER SEMICOLON RIGHT_BR {printf("Program respects the grammar rules!"); return 0;}
;


%%

int yyerror(char *s)
{
	printf("Syntax Error on line %s\n", s);
	return 0;
}

int main()
{
    yyparse();
    return 0;
}
