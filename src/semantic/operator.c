#include "operator.h"	

static const char *operatorRepr[] = {"+", "-", "*", "/", "%", "<<", ">>", "=", "==", ">", "<", ">=", "<=", "and", "or", "not"};

void printOperator(Operator op){
	if (op >= SO_UNKOWN){
		printf("\n-=[ Operator ]=-\nUNKNOWN OPERATOR");
		return;
	}
	printf("\n-=[ Operator ]=-\n%s", operatorRepr[op]);
}

char *getOperatorRepr(Operator op){
	if (op >= SO_UNKOWN){
		return strdup("Unkown");
	}
	
	return strdup(operatorRepr[op]);
}