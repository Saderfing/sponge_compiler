#ifndef __AST_H__
#define __AST_H__
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "variable.h"
#include "operator.h"
#include "hashmap.h"
#include "type.h"

typedef enum {
	ST_VAR,
	ST_CST,
	ST_OPE,
	ST_CTX,
	ST_NOT_A_NODETYPE,
	ST_TYPE_COUNT
} NodeType;

typedef union ast{
	Variable variable;
	HashMap *symboles;
	Operator operator;
	uint64_t value;
} Data;

typedef struct node{
	NodeType nodeType; 
	Data data;

	uint64_t sizeAllocated;
	uint64_t childCount;
	struct node **child;
} ASTNode;

ASTNode *newASTNode(NodeType nodeType, Data data);

ASTNode *newASTOperator(Operator op);

ASTNode *newASTConstant(uint64_t con);

ASTNode *newASTVariable(char *varNam);

ASTNode *newASTSymbolesTable(HashMap *symboleTable);

void addChildASTNode(ASTNode *root, ASTNode *child);

void popChildASTNode(ASTNode *root);

void printASTNode(ASTNode *node);

void printAST(ASTNode *root);

void freeAST(ASTNode *node);

#endif