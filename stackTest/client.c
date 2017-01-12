#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	int i;
	Stack_T s = Stack_new();
	for (i = 1; i < 10; i++)
		Stack_push(s, i);
	while (!Stack_empty(s))
		printf("val: %d\n",Stack_pop(s));
	return EXIT_SUCCESS;
}