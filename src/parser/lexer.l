%option nounput noinput noyywrap
%option yylineno

%{
	#include "operator.h"
	#include "hashmap.h"
	#include "parser.h"
	#include "ast.h"
%}

DIGIT [0-9]

%%

-?[0-9]+	{yylval.node = newASTConstant(strtoul(yytext, NULL, 0)); return CST;}

"="			{yylval.node = newASTOperator(SO_AFF); return PO_AFF;}
"+"			{yylval.node = newASTOperator(SO_ADD); return PO_ADD;}
"-"			{yylval.node = newASTOperator(SO_SUB); return PO_SUB;}
"*"			{yylval.node = newASTOperator(SO_MUL); return PO_MUL;}
"/"			{yylval.node = newASTOperator(SO_DIV); return PO_DIV;}

"=="		{yylval.node = newASTOperator(SO_EQ);  return PR_EQ;}
"<="		{yylval.node = newASTOperator(SO_LE);  return PR_LE;}
">="		{yylval.node = newASTOperator(SO_GE);  return PR_GE;}
"<"			{yylval.node = newASTOperator(SO_LT);  return PR_LT;}
">"			{yylval.node = newASTOperator(SO_GT);  return PR_GT;}

"and"|"&&"	{yylval.node = newASTOperator(SB_AND); return PB_AND;}
"or"|"||"	{yylval.node = newASTOperator(SB_OR);  return PB_OR; }
"not"|"!"	{yylval.node = newASTOperator(SB_NOT); return PB_NOT;}


";"			{return SEMICOLON;}
"("			{return LB;}
")"			{return RB;}

[\t\n\r ]*
[a-zA-Z]+	{yylval.identifier = strdup(yytext) ; return IDT;}

<<EOF>> 		{return EOF;}
%%