#include "c_backend.h"

char *getCReprOperator(Operator op){
	static const char *COperatorRepr[] = {"+", "-", "*", "/", "%", "<<", ">>", "=", "==", ">", "<", ">=", "<=", "&&", "||", "!"};

	if (op >= SO_UNKOWN){
		fatalError("Unsupported operator for C\n", -1);
	}

	return COperatorRepr[op];
}

#define CONDITIONNAL_PREFIX(index) (index <= 1) ? "if" : "else if"


void generateCCodeRec(ASTNode *root, uint64_t depth, FILE* outputFile){
	if (!root){
		printf("Error: NULL ASTNode passed to generateCCodeRec\n");
		return;
	}

	switch (root->nodeType){
	case ST_VAR:
		printf("Generating C code for variable: %s\n", GET_VARIABLE_NAME(root));
		if (GET_VARIABLE_NAME(root)){
			fprintf(outputFile, "var_%s", GET_VARIABLE_NAME(root));
		}
		break;

	case ST_CST:
		printf("Generating C code for constant: %lu\n", GET_CONSTANT_VALUE(root) );
		fprintf(outputFile, "%ld", GET_CONSTANT_VALUE(root) );
		break;
	
	case ST_OPE:
		printf("Generating C code for operator: %s\n", getCReprOperator(GET_OPERATOR(root)));
		if (GET_OPERATOR(root) == SO_AFF){
			fprintf(outputFile, "int ");
		}

		generateCCodeRec(root->child[0], 0, outputFile);
		fprintf(outputFile, " %s ", getCReprOperator(GET_OPERATOR(root)));
		generateCCodeRec(root->child[1], 0, outputFile);

		break;

	case ST_CTX:
		printf("Generating C code for context\n%lu\n", root->childCount);

		if (root->parent == NULL && GET_CONTEXT_NAME(root) == NULL){
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
		
		switch (GET_BRANCH_TYPE(root) ){
			case SB_IF: 
				
				for (uint64_t i = 0; i < root->childCount - (root->childCount % 2); i += 2){
					fprintf(outputFile, CONDITIONNAL_PREFIX(i));
					
					fprintf(outputFile, "(");
					generateCCodeRec(root->child[i], depth, outputFile);
					fprintf(outputFile, ")");
					fprintf(outputFile, "{\n\t");
					generateCCodeRec(root->child[i + 1], depth + 1, outputFile);
					fprintf(outputFile, "}");
				}
				
				if ((root->childCount % 2) == 1){
					fprintf(outputFile, "else");
					fprintf(outputFile, "{\n\t");
					generateCCodeRec(root->child[root->childCount - 1], depth + 1, outputFile);
					fprintf(outputFile, "}");
				}

				break;

			case SB_ELIF:
			case SB_ELSE:
				fatalError("Unknown branch type for C code generation\n", -1);
				break;

			default:
				break;
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