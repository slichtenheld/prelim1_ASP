#ifndef STACK_H_
#define STACK_H_

typedef struct Stack_t *Stack_T; // Because stack is treated like black box

extern Stack_T Stack_new(void);
extern int Stack_empty(Stack_T stk);
extern void Stack_push(Stack_T stk, void *i); // no type checking but should work with anything
extern void *Stack_pop(Stack_T stk);

/* supports type checking but less flexible
extern void Stack_push(Stack_T stk, int i);
extern int Stack_pop(Stack_T stk);
*/

#endif