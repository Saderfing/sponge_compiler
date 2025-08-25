#include "ast.h"

ASTNode *newASTNode(NodeType nodeType, Data data){
	ASTNode *node = (ASTNode *)allocate(sizeof(ASTNode), "Allocating new ASTNode");
	
	node->nodeType = nodeType;
	node->data = data;
	node->sizeAllocated = 0;
	node->childCount = 0;
	node->child = NULL;
	debug("Creating node");
	printASTNode(node);
	
	return node;
}

ASTNode *newASTOperator(Operator op){
	Data data;
	data.operator = op;
	return newASTNode(ST_OPE, data);
}

ASTNode *newASTConstant(uint64_t constant){
	Data data;
	data.value = constant;
	return newASTNode(ST_CST, data);
}

ASTNode *newASTVariable(char *varName){
	Data data;
	Variable v = newVariable(varName, NEW_INT(), false, 0);
	data.variable = v;
	return newASTNode(ST_VAR, data);
}

ASTNode *newASTSymbolesTable(HashMap *symboleTable){
	Data data;
	data.symboles = symboleTable;
	return newASTNode(ST_CTX, data);
}

int8_t allocateChild(ASTNode *node){
	if (!node || !node->childCount + 1 < node->sizeAllocated){
		return 0;
	}

	uint64_t sizeToAlloc = 0;
	ASTNode **newASTNode = NULL;
	if (node->childCount == 0){
		sizeToAlloc = 1;
	} else {
		sizeToAlloc = 2 * node->childCount;
	}

	newASTNode = (ASTNode **)realloc(node->child, sizeToAlloc * sizeof(ASTNode *));
	if (!newASTNode){
		fatalError("allocation failed for new child", -1);
	}

	node->child = newASTNode;
	node->sizeAllocated = sizeToAlloc;
	return 0;
}

void popChildASTNode(ASTNode *root){
	if (!root){
		fatalError("Cannot pop empty AST\n", -1);
	}

	if (root->childCount == 0){
		fatalError("Cannot apply pop on leaves of the AST\n", -1);
	}

	root->childCount--;
	freeAST(root->child[root->childCount]);
	root->child[root->childCount] = NULL;
}

void addChildASTNode(ASTNode *root, ASTNode *child){
	if (!root || !child){
		return;
	}

	if (root->childCount + 1 >= root->sizeAllocated && allocateChild(root) != 0){
		fatalError("Cannot allocate AST", -1);
	}

	root->child[root->childCount] = child;
	root->childCount++;
}


static char *nodeTypeRepr[] = {"Variable", "Constant", "Operator"};

void printNodeType(NodeType op){
	if (op >= ST_NOT_A_NODETYPE){
		printf("UNKNOWN NODE_TYPE");
		return;
	}
	printf("%s", nodeTypeRepr[op]);
}

void printASTNode(ASTNode *node){
	if (!node){
		return;
	}

	switch (node->nodeType){
	case ST_VAR:
		if (node->data.variable.name){
			printf("%s", node->data.variable.name);
		} else {
			printf("No Name");
		}
		break;

	case ST_CST:
		printf("%lx", node->data.value);
		break;
	
	case ST_OPE:
		printOperator(node->data.operator);
		break;

	case ST_CTX:
		printHashMap(node->data.symboles);
		break;

	default:
		printf("Unknown value");
		break;
	}
}

void printAST(ASTNode *root){
	if (!root){
		return;
	}
	
	for (uint64_t i = 0; i < root->childCount / 2; i++){
		printAST(root->child[i]);
		if (root->nodeType == ST_CTX){
			printf(";\n");
		}
	}

	if (root->nodeType != ST_CTX){
		printASTNode(root);
	}

	for (uint64_t i = root->childCount / 2; i < root->childCount ; i++){
		printAST(root->child[i]);
		if (root->nodeType == ST_CTX){
			printf(";\n");
		}
	}
}

void freeAST(ASTNode *node){
	if (!node){
		return;
	}

	for (uint64_t i = 0; i < node->childCount; i++){
		freeAST(node->child[i]);
	}

	if (node->nodeType == ST_VAR){
		free(node->data.variable.name);
	}
	free(node->child);
	free(node);
}