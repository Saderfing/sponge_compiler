#ifndef __AST_H__
#define __AST_H__
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"

#include "context.h"
#include "variable.h"
#include "operator.h"
#include "hashmap.h"
#include "branch.h"
#include "type.h"

#define NEW_EMPTY_DATA() (Data){0}

typedef enum {
	ST_VAR,		// Variables
	ST_CST,		// Constants
	ST_OPE,		// Operator
	ST_BCH,		// Conditional / Branch
	ST_CTX,		// Context / Basic block
	ST_NOT_A_NODETYPE, // Error value
	ST_TYPE_COUNT	   // Number of node types
} NodeType;

typedef union ast{
	Variable variable;		// nodeType == ST_VAR
	Context context;		// nodeType == ST_CTX
	Operator operator;		// nodeType == ST_OPE
	uint64_t value;			// nodeType == ST_CST
	BranchType branchType;	// nodeType == ST_BCH
} Data;

typedef struct node{
	NodeType nodeType; 	// Type of the node
	Data data;			// Optional data associated with the node

	uint64_t sizeAllocated; // Size allocated in the dynamic array
	uint64_t childCount;	// Number of children
	struct node **child; 	// Table of pointer to nodes

	struct node *parent;	// NULL if root
} ASTNode;

ASTNode *newASTNode(NodeType nodeType, Data data);

ASTNode *newASTContext(char *name, HashMap *symboleTable);

ASTNode *newASTBranch();

ASTNode *newASTOperator(Operator op);

ASTNode *newASTConstant(uint64_t con);

ASTNode *newASTVariable(char *varNam);

void addChildASTNode(ASTNode *root, ASTNode *child);

void popChildASTNode(ASTNode *root);

void printASTNode(ASTNode *node);

void printAST(ASTNode *root);

void freeAST(ASTNode *node);

#endif