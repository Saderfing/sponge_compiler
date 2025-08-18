#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include "sponge_IO.h"
#include "sponge_testing.h"

extern int memUsage;

#define MAX_UINT_DIGIT_COUNT 9

#define BYTE_LENGTH 256
#define HALF_WORD_LENGTH 512
#define WORD_LENGTH 1024
#define DOUBLE_WORD_LENGTH 2048

#define FIRST_NIBBLE 0xFF000000
#define SECOND_NIBBLE 0x00FF0000
#define THIRD_NIBBLE 0x0000FF00
#define FOURTH_NIBBLE 0x000000FF

#define BUFFER_SIZE BYTE_LENGTH

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t

#define END_STRING '\0'

void fatalError(char *msg, int code);

void *allocate(size_t size, char *message);

