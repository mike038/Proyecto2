/*
 * SimpleList.h
 *
 *  Created on: May 5, 2020
 *      Author: Miguel Aguilar
 */
#include <stdbool.h>
#include "..\Definiciones\Definiciones.h"
#include "..\Type\Type.h"
#ifndef SIMPLELIST_H_
#define SIMPLELIST_H_


typedef void (*destructor) (void*);

typedef struct stSimpleList* simpleList;

simpleList simpleList_create();
void simpleList_print(simpleList);
void simpleList_destroy(simpleList);
int simpleList_size(simpleList);
bool simpleList_add(simpleList, char*, Type);
Type simpleList_get(simpleList, char*);
bool simpleList_remove(simpleList, char*);
bool simpleList_isEmpty(simpleList);


#endif /* SIMPLELIST_H_ */
