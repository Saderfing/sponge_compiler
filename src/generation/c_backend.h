#ifndef __C_BACKEND_H__
#define __C_BACKEND_H__
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "ast.h"


void generateCCode(ASTNode *root, FILE* outputFile);

#endif