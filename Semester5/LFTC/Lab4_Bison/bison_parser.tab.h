
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RETURN = 258,
     INCLUDE = 259,
     IOSTREAM = 260,
     NAMESPACE = 261,
     MAIN = 262,
     LEFT_PAR = 263,
     RIGHT_PAR = 264,
     LEFT_BR = 265,
     RIGHT_BR = 266,
     PLUS = 267,
     MINUS = 268,
     DIV = 269,
     MUL = 270,
     MOD = 271,
     INOP = 272,
     OUTOP = 273,
     IFSTMT = 274,
     WHILESTMT = 275,
     INTDECL = 276,
     FLOATDECL = 277,
     EQUALS = 278,
     INTEGER = 279,
     FLOAT = 280,
     OTHER = 281,
     SEMICOLON = 282,
     ID = 283,
     IDVECTOR = 284,
     RELATION = 285
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 17 "bison_parser.y"

	  char id[250];
      char id_vector[250];
      int int_number;
      float float_number;



/* Line 1676 of yacc.c  */
#line 91 "bison_parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


