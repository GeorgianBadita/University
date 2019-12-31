#!/bin/sh
flex parser.l
bison -dv bison_syntax.y
gcc -o syntax_check lex.yy.c bison_syntax.tab.c

