#include "sponge_IO.h"

#define END_STRING '\0'

char *F_RED 	= "\033[0;31m";
char *F_GREEN	= "\033[0;32m";
char *F_YELLOW	= "\033[0;33m";
char *F_BLUE	= "\033[0;34m";
char *F_WHITE	= "\033[0;39m";

bool isNullFile(FILE *f){
    return f == NULL;
}

FILE *openFile(char *fileName, char *mode){
    FILE *f = fopen(fileName, mode);

    if (isNullFile(f)){
        fatalError("Cannot open this file", 5);
    }

    return f;
}

/*Read a line in the */
int getLine(FILE *f, char destBuffer[], int destSize){
    if (feof(f) || destSize <= 0){
        return 1;
    }
    char c = fgetc(f);
    int i = 0;
    

    while (c != EOF && c != '\n' && i + 1 < destSize){
        destBuffer[i] = c;
        c = fgetc(f);
        i++;
    }

    destBuffer[i] = '\0';

    return 0;
}

void printRawChar(char c){
	if (c == ' '){
		printf("(space) ");

	} else if (c == '\n'){
		printf("\\n\n");

	} else if (c == '\t'){
		printf("\\t\t");

	} else {
		printf("%c", c);
	}
}

void debug(char *msg){
	if (msg){
		#ifdef DEBUG
		printf("%s\n", msg);
		#endif
	}

}

void warning(char *msg){
	#ifdef DEBUG
	if (msg && DEBUG >= 1){
		printf("%s\n", msg);
	}

	#endif
}

void error(char *msg){
	#ifdef DEBUG
	if (msg && DEBUG >= 2){
		fprintf(stderr, "%serror%s: %s\n",F_RED, F_WHITE, msg);
	}
	#endif
}