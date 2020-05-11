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

bool simpleList_isEmpty(simpleList s) {
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
		if (s->size > 1) {
			for (int i = 0; i < s->size; ++i) {
				if (temp->next == NULL) {
					temp->next = newNode;
					s->size++;
					return true;
				} else
					temp = temp->next;
			}
		} else {
			s->start->next = newNode;
		}
		temp->next = newNode;
	}

	s->size++;
	return true;
}

Type simpleList_get(simpleList s, char *key) {
	Node temp = s->start;
	for (int i = 0; i < s->size; ++i) {
		if (strcmp(temp->key, key) == 0)
			return temp->data;
		else {
			temp = temp->next;
		}
	}
	return temp->data;
}

void simpleList_print(simpleList s) {
	Node temp = s->start;
	for (int i = 0; i < s->size; ++i) {
		print_type(temp->data);
		if (temp->next != NULL)
			temp = temp->next;
	}
}

bool simpleList_remove(simpleList s, char *key) {

	if (strcmp(s->start->key, key) == 0) {
		destroy_type(s->start->data);
		free(s->start->key);
		s->size--;
		return true;
	}

	Node temp = s->start->next;
	Node temp2 = s->start;

	for (int i = 0; i < s->size; ++i) {
		if (strcmp(temp->key, key)) {
			destroy_type(temp->data);
			free(temp->key);
			temp2->next = temp->next;
			s->size--;
			return true;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	return false;
}

void simpleList_destroy(simpleList s) {
	while (s->size > 0) {
		Node temp = s->start;
		for (int i = 0; i < s->size; ++i) {
			if (temp->next == NULL)
				simpleList_remove(s, temp->key);
			s->size--;
		}
	}
}

