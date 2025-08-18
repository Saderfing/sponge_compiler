#ifndef _VARIABLE_H_
#define _VARIABLE_H_
#include "sponge_std.h"
#include "type.h"

typedef struct {
	char *name;
	Type type;
	bool defined;
	int64_t value;
} Variable;

Variable newVariable(char *name, Type type, bool defined, int64_t value);

Variable newEmptyVariable(char *name);

void setVariableName(char *name, Variable v);

void printVariable(Variable *var);

#endif