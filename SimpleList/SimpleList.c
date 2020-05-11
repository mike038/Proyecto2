/*
 * SimpleList.c
 *
 *  Created on: May 5, 2020
 *      Author: Miguel Aguilar
 */

#include "SimpleList.h"
#include "..\Definiciones\Definiciones.h"
#include "..\Type\Type.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stNode {
	Type data;
	struct stNode *next;
	char *key;
};

typedef struct stNode *Node;

struct stSimpleList {
	Node start;
	int size;
};

simpleList simpleList_create() {
	simpleList s = malloc(sizeof(struct stSimpleList));
	if (s == NULL)
		return NULL;
	s->size = 0;
	s->start = NULL;
	return s;
}

int simpleList_size(simpleList s) {
	return s->size;
}

int simpleList_isEmpty(simpleList s) {
	return s->size == 0;
}

bool simpleList_add(simpleList s, char *key, Type t) {
	Node newNode = malloc(sizeof(struct stNode));
	newNode->data = t;
	newNode->key = key;
	newNode->next = NULL;

	if (simpleList_isEmpty(s))
		s->start = newNode;
	else {
		Node temp = s->start;
		for (int i = 0; i < s->size; ++i) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	s->size++;
	return true;
}

//No se validan entradas, siempre se regresara un dato
Type simpleList_get(simpleList s, char *key) {
	Node temp = s->start;
	for (int i = 0; i < s->size; ++i) {
		if (strcmp(temp->key, key) == 0)
			return temp->data;
		else{
			temp = temp->next;
		}
	}
	return temp->data;
}
//No se eliminan realmente, se pone un dato que tomamos como borrado
bool simpleList_remove(simpleList s, char* key) {
	Node temp = s->start;
	for (int i = 0; i < s->size; ++i) {
		if(strcmp(temp->key, key)){
			temp->key = "0000";
			return true;
		}
	}
	return false;
}

void simpleList_destroy(simpleList s) {
	while(simpleList_isEmpty(s)){
		Node temp = s->start;
		for (int i = 0; i < s->size; ++i) {
			temp = temp->next;
			if(temp->next == NULL)
				free(temp);
		}
	}
}

