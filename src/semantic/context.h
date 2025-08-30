#ifndef __CONTEXT_H__
#define __CONTEXT_H__
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "hashmap.h"

#define NEW_EMPTY_CONTEXT() (Context){NULL, NULL}

typedef struct context{
	char *name;		// \0-terminated string if function, NULL for anonymous context such as if
	HashMap *symboles;
} Context;

Context newContext(char *name, HashMap *symboles);

void printContext(Context context);

#endif