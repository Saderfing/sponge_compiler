#include "nasm_backend.h"

#define WRITE_TEXT_SECTION(outputFile)				fprintf(outputFile, "section .text\n")
#define WRITE_LABEL_DEFINITION(outputFile, label)	fprintf(outputFile, "global %s\n", label)
#define WRITE_LABEL(outputFile, label)				fprintf(outputFile, "%s:", label)

void generateTextSection(ASTNode *root, FILE *outputFile){
	WRITE_LABEL_DEFINITION(outputFile, "_start");
	WRITE_TEXT_SECTION(outputFile);
	WRITE_LABEL(outputFile, "_start");

	generateTextSectionContent(root, outputFile);
}

void generateNasmCode(ASTNode *root, FILE *outputFile){
	
	generateTextSection(root, outputFile);
}