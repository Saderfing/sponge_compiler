%option nounput noinput noyywrap
%option yylineno

%{
	#include "operator.h"
	#include "hashmap.h"
	#include "parser.h"
	#include "ast.h"
%}

DIGIT [0-9]

%x COMMENTS
%x MULTILINE_COMMENTS

%%

"//"				{BEGIN(COMMENTS);}
<COMMENTS>[^\n]*	{/* skip */}
<COMMENTS>\n		{BEGIN(INITIAL);}


"/*"						{BEGIN(MULTILINE_COMMENTS);}
<MULTILINE_COMMENTS>"*/"	{BEGIN(INITIAL);}
<MULTILINE_COMMENTS>\n		{yylineno++;}
<MULTILINE_COMMENTS>.


-?{DIGIT}+	{yylval.node = newASTConstant(strtoul(yytext, NULL, 0)); return CST;}
 

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

"and"|"&&"	{yylval.node = newASTOperator(SO_AND); return PB_AND;}
"or"|"||"	{yylval.node = newASTOperator(SO_OR);  return PB_OR; }
"not"|"!"	{yylval.node = newASTOperator(SO_NOT); return PB_NOT;}

"if"		{return PB_IF;  }
"elif"		{return PB_ELIF;}
"else"		{return PB_ELSE; return PB_ELSE;}

";"			{return SEMICOLON;}
"("			{return LEFT_BRACKET;}
")"			{return RIGHT_BRACKET;}
"{"			{return LEFT_BRACE;}
"}"			{return RIGHT_BRACE;}

[\t\n\r ]*
[a-zA-Z]+	{yylval.identifier = strdup(yytext) ; return IDT;}

<<EOF>> 		{return EOF;}
%%