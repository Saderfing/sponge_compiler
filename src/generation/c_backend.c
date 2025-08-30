#include "c_backend.h"

char *getCReprOperator(Operator op){
	static const char *COperatorRepr[] = {"+", "-", "*", "/", "%", "<<", ">>", "=", "==", ">", "<", ">=", "<=", "&&", "||", "!"};

	if (op >= SO_UNKOWN){
		fatalError("Unsupported operator for C\n", -1);
	}

	return COperatorRepr[op];
}


void generateCCodeRec(ASTNode *root, uint64_t depth, FILE* outputFile){
	if (!root){
		printf("Error: NULL ASTNode passed to generateCCodeRec\n");
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
		fprintf(outputFile, "%ld", root->data.value);
		break;
	
	case ST_OPE:
		printf("Generating C code for operator: %s\n", getCReprOperator(root->data.operator));
		if (root->data.operator == SO_AFF){
			fprintf(outputFile, "int ");
		}

		generateCCodeRec(root->child[0], 0, outputFile);
		fprintf(outputFile, " %s ", getCReprOperator(root->data.operator));
		generateCCodeRec(root->child[1], 0, outputFile);

		break;

	case ST_CTX:
		printf("Generating C code for context\n%lu\n", root->childCount);

		if (root->parent == NULL && root->data.context.name == NULL){
			fprintf(outputFile, "int main(int argc, char *argv[]){\n\t");
			for (uint64_t i = 0; i < root->childCount; i++){
				generateCCodeRec(root->child[i], depth, outputFile);
				fprintf(outputFile, ";\n\t");
			}
			fprintf(outputFile, "return 0;\n}");
		} else {
			for (uint64_t i = 0; i < root->childCount; i++){
				generateCCodeRec(root->child[i], depth, outputFile);
				fprintf(outputFile, ";\n\t");
			}
		}

		break;

	case ST_BCH:
		printf("Generating C code for branch\n%lu\n", root->childCount);
		
		switch (root->data.branchType){
			case SB_IF  : 
				fprintf(outputFile, "if ");
				for (uint64_t i = 0; i < root->childCount; i++){
					if (root->child[i]->nodeType == ST_OPE){
						fprintf(outputFile, "(");
						generateCCodeRec(root->child[i], depth, outputFile);
						fprintf(outputFile, ")");
					} else if (root->child[i]->nodeType == ST_CTX){
						fprintf(outputFile, "{\n\t");
						generateCCodeRec(root->child[i], depth + 1, outputFile);
						fprintf(outputFile, "}");
					} else {
						generateCCodeRec(root->child[i], depth, outputFile);
					}
				}
				break;

			case SB_ELIF:
				fprintf(outputFile, "else if ");
				for (uint64_t i = 0; i < root->childCount; i++){
					if (root->child[i]->nodeType == ST_OPE){
						fprintf(outputFile, "(");
						generateCCodeRec(root->child[i], depth, outputFile);
						fprintf(outputFile, ")");
					} else if (root->child[i]->nodeType == ST_CTX){
						fprintf(outputFile, "{\n\t");
						generateCCodeRec(root->child[i], depth + 1, outputFile);
						fprintf(outputFile, "}");
					} else {
						generateCCodeRec(root->child[i], depth, outputFile);
					}
				}
				break;

			case SB_ELSE:
				fprintf(outputFile, "else ");
				for (uint64_t i = 0; i < root->childCount; i++){
					fprintf(outputFile, "{\n\t");
					generateCCodeRec(root->child[i], depth + 1, outputFile);
					fprintf(outputFile, "}");
				}
				break;

			default: fatalError("Unsupported branch type\n", -1);
		}

		break;

	default:
		printf("Unknown value");
		break;
	}
	return;
}

void generateCCode(ASTNode *root, FILE* outputFile){
	generateCCodeRec(root, 0, outputFile);
}