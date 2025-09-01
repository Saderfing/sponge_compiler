#include "context.h"

Context newContext(char *name, HashMap *symboles){
	return (Context){name ? strdup(name) : NULL, symboles};
}

void setContextName(char *name, Context *c){
	if (c->name){
		free(c->name);
	}
	c->name = name;
}

void printContext(Context context){
	printf("\n-=[ Context ]=-\n");
	if (context.name){
		printf("Name : %s\n", context.name);
	}

	if (context.symboles){
		printHashMap(context.symboles);
	}
	printf("\n-=-=-=-\n");
}

void freeContext(Context *context){
	free(context->name);
	freeHashMap(context->symboles);
	context->name = NULL;
	context->symboles = NULL;
}