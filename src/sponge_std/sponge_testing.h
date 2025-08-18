#ifndef _SPONGE_TESTING_H_
#define _SPONGE_TESTING_H_
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE   "\033[0;34m"
#define WHITE  "\033[0;39m"

typedef enum {FAIL, PASS} Test;

void setupRandom();


int min(int a, int b);

int max(int a, int b);

int randint(int min, int max);

double randdouble(double a, double b);

void fail();

void pass();

void printResult(char *testName, Test testResult);

void printAsBinary(uint64_t integer);

#endif