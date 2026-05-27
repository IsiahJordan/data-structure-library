#include "ds/stack.h"
#include <stdio.h>
#include <string.h>

Stack *init_stack(size_t padding) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  if (s == NULL) {
    perror("init_stack: failed malloc"); 
    return NULL;
  }

  s->count = 0;
  s->padding = padding;
  return s;
}

void push_stack(
  Stack *top, 
  void *val
) {
  if (top == NULL) {
    perror("push_stack: invalid arguments");
    return;
  }
  
  if (top->count == 0) {
    top->list = init_listnode(val, top->padding, NULL);
  }
  else {
    ListNode *temp = init_listnode(val, top->padding, top->list);
    top->list = temp;
  }
  top->count++;
}

void pop_stack(
  Stack *top
) {
  if (top == NULL || top->count <= 0) {
    perror("pop_stack: invalid arguments");
    return;
  }

  ListNode *temp = top->list->next;
  free(top->list);
  
  top->list = temp;
  top->count--;
}

void *peek_stack(
  Stack *top
) {
  if (top == NULL || top->count <= 0) {
    return NULL;
  }

  return top->list->val;
}

void release_stack(
  Stack *top
) {
  if (top == NULL) {
    return;
  }
  
  if (top->list != NULL) {
    release_listnode(top->list);
  }
  free(top);
}
