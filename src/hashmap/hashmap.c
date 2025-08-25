#include "hashmap.h"

uint64_t joaat_hash(char *key, uint64_t key_len) {
    uint64_t hash = 0;
    uint64_t i;

    for (i = 0; i < key_len; i++) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

HashMap *newHashMap(){
	HashMap *hm = (HashMap *)allocate(sizeof(HashMap), "new HashMap");
	hm->length = 0;

	for (uint64_t i = 0; i < BASE_BUCKETS_COUNT; i++){
		hm->buckets[i] = newBucket();
	}

	return hm;
}

bool inHashMap(char *key, HashMap *hm){
	if (!key || !hm){
		return false;
	}
	uint64_t length = strlen(key);
	uint64_t index = joaat_hash(key, length) % BASE_BUCKETS_COUNT;

	Bucket *b = hm->buckets[index];

	return inBucket(key, b);
}

uint8_t getHashMap(char *key, HashMap *hm){
	if (key == NULL || hm == NULL){
		return 0; // Random accessbe an error
	}
	uint64_t length = strlen(key);
	uint64_t index = joaat_hash(key, length) % BASE_BUCKETS_COUNT;

	Bucket *b = hm->buckets[index];

	return getValueBucket(key, b);
}

void appendHashMap(char *key, uint8_t value, HashMap *hm){
	if (key == NULL && hm == NULL){
		return;
	}
	
	uint64_t length = strlen(key);
	uint64_t index = joaat_hash(key, length) % BASE_BUCKETS_COUNT;

	Bucket *b = hm->buckets[index];
	appendBucket(key, value, b);
	hm->length++;
}

void setHashMap(char *key, uint8_t newValue, HashMap *hm){
	uint64_t length = strlen(key);
	uint64_t index = joaat_hash(key, length) % BASE_BUCKETS_COUNT;

	Bucket *b = hm->buckets[index];
	setValueBucket(key, newValue, b);
}

void popHashMap(char *key, HashMap *hm){
	uint64_t length = strlen(key);
	uint64_t index = joaat_hash(key, length) % BASE_BUCKETS_COUNT;

	Bucket *b = hm->buckets[index];
	popBucket(key, b);
	hm->length--;
}

void printHashMap(HashMap* hm){
	if (hm == NULL || hm->length == 0){
		printf("Empty HashMap\n");
		return;
	}

	printf("HashMap : length : %ld {\n", hm->length);

	for (uint64_t i = 0; i < BASE_BUCKETS_COUNT; i++){
		if (hm->buckets[i] != NULL && hm->buckets[i]->head != NULL){
			printBucket(hm->buckets[i]);
		}
	}
	printf("}\n");
}

void freeHashMap(HashMap *hm){
	if (hm == NULL){
		return;
	}

	for (uint64_t i = 0; i < BASE_BUCKETS_COUNT; i++){
		if (hm->buckets[i] != NULL){ // don't free a null pointer (crowdstrike moment)
			freeBucket(hm->buckets[i]);	
		}
	}

	free(hm);
}