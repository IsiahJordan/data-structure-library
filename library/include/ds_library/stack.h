#ifndef DS_STACK_H
#define DS_STACK_H

#include "array.h"

typedef struct {
  LinkedNode *node;
  void *last; // last element of the stack
} Stack;

Stack *init_stack(void *entry);
void push_stack(Stack *stack, void *value);
void *peek_stack(Stack *stack);
void pop_stack(Stack *stack);
bool empty_stack(Stack *stack);
void release_stack(Stack *stack);

#endif
