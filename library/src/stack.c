#include "ds_library/stack.h"
#include <stdio.h>

Stack *init_stack(void *entry) {
  LinkedNode *node = init_linked_list(entry);
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  
  stack->node = node;
  stack->last = entry;

  return stack;
}

void push_stack(Stack *stack, void *value) {
  if (stack == NULL) {
    perror("[stack push]");
    return;
  }

  push_linked_list(stack->node, value);
}

void *peek_stack(Stack *stack) {
  if (stack == NULL) {
    perror("[stack peek]");
    return NULL;
  }
  else if (stack->node->data->size == 0) {
    return NULL;
  } 

  void *value = access_linked_list(stack->node, stack->node->data->size-1);
  return value;
}

void pop_stack(Stack *stack) {
  if (stack == NULL) {
    perror("[stack pop]");
    return;
  }

  pop_linked_list(stack->node);
}

bool empty_stack(Stack *stack) {
  if (stack == NULL) {
    return true;
  }

  empty_linked_list(stack->node);
}

void release_stack(Stack *stack) {
  free(stack);
}
