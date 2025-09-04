#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "optimization.h"
#include "code_generation.h"
#include "parser.h" 
#include "lexer.h"
#include "hashmap.h"
#include "ast.h"
#include "ssa.h"

void buildSymboleTableRec(ASTNode *root, HashMap *currentSymboleTable){
	if (!root){
		return;
	}

	switch (root->nodeType){
	case ST_VAR:
		appendHashMap(GET_VARIABLE_NAME(root), 0, currentSymboleTable);
		return;
	
	case ST_CTX:
		for (uint64_t i = 0; i < root->childCount; i++){
			buildSymboleTableRec(root->child[i], root->data.context.symboles);
		}
		return;

	case ST_CST:
		return;
	
	case ST_BCH:
	case ST_OPE:
		for (uint64_t i = 0; i < root->childCount; i++){
				buildSymboleTableRec(root->child[i], currentSymboleTable);
		}
		return;

	default:
		fatalError("Error: Unknown node type in the AST", -1);
	}
}

void buildSymboleTable(ASTNode *root){
	if (!root){
		return;
	}
	
	if (root->nodeType != ST_CTX){
		printf("\n---------Root not a context---------\n");
		printAST(root);
		fatalError("Root should be a context", -1);
	}

	buildSymboleTableRec(root, root->data.context.symboles);
}

int main(int argc, char *argv[]){
	if (argc < 2){
		fatalError("Need input file", 1);
	}

	yyin = openFile(argv[1], READ_MODE);

	ASTNode *root = NULL;
	u32 parseCode = yyparse(&root);
	if (parseCode != 0){
		fatalError("Parsing failed", parseCode);
	}
	buildSymboleTable(root);

	selectOptimization(root);
	
	printAST(root);

	FILE *f = openFile("a.c", "w");
	selectBackend(root, BACKEND_C, f);

	closeFile(yyin);
	closeFile(f);

	yylex_destroy();
	freeAST(root);

	return 0;
}