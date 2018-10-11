#include <stdio.h>

int main(int arg, char* argc[]){
	
	int x;
	int *y;
	y = &x;

	printf("The size of an int is: %d\n", sizeof(x));
	printf("The size of an int pointer is: %d\n", sizeof(y));

	long a;
	printf("The size of a long is: %d\n", sizeof(a));

	double *c;
	printf("The size of a double pointer is: %d\n", sizeof(c));

	char **test;
	printf("The size of a char double pointer is: %d\n", sizeof(test));

	//The size of all these variables and pointers is 4 bytes. 
  
  
  return 0;
}
