/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser/parser.y"

	#include <math.h>
	#include "sponge_std.h"
	#include "hashmap.h"
	#include "ast.h"

	extern FILE *yyin;
	extern FILE *yyout;
	extern int yylineno;
	#define YYDEBUG 1

	typedef enum{
		PARSING_SUCCESSED,
		PARSING_FAILED,
		MEMORY_FAIL
	} ParsingResult;

#line 67 "src/parser/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CST = 258,                     /* CST  */
    IDT = 259,                     /* IDT  */
    PO_ADD = 260,                  /* PO_ADD  */
    PO_SUB = 261,                  /* PO_SUB  */
    PO_MUL = 262,                  /* PO_MUL  */
    PO_DIV = 263,                  /* PO_DIV  */
    PO_AFF = 264,                  /* PO_AFF  */
    PR_EQ = 265,                   /* PR_EQ  */
    PR_GT = 266,                   /* PR_GT  */
    PR_GE = 267,                   /* PR_GE  */
    PR_LT = 268,                   /* PR_LT  */
    PR_LE = 269,                   /* PR_LE  */
    PB_AND = 270,                  /* PB_AND  */
    PB_OR = 271,                   /* PB_OR  */
    PB_NOT = 272,                  /* PB_NOT  */
    SEMICOLON = 273,               /* SEMICOLON  */
    LB = 274,                      /* LB  */
    RB = 275,                      /* RB  */
    PO_AND = 276,                  /* PO_AND  */
    PO_OR = 277                    /* PO_OR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "src/parser/parser.y"

	int64_t integer;
	Operator operator;
	char *identifier;

	ASTNode *node;

#line 114 "src/parser/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (ASTNode *root, HashMap *currentSymboleTable);


#endif /* !YY_YY_SRC_PARSER_PARSER_H_INCLUDED  */
