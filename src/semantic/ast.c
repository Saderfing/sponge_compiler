#include "ast.h"

/**
 * @brief Create a new AST node with the given type and data.
 *
 * @param nodeType Type of the AST node
 * @param data Data associated with the node
 * @return Pointer to the newly created ASTNode
 */
ASTNode *newASTNode(NodeType nodeType, Data data){
	ASTNode *node = (ASTNode *)allocate(sizeof(ASTNode), "Allocating new ASTNode");
	
	node->nodeType = nodeType;
	node->data = data;
	node->sizeAllocated = 0;
	node->childCount = 0;
	node->child = NULL;
	node->parent = NULL;
	
	return node;
}

/**
 * @brief Creates a new AST context node. (e.g., function or block)
 *
 * @param name Name of the context (function name or NULL for anonymous)
 * @param symboles Symbol table associated with the context
 * @return Pointer to the newly created ASTNode representing the context
 */
ASTNode *newASTContext(char *name, HashMap *symboles){
	Data data = NEW_EMPTY_DATA();
	data.context = newContext(name, symboles);
	return newASTNode(ST_CTX, data);
}

/**
 * @brief Creates a new AST branch node (conditional/branch).
 *
 * @return Pointer to the newly created ASTNode representing a branch.
 */
ASTNode *newASTBranch(BranchType branchType){
	Data data = NEW_EMPTY_DATA();
	data.branchType = branchType;
	return newASTNode(ST_BCH, data);
}

/**
 * @brief Creates a new AST operator node.
 *
 * @param op Operator to associate with the node.
 * @return Pointer to the newly created ASTNode representing an operator.
 */
ASTNode *newASTOperator(Operator op){
	Data data = NEW_EMPTY_DATA();
	data.operator = op;
	return newASTNode(ST_OPE, data);
}

/**
 * @brief Creates a new AST constant node.
 *
 * @param constant Constant value to store in the node.
 * @return Pointer to the newly created ASTNode representing a constant.
 */
ASTNode *newASTConstant(uint64_t constant){
	Data data = NEW_EMPTY_DATA();
	data.value = constant;
	return newASTNode(ST_CST, data);
}

/**
 * @brief Creates a new AST variable node.
 *
 * @param varName Name of the variable.
 * @return Pointer to the newly created ASTNode representing a variable.
 */
ASTNode *newASTVariable(char *varName){
	Data data = NEW_EMPTY_DATA();
	Variable v = newVariable(varName, NEW_INT(), false, 0);
	data.variable = v;
	return newASTNode(ST_VAR, data);
}

int8_t allocateChild(ASTNode *node){
	if (!node || node->childCount + 1 < node->sizeAllocated){
		return 0;
	}

	uint64_t sizeToAlloc = 0;
	ASTNode **newASTNode = NULL;
	if (node->sizeAllocated == 0){
		sizeToAlloc = 1;
	} else {
		sizeToAlloc = 2 * node->sizeAllocated;
	}

	newASTNode = (ASTNode **)realloc(node->child, sizeToAlloc * sizeof(ASTNode *));
	if (!newASTNode){
		fatalError("allocation failed for new child", -1);
	}

	node->child = newASTNode;
	node->sizeAllocated = sizeToAlloc;
	return 0;
}

/**
 * @brief Removes and frees the last added child node from the given AST node.
 *
 * @param root Pointer to the ASTNode from which to pop the child.
 */
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

/**
 * @brief Adds a child node to the given AST node.
 *
 * @param root Pointer to the parent ASTNode.
 * @param child Pointer to the child ASTNode to add.
 */
void addChildASTNode(ASTNode *root, ASTNode *child){
	if (!root || !child){
		return;
	}

	if (root->childCount + 1 >= root->sizeAllocated && allocateChild(root) != 0){
		fatalError("Cannot allocate AST", -1);
	}

	root->child[root->childCount] = child;
	child->parent				  = root;
	root->childCount++;
}

void squachIfStatements(ASTNode *ifNode, ASTNode *root){
	if (!root){
		return;
	}

	if (root->nodeType == ST_BCH){
		for (uint64_t i = 0; i < root->childCount; i++){
			
		}
	}
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
		printVariable(&(node->data.variable));
		break;

	case ST_CST:
		printf("\n-=[ Constant ]=-\nvalue : %ld\n----------", node->data.value);
		break;
	
	case ST_OPE:
		printOperator(node->data.operator);
		break;

	case ST_CTX:
		printContext(node->data.context);
		break;

	case ST_BCH:
		printf("\n-=[ Branch ]=-\n%ld\n------------\n", node->childCount);

		break;

	default:
		printf("Unknown value");
		break;
	}
}

/**
 * @brief Recursively prints the AST starting from the given root node.
 *
 * @param root Pointer to the root ASTNode.
 */
void printAST(ASTNode *root){
	if (!root){
		return;
	}
	
	printASTNode(root);

	for (uint64_t i = 0; i < root->childCount ; i++){
		printAST(root->child[i]);
	}
}

void freeASTNode(ASTNode *node){
	if (!node){
		return;
	}

	switch (node->nodeType){
	case ST_VAR:
		free(node->data.variable.name);
		break;

	case ST_CST:
	case ST_OPE:
	case ST_BCH:
		break;

	case ST_CTX:
		freeContext(&(node->data.context));
		break;

	default:
		break;
	}
}

void freeAST(ASTNode *node){
	if (!node){
		return;
	}

	for (uint64_t i = 0; i < node->childCount; i++){
		freeAST(node->child[i]);
	}

	freeASTNode(node);
	free(node->child);
	free(node);
}