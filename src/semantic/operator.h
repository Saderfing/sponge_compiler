#ifndef __OPERATOR_H__
#define __OPERATOR_H__
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"

typedef enum {
	SO_ADD,
	SO_SUB,
	SO_MUL,
	SO_DIV,
	SO_REM,
	SO_LSL,
	SO_LSR,
	SO_AFF,

	SO_EQ,
	SO_GT,
	SO_LT,
	SO_GE,
	SO_LE,

	SB_AND,
	SB_OR,
	SB_NOT,
	
	SO_ROOT,
	SO_EXPR,
	SO_UNKOWN,
	SO_OPERATOR_COUNT
} Operator;

void printOperator(Operator op);

char *getOperatorRepr(Operator op);

#endif