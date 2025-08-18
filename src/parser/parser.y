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
	int yyerror(ASTNode *root, HashMap *currentSymboleTable, char *s);
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
%token SEMICOLON LB RB


%precedence PO_AFF
%left PO_AND PO_OR
%precedence PB_NOT
%left PO_ADD PO_SUB
%left PO_MUL PO_DIV

%nterm <node> expr program bool_expr program

%printer { fprintf(yyo, "%s", $$); } <identifier>
%printer { printASTNode($$); } <node>

%start program

%parse-param {ASTNode *root} {HashMap *currentSymboleTable}
%%

program:%empty					{$$ = NULL;}
	|program expr SEMICOLON		{addChildASTNode(root, $2);}
	;

/* // bool_expr:
// 	|expr PR_EQ expr			{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
// 	|expr PR_GT expr			{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
// 	|expr PR_GE expr			{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
// 	|expr PR_LT expr			{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
// 	|expr PR_LE expr			{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
// 	|bool_expr PB_AND bool_expr	{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
// 	|bool_expr PB_OR bool_expr	{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
// 	|expr PB_AND expr			{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
// 	|expr PB_OR expr			{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}
// 	|PB_NOT bool_expr			{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $2);}
// 	|PB_NOT expr				{$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $2);}
// 	; */

expr:
	 IDT PO_AFF expr			{$$ = $2; addChildASTNode($$,  newASTVariable($1)); appendHashMap($1, currentSymboleTable->length, currentSymboleTable); addChildASTNode($$, $3);}
	|expr PO_ADD expr			{if ($1->nodeType == ST_CST && $3->nodeType == ST_CST){$$ = newASTConstant($1->data.value + $3->data.value);} else {$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}}
	|expr PO_SUB expr			{if ($1->nodeType == ST_CST && $3->nodeType == ST_CST){$$ = newASTConstant($1->data.value - $3->data.value);} else {$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}}
	|expr PO_MUL expr			{if ($1->nodeType == ST_CST && $3->nodeType == ST_CST){$$ = newASTConstant($1->data.value * $3->data.value);} else {$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}}
	|expr PO_DIV expr			{if ($1->nodeType == ST_CST && $3->nodeType == ST_CST){$$ = newASTConstant($1->data.value / $3->data.value);} else {$$ = $2; addChildASTNode($$, $1); addChildASTNode($$, $3);}}
	|LB expr RB					{$$ = $2;}
	|CST						{$$ = $1;}
	|IDT						{(inHashMap($1, currentSymboleTable)) ? $$ = newASTVariable($1) : fatalError("Used before assignation", 1);}
	;

%%

int yyerror(ASTNode *root, HashMap *currentSymboleTable, char *s) {
	printAST(root);
	fprintf(stderr, "Erreur: %s at line : %d\n", s, yylineno);
	return 0;
}
