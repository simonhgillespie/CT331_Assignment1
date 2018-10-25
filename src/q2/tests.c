#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);


  //Test create and traverse
  printf("About to start 1st traverse\n");
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  printf("About to start 2nd traverse\n");
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  printf("About to start 3rd traverse\n");
  traverse(l);
  printf("\n");


  //test Push by pushing element onto linked list
  push(&l, "Push test", 30);
  printf("About to start 4th traverse for push\n");
  traverse(l);
  printf("\n");

  //test Pop
  listElement *thepoppedelement = pop(&l);
  printf("About to start 4th traverseto test if element popped\n");
  traverse(l);
  printf("\n");

  //test Popped element
  printf("About to start 4th traverse to print popped element\n");
  traverse(thepoppedelement);
  printf("\n");


  //test encueue 
  printf("About to start 5th traverse to test enqueueing 3 elements\n");
  enqueue(&l, "Encueue 1", 30);
  enqueue(&l, "Encueue 2", 30);
  enqueue(&l, "Encueue 3", 30);
  traverse(l);
  printf("\n");


  //test dequeue
  printf("About to start 6th traverse to test dequeueing 1 element\n");
  listElement *theDequeueued = dequeue(l);
  //
  printf("\nPrint after dequeue\n");
  traverse(l);

  printf("\nPrint dequeued element\n");
  traverse(theDequeueued);
  printf("\n");






  printf("\nTests complete.\n");
}
