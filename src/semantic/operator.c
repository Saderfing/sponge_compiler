#include "operator.h"

static char *operatorRepr[] = {"+", "-", "*", "/", "%", "<<", ">>", "=", "main", "(+)"};

void printOperator(Operator op){
	if (op >= SO_UNKOWN){
		printf("UNKNOWN OPERATOR");
		return;
	}
	printf("%s", operatorRepr[op]);
}

char *getOperatorRepr(Operator op){
	if (op >= SO_UNKOWN){
		return strdup("Unkown");
	}
	
	return strdup(operatorRepr[op]);
}