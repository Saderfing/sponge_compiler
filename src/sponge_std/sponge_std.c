#include "sponge_std.h"

int memUsage = 0;

void fatalError(char *msg, int code){
	printf("[ %s Fatal Error %s ] : %s\n", F_RED, F_WHITE, msg);
	exit(code);
}

void *allocate(size_t size, char *message){
	// Fonction qui permet d'allouer de la mémoire (malloc) (utile pour le debug)
	void *p;
	
	p = malloc((unsigned long)size);
	if (p == NULL){
		fprintf(stderr,"Can't allocate %ld bytes for '%s' \n", size, message);
		fatalError("Allocate error", -1);
	}
	
	memUsage += size;

	return p;    
}