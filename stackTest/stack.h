#ifndef STACK_H_
#define STACK_H_

typedef struct Stack_t* Stack_T;

extern Stack_T Stack_new(void);
extern int Stack_empty(Stack_T stk);
extern void Stack_push(Stack_T stk, int i);
extern int Stack_pop(Stack_T stk);

#endif