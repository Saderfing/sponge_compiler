#include "ssa.h"
#define MAX_IDENTIFIER_SIZE 16

ASTNode *ASTToSSARec(ASTNode *root, ASTNode *ctx, uint64_t *temporaryCreation);

ASTNode *handleVariable(ASTNode *root){
	return root;
}

ASTNode *handleConstant(ASTNode *root, ASTNode *ctx, uint64_t *temporaryCreation){
	return root;
}

ASTNode *handleOperator(ASTNode *root, ASTNode *ctx, uint64_t *temporaryCreation){
	ASTNode *leftValue;
	ASTNode *rightValue;
	if (root->childCount < 1 || root->childCount > 2){
		fprintf(stderr, "Child count %dnot supported\n", root->childCount);
		exit(-1);
	}
	
	leftValue  = ASTToSSARec(root->child[0], ctx, temporaryCreation);
	rightValue = ASTToSSARec(root->child[1], ctx, temporaryCreation);

	if (rightValue->nodeType != ST_OPE){
		return root;
	}

	// TODO: Change temporary creations
	char *name = (char *)allocate(MAX_IDENTIFIER_SIZE + 1, "Allocating name for temporary");
	snprintf(name, MAX_IDENTIFIER_SIZE, "%lu", *temporaryCreation);
	(*temporaryCreation)++;
	name[MAX_IDENTIFIER_SIZE] = "\0";

	ASTNode *dest = newASTVariable(name);
	ASTNode *newRightValue = newASTVariable(strdup(name));
	root->child[1] = newRightValue;

	ASTNode *aff = newASTOperator(SO_AFF);
	addChildASTNode(aff, dest);
	addChildASTNode(aff, rightValue);
	
	addChildASTNode(ctx, aff);
	addChildASTNode(ctx, root);

	return aff;
}

ASTNode *handleContext(ASTNode *root, ASTNode *ctx, uint64_t *temporaryCreation){
	ASTNode *newContext = newASTSymbolesTable(newHashMap());
	ASTNode *subContext = newASTSymbolesTable(newHashMap());

	for (uint64_t i = 0; i < root->childCount; i++){
		subContext = ASTToSSARec(root->child[i], newContext, temporaryCreation); // TODO: Fuse symbole tables or make it global with the associated context name/id
		addChildASTNode(newContext, subContext);
	}
	printf("---------------------\n\n");
	printAST(newContext);
	return newContext;
}

ASTNode *ASTToSSARec(ASTNode *root, ASTNode *ctx, uint64_t *temporaryCreation){
		switch (root->nodeType){
		case ST_VAR:
			return handleVariable(root);

		case ST_CST:
			return handleConstant(root, ctx, temporaryCreation);

		case ST_OPE:
			return handleOperator(root, ctx, temporaryCreation);

		case ST_CTX:
			return handleContext(root, ctx, temporaryCreation);

		default:
			printAST(root);
			fatalError("Unknown node type\n", -1);
			break;
	}
	return NULL;
}

void ASTToSSA(ASTNode **root){
	uint64_t temporaryCreation = 0;
	*root = ASTToSSARec(*root, NULL, &temporaryCreation);
}