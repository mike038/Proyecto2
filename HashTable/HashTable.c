/*
 * HashTable.c
 *
 *  Created on: May 11, 2020
 *      Author: Miguel Aguilar
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "..\Type\Type.h"
#include "..\Definiciones\Definiciones.h"
#include "..\SimpleList\SimpleList.h"
#include "HashTable.h"

#define M 1000

struct stNode {
	Type data;
	char *key;
};

typedef struct stNode *Node;

struct stHashTable {
	simpleList hs;
	int size;
	int places;
};

hashTable hashTable_create(int places) {
	hashTable ht = malloc(sizeof(struct stHashTable));
	if (ht == NULL)
		return NULL;
	ht.places = places;
	ht.size = 0;
	ht.hs = NULL;
	return ht;
}

int alphaToNumer(char c) {
	return (int) c - 65;
}

int hash(char *key, hashTable hs) {
	int h = alphaToNumer(*key);
	int x = 26;

	for (int i = 0; i < strlen(key); ++i)
		h = (h * x) % M + (alphaToNumer(*key[i])) % M;
	return h % M;
}

char* toUpper(char *s) {
	char *sUpper = malloc(100);
	int i = 0;
	char letra;
	while (*(s + i) != '\0') {
		if ((*(s + i) >= 'a' && *(s + i) <= 'z')
				|| (*(s + i) >= 'A' && *(s + i) <= 'Z')
				|| (*(s + i) >= '0' && *(s + i) <= '9')) {
			letra = toupper(*(s + i));
			strncpy(sUpper + i, &letra, 1);
		} else {
			strncpy(sUpper + i, s + i, 1);
		}
		i++;
	}
	strncpy(sUpper + i, "\0", 1);
	return sUpper;
}

int hashTable_size(hashTable hs) {
	return hs.size;
}
int hashTable_places(hashTable hs){
	return hs.places;
}
bool hashTable_add(hashTable hs, char *key, Type data);
Type hashTable_get(hashTable hs, char *key);
bool hashTable_remove(hashTable hs, char *key);
bool hashTable_destroy(hashTable hs);

