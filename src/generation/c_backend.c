#include "c_backend.h"

char *getCReprOperator(Operator op){
	static const char *COperatorRepr[] = {"+", "-", "*", "/", "%", "<<", ">>", "=", "==", ">", "<", ">=", "<=", "&&", "||", "!"};

	if (op >= SO_UNKOWN){
		fatalError("Unsupported operator for C\n", -1);
	}

	return COperatorRepr[op];
}


void generateCCode(ASTNode *root, FILE* outputFile){
	if (!root){
		printf("Error: NULL ASTNode passed to generateCCode\n");
		return;
	}

	switch (root->nodeType){
	case ST_VAR:
		printf("Generating C code for variable: %s\n", root->data.variable.name);
		if (root->data.variable.name){
			fprintf(outputFile, "var_%s", root->data.variable.name);
		}
		break;

	case ST_CST:
		printf("Generating C code for constant: %lu\n", root->data.value);
		fprintf(outputFile, "%lx", root->data.value);
		break;
	
	case ST_OPE:
		printf("Generating C code for operator: %s\n", getCReprOperator(root->data.operator));
		if (root->data.operator == SO_AFF){
			fprintf(outputFile, "int ");
		}

		generateCCode(root->child[0], outputFile);
		fprintf(outputFile, " %s ", getCReprOperator(root->data.operator));
		generateCCode(root->child[1], outputFile);

		break;

	case ST_CTX:
		printf("Generating C code for context\n%lu\n", root->childCount);
		fprintf(outputFile, "int main(int argc, char *argv[]){\n\t");
		for (uint64_t i = 0; i < root->childCount; i++){
			generateCCode(root->child[i], outputFile);
			fprintf(outputFile, ";\n\t");
		}
		fprintf(outputFile, "return 0;\n}");
		break;

	default:
		printf("Unknown value");
		break;
	}
	// printf("}");
}
