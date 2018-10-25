#include <stdio.h>
#include "genericLinkedList.h"
#include "tests.h"

int main(int arg, char* argc[]){
  //runTests();
	printf("==== Starting testing ====\n\n");
	listElement* l = createEl("String 1", &printString, 30);
	printf("\nTraversal After Creating List with a string:\n");
	traverse(l);

	enqueue(&l, "A", &printChar, 30);
	printf("\nTraversal After adding a Char:\n");
	traverse(l);

	push(&l, "String 2", &printString, 30);
	printf("\nTraversal After Adding a String:\n");
	traverse(l);

	int x = 1001;
	enqueue(&l, &x, &printInt, 30);
	printf("\nTraversal After Adding int:\n");
	traverse(l);

	printf("\nTraversal after a dequeues and a pop:\n");
	dequeue(l);
	pop(&l);
	traverse(l);

	printf("\n==== Finishing testing ====");
  return 0;
}
