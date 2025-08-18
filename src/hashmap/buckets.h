#ifndef _POINT_LIST_H_
#define _POINT_LIST_H_
#include <stdio.h>  
#include <stdlib.h> 
#include "sponge_std.h"

typedef struct _BucketCell{
	char *key;
	uint8_t value;
	struct _BucketCell *next;
} BucketCell;

typedef struct _Bucket{
	uint64_t length;
	BucketCell *head;
	BucketCell *tail;
} Bucket;

Bucket *newBucket();

bool inBucket(char *key, Bucket *L);

void appendBucket(char *key, uint8_t value, Bucket *L);

uint8_t popBucket(char *key, Bucket *l);

void emptyBucket(Bucket *L);

uint8_t getValueBucket(char *key, Bucket *l);

void setValueBucket(char *key, uint8_t value, Bucket *l);

void freeBucket(Bucket *L);

void printBucket(Bucket *L);

#endif