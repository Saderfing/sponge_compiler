%code requires{
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
}

%code top{
	#include "parser.h"
	extern int yylex();
	int yyerror(ASTNode **root, char *s);
	int yydebug = 1;
}

%union {
	int64_t integer;
	Operator operator;
	char *identifier;

	ASTNode *node;
}

%token <node> CST 
%token <identifier> IDT
%token <node> PO_ADD PO_SUB PO_MUL PO_DIV PO_AFF PR_EQ PR_GT PR_GE PR_LT PR_LE PB_AND PB_OR PB_NOT
%token <node> PB_IF PB_ELIF PB_ELSE
%token SEMICOLON LEFT_BRACKET RIGHT_BRACKET LEFT_BRACE RIGHT_BRACE

%precedence PO_AFF
%left PB_AND PB_OR
%precedence PB_NOT
%left PO_ADD PO_SUB
%left PO_MUL PO_DIV

%type <node> expr program bool_expr context if_statement optional_if

%destructor { free($$); } <identifier>

%start program

%parse-param {ASTNode **root}
%%

program:context	{*root = $1;}
	;

context:%empty						{$$ = newASTContext(NULL, newHashMap());}
	|context bool_expr SEMICOLON	{$$ = $1; addChildASTNode($$, $2);}
	|context expr SEMICOLON 		{$$ = $1; addChildASTNode($$, $2);}
	|context if_statement 			{$$ = $1; addChildASTNode($$, $2);}
	;

if_statement:
	PB_IF bool_expr LEFT_BRACE context RIGHT_BRACE optional_if		{$$ = newASTBranch(SB_IF); addChildASTNode($$, $2); addChildASTNode($$, $4); addChildASTNode($$, $6); squachIfStatement($$);}
	;

optional_if: %empty													{$$ = NULL;}
	|PB_ELIF bool_expr LEFT_BRACE context RIGHT_BRACE optional_if	{$$ = newASTBranch(SB_ELIF); addChildASTNode($$, $2); addChildASTNode($$, $4); addChildASTNode($$, $6);}
	|PB_ELSE LEFT_BRACE context RIGHT_BRACE							{$$ = newASTBranch(SB_ELSE); addChildASTNode($$, $3);}

bool_expr:
	 expr PR_EQ expr						{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
	|expr PR_GT expr						{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
	|expr PR_GE expr						{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
	|expr PR_LT expr						{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
	|expr PR_LE expr						{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
	|bool_expr PB_AND bool_expr				{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
	|bool_expr PB_OR bool_expr				{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
	|LEFT_BRACKET bool_expr RIGHT_BRACKET	{$$ = $2;}
	|PB_NOT bool_expr						{$$ = $2; addChildASTNode($$, $2);}
	;

expr:
	 IDT  PO_AFF expr					{$$ = $2; addChildASTNode($$, newASTVariable($1)); addChildASTNode($$, $3); free($1);}
	|expr PO_ADD expr					{if ($1->nodeType == ST_CST && $3->nodeType == ST_CST){$$ = newASTConstant($1->data.value + $3->data.value); freeAST($1); freeAST($2); freeAST($3);} else {$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}}
	|expr PO_SUB expr					{if ($1->nodeType == ST_CST && $3->nodeType == ST_CST){$$ = newASTConstant($1->data.value - $3->data.value); freeAST($1); freeAST($2); freeAST($3);} else {if ($3->nodeType == ST_CST) {freeAST($2); $$ = newASTOperator(SO_ADD); addChildASTNode($$, $1); addChildASTNode($$, newASTConstant(- $3->data.value)); freeAST($3);} else {addChildASTNode($$, $3);}}}
	|expr PO_MUL expr					{if ($1->nodeType == ST_CST && $3->nodeType == ST_CST){$$ = newASTConstant($1->data.value * $3->data.value); freeAST($1); freeAST($2); freeAST($3);} else {$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}}
	|expr PO_DIV expr					{if ($1->nodeType == ST_CST && $3->nodeType == ST_CST){$$ = newASTConstant($1->data.value / $3->data.value); freeAST($1); freeAST($2); freeAST($3);} else {$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}}
	|LEFT_BRACKET expr RIGHT_BRACKET	{$$ = $2;}
	|CST								{$$ = $1;}
	|IDT								{$$ = newASTVariable($1); free($1);}
	;

%%

int yyerror(ASTNode **root,  char *s) {
	printAST(*root);
	fprintf(stderr, "\n\n\n--------------------------------------\nErreur: %s at line : %d\n--------------------------------------\n", s, yylineno);
	return 0;
}
