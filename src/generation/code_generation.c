#include "code_generation.h"

void selectBackend(ASTNode *root, Backend backend, FILE *outputFile){
	switch (backend){
		case BACKEND_C:
			generateCCode(root, outputFile);
			break;

		case BACKEND_NASM:
			generateNasmCode(root, outputFile);
			break;


		default:
			fatalError("Unsupported backend\n", -1);
	}
}