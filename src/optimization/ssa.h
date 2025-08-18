#ifndef __SSA_H__
#define __SSA_H__
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "ast.h"

void ASTToSSA(ASTNode **root);

#endif