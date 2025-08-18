#ifndef _SPONGE_FILES_H_
#define _SPONGE_FILES_H_

#include "sponge_std.h"
//#include "token.h"

#define READ_MODE "r"
#define READ_BINARY_MODE "rb"
#define READ_MODE_PLUS "r+"
#define WRITE_MODE "w"
#define WRITE_BINARY_MODE "wb"
#define WRITE_MODE_PLUS "w+"
#define APPEND_MODE "a"
#define APPEND_MODE_PLUS "a+"

extern char *F_RED;
extern char *F_GREEN;
extern char *F_YELLOW;
extern char *F_BLUE;
extern char *F_WHITE;

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 

#define HWORD_TO_BINARY_PATTERN BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN
#define HWORD_TO_BINARY(hword) BYTE_TO_BINARY((hword & 0xFF00) >> 8), BYTE_TO_BINARY(hword & 0x00FF)

#define WORD_TO_BINARY_PATTERN HWORD_TO_BINARY_PATTERN" "HWORD_TO_BINARY_PATTERN
#define WORD_TO_BINARY(word) HWORD_TO_BINARY((word & 0xFFFF0000) >> 16), HWORD_TO_BINARY(word & 0x0000FFFF)

#define DOUBLE_TO_BINARY_PATTERN WORD_TO_BINARY_PATTERN" "WORD_TO_BINARY_PATTERN
#define DOUBLE_TO_BINARY(double_value) WORD_TO_BINARY((double_value & 0xFFFFFFFF00000000) >> 32), WORD_TO_BINARY(double_value & 0x00000000FFFFFFFF)


#define closeFile fclose

bool isNullFile(FILE *f);

FILE *openFile(char *fileName, char *mode);

/*Read a line in the */
int getLine(FILE *f, char destBuffer[], int destSize);

void debug(char *msg);

void warning(char *msg);

void error(char *msg);

#endif
