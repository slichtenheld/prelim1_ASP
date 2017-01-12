#include <assert.h>
#include <stdlib.h>
#include "stack.h"
#define CAPACITY 1000

struct Stack_t {
	int count;
	int data[CAPACITY];
};

Stack_T Stack_new(void) {
	Stack_T stk = malloc(sizeof *stk);
	assert(stk != NULL);
	stk->count = 0;
	return stk;
}

int Stack_empty(Stack_T stk) {
	assert(stk);
	return (stk->count == 0);
}

void Stack_push(Stack_T stk, int i) {
	assert(stk);
	assert(stk->count < CAPACITY);
	stk->data[stk->count++] = i;
}

int Stack_pop(Stack_T stk) {
	assert(stk && stk->count > 0);
	return stk->data[--(stk->count)];
}