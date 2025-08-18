#ifndef __NASM_BACKEND_H__
#define __NASM_BACKEND_H__
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "ast.h"
#include "instruction_stream.h"


void generateNasmCode(ASTNode *root, FILE *outputFile);

#endif