#include "type.h"

static char *typeRepr[] = {"void", "int", "bool"};

void printType(Type type){
	if (type.name >= STY_UNDEFINED){
		printf("UNKNOWN TYPE");
		return;
	}
	printf("%s", typeRepr[type.name]);
}