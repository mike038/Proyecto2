/*
 * HashTable.c
 *
 *  Created on: May 11, 2020
 *      Author: Miguel Aguilar
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "..\Type\Type.h"
#include "..\Definiciones\Definiciones.h"
#include "..\SimpleList\SimpleList.h"
#include "HashTable.h"

#define M 1000

struct stNode {
	int num;
	Type data;
	struct stNode *next;
};

typedef struct stNode *Node;

struct stHashTable {
	simpleList table[M];
	int size;
	int places;
};

hashTable hashTable_create(int places) {
	hashTable hs = malloc(sizeof(struct stHashTable));
	if (hs == NULL)
		return NULL;

	hs->places = places;
	hs->size = 0;
	for (int i = 0; i < 1001; ++i) {
		hs->table[i] = NULL;
	}

	return hs;
}

int alphaToNumer(char c) {
	return (int) c - 65;
}

int hash(char *key) {
	int h = alphaToNumer(*key);
	int x = 26;

	for (int i = 0; i < strlen(key); ++i)
		h = (h * x) % M + (alphaToNumer(key[i])) % M;
	return h % M;
}

char* mayus(char *s) {
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
	return hs->size;
}

int hashTable_places(hashTable hs) {
	return hs->places;
}

bool hashTable_add(hashTable hs, char *key, Type data){
	int clave = hash(key);
	if(hs->table[clave] == NULL){
		hs->table[clave] = simpleList_create();
		simpleList_add(hs->table[clave], key, data);
		hs->size++;
	} else {
		simpleList_add(hs->table[clave], key, data);
		hs->size++;
	}
	return true;
}

Type hashTable_get(hashTable hs, char *key){
	int clave = hash(key);
	return simpleList_get(hs->table[clave], key);
}

void hashTable_print(hashTable hs){
	for (int i = 0; i < 1000; ++i) {
		if(hs->table[i] != NULL){
			simpleList_print(hs->table[i]);
		}
	}
}

bool hashTable_remove(hashTable hs, char *key){
	int clave = hash(key);
	if(simpleList_size(hs->table[clave]) == 1)
		simpleList_destroy(hs->table[clave]);
	else
		simpleList_remove(hs->table[clave], key);
	hs->size--;
	return true;
}

bool hashTable_destroy(hashTable hs){
	//TODO cambiar 1001
	for (int i = 0; i < 1001; ++i) {
		simpleList_destroy(hs->table[i]);
	}
	//TODO eliminar lista completa
	return true;
}
