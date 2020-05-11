/*
 * HashTable.h
 *
 *  Created on: May 11, 2020
 *      Author: Miguel Aguilar
 */
#include <stdbool.h>
#include "..\Type\Type.h"
#include "..\Definiciones\Definiciones.h"
#include "..\SimpleList\SimpleList.h"
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

typedef void (*destructor) (void*);

typedef struct stHashTable *hashTable;

hashTable hashTable_create (int);
bool hashTable_destroy (hashTable);
int hashTable_size (hashTable);
int hashTable_places (hashTable);
bool hashTable_add (hashTable, char*, Type);
Type hashTable_get (hashTable, char*);
bool hashTable_remove (hashTable, char*);
int hash (char* key);
int alphaToNumer(char);
char* mayus(char*);
void hashTable_print(hashTable);

#endif /* HASHTABLE_H_ */

