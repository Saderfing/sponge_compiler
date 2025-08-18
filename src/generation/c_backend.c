#include "c_backend.h"


void generateCCode(ASTNode *root, FILE* outputFile){
	if (!root){
		return;
	}
	char *oui;

	switch (root->nodeType){
	case ST_VAR:
		if (root->data.variable.name){
			fprintf(outputFile, "var_%s", root->data.variable.name);
		}
		break;

	case ST_CST:
		fprintf(outputFile, "%lx", root->data.value);
		break;
	
	case ST_OPE:
		oui = getOperatorRepr(root->data.operator);

		if (root->data.operator == SO_AFF){
			fprintf(outputFile, "int ");
		}

		generateCCode(root->child[0], outputFile);
		fprintf(outputFile, " %s ", getOperatorRepr(root->data.operator));
		generateCCode(root->child[1], outputFile);

		free(oui);
		break;

	case ST_CTX:
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
