#include "variable.h"

Variable newVariable(char *name, Type type, bool defined, int64_t value){
	if (!name){
		name = "\0";
	}

	Variable v;
	v.name		= strdup(name);
	v.type		= type;
	v.defined	= defined;
	v.value		= value;
	return v;
}

Variable newEmptyVariable(char *name){
	return newVariable(name, NEW_INT(), false, 0);
}

void setVariableName(char *name, Variable v){
	if (!name){
		name = "\0";
	}

	if (v.name){
		free(v.name);
	}

	v.name = strdup(name);
}

void printVariable(Variable *var){
	printType(var->type);
	printf(" %s = ", var->name);
	
	if (var->defined){
		printf("%lx", var->value);
	} else {
		printf("UNDEFINED");
	}
}