#ifndef __TYPE_H__
#define __TYPE_H__
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"

typedef enum {
	STY_VOID,
	STY_INT,
	STY_BOOL,
	STY_UNDEFINED,
	STY_TYPE_COUNT
} TypeName;

typedef struct {
	TypeName name;
	uint64_t size;
} Type;

void printType(Type t);

#define NEW_TYPE(typeName, typeSize) (Type){.name = typeName, .size = typeSize}

#define NEW_INT() NEW_TYPE(STY_INT, 64)
#define NEW_VOID() NEW_TYPE(STY_VOID, 0)
#define NEW_UNDEFINED() NEW_TYPE(STY_UNDEFINED, 0)

#endif