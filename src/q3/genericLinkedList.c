#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct {
	void* data;
	void (*printFunction)();
	size_t size;
	struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, void* printFunction1, size_t size) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	void* dataPointer = malloc(sizeof(data));
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	strcpy(dataPointer, data);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	e->printFunction = printFunction1;
	return e;
}

//Prints out each element in the list
void traverse(listElement* start) {
	listElement* current = start;

	while (current != NULL) {
		//printf("%s\n", current->data);
		current->printFunction(current->data);
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, void* printFunction, size_t size) {
	listElement* newEl = createEl(data, printFunction, size);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}


int length(listElement* list) {
	listElement* current = list;
	int x = 0;
	while (current != NULL) {
		x++;
		current = current->next;
	}
	return x;
}

void push(listElement** list, void* data, void* printFunction1, size_t size) {

	listElement* newEl = createEl(data, printFunction1, size);
	newEl->next = *list;
	newEl->printFunction = printFunction1;
	*list = newEl;
}


listElement* pop(listElement** list) {
	listElement* toRet = NULL;
	listElement* first = *list;
	if (first->next == NULL)
	{
		listElement* toRet = *list;
		first->data = NULL;
	}
	else {
		listElement* toRet = *list;
		*list = toRet->next;
		toRet->next = NULL;
	}
	return toRet;
}

void enqueue(listElement** list, void* data, void* printFunction1, size_t size) {
	listElement* newEl = createEl(data, printFunction1, size);
	newEl->next = *list;
	newEl->printFunction = printFunction1;
	*list = newEl;
}

listElement* dequeue(listElement* list) {
	listElement* previous = list;
	listElement* current = list;
	listElement* toRet = NULL;
	if (current->next == NULL) {
		toRet = current;
		current->data = NULL;
	}
	else {
		while (current != NULL) {

			if (current->next == NULL) {
				toRet = current;
				previous->next = NULL;
			}
			else {
				previous = current;
			}

			current = current->next;
		}
	}
	return toRet;
}

void printChar(void* data) {
	printf("%c\n",*(char*)data);
}

void printString(void* data) {
	printf("%s\n", (char*)data);
}

void printInt(void* data) {
	printf("%d\n", *(int*)data);
}



