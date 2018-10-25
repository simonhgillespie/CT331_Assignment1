#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, void* printFunction1, size_t size);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, void* printFunction, size_t size);

//Delete the element after the given el
void deleteAfter(listElement* after);

int length(listElement* list);

void push(listElement** list,void* data, void* printFunction1, size_t size);

listElement* pop(listElement** list);

void enqueue(listElement** list, void* data, void* printFunction1, size_t size);

listElement* dequeue(listElement* list);

void printChar(void* data);
void printInt(void* data);
void printString(void* data);


#endif
