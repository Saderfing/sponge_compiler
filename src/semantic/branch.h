#ifndef __BRANCH_H__
#define __BRANCH_H__
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"

typedef enum {
	SB_IF,
	SB_ELIF,
	SB_ELSE,

	SB_WHILE,		// Not implemented
	SB_FOR,			// Not implemented
	SB_FOR_EACH,	// Not implemented

	SB_UNKOWN,
	SB_BRANCH_TYPE_COUNT
} BranchType;

#endif