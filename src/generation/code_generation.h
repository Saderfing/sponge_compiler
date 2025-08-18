#ifndef _CODE_GENERATION_H_
#define _CODE_GENERATION_H_
#include <stdio.h>
#include <stdlib.h>
#include "instruction_stream.h"
#include "sponge_std.h"
#include "c_backend.h"
#include "operator.h"
#include "ast.h"

typedef enum{
	BACKEND_C,
	BACKEND_NASM,

	UNKOWN_BACKEND,
	BACKEND_COUNT
} Backend;

void selectBackend(ASTNode *root, Backend backend, FILE *outputFile);

#endif