#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "optimization.h"
#include "code_generation.h"
#include "parser.h" 
#include "hashmap.h"
#include "ast.h"
#include "ssa.h"


int main(int argc, char *argv[]){
	if (argc < 2){
		fatalError("Need input file", 1);
	}

	yyin = openFile(argv[1], READ_MODE);

	HashMap *currentSymTab = newHashMap();
	ASTNode *root = newASTSymbolesTable(currentSymTab);

	u32 parseCode = yyparse(root, currentSymTab);
	if (parseCode != 0){
		fatalError("Parsing failed", parseCode);
	}
	
	printAST(root);

	selectOptimization(root);

	FILE *f = openFile("a.c", "w");
	selectBackend(root, BACKEND_C, f);
	closeFile(yyin);

	return 0;
}