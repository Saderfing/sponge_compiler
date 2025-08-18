#include "sponge_testing.h"

void setupRandom(){
	srand(time(NULL));
}

int min(int a, int b){
	return (a > b) ? b : a;
}


int max(int a, int b){
	return (a < b) ? b : a;
}

int randint(int min, int max){
	if (min > max){
		return (rand() % abs(min - max)) + max;
	}

	return (rand() % abs(max - min)) + min;
}

double randdouble(double min, double max){
	if (min > max){
		return (rand() / fabs(min - max)) + max;
	}

	return (rand() / fabs(max - min)) + min;
}


void fail(){
	printf("[%s FAIL %s] : ", RED, WHITE);
}

void pass(){
	printf("[%s PASS %s] : ", GREEN, WHITE);
}

void printResult(char *testName, Test testResult){
	if (testResult){
		pass();
	} else {
		fail();
	}

	printf(" - %s\n", testName);
}
// flip a 32 bit integer (make the MSB the LSB and vice-versa)
uint64_t flipWord(uint64_t value) {
	//printf("before %d\n", value);
	value = (value & 0xFFFFFFFF00000000) >> 32 | (value & 0x00000000FFFFFFFF) << 32;

	value = (value & 0xFFFF0000FFFF0000) >> 16 | (value & 0x0000FFFF0000FFFF) << 16;
	// printf("16 %d\n", value);
	value = (value & 0xFF00FF00FF00FF00) >> 8  | (value & 0x00FF00FF00FF00FF) << 8;
	// printf("8 %d\n", value);
	value = (value & 0xF0F0F0F0F0F0F0F0) >> 4  | (value & 0x0F0F0F0F0F0F0F0F) << 4;
	// printf("4 %d\n", value);
	value = (value & 0xCCCCCCCCCCCCCCCC) >> 2  | (value & 0x3333333333333333) << 2;
	// printf("2 %d\n", value);
	value = (value & 0xAAAAAAAAAAAAAAAA) >> 1  | (value & 0x5555555555555555) << 1;
	// printf("after %d\n", value);

	return value;
}


void printAsBinary(uint64_t integer){
	printf("(int) %ld = 0b", integer);
	integer = flipWord(integer);
	for (int i = 1; i <= 64; i++){
		printf("%ld", integer % 2);
		integer /= 2;
		if (i % 4 == 0){
			printf(" ");
		}
		if (i % 8 == 0){
			printf(" ");
		}
	}
	printf("\n");
}