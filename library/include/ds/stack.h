#ifndef DS_STACK_H
#define DS_STACK_H

#include "list.h"

#if defined(DS_MACRO_STACK_ENABLED) || defined(DS_MACRO_ENABLED)

/**
 * Very Buggy!!!!
 * for someone reason, the value
 * is already set to top which 
 * gives unpredictable behavior
 **/
#define PUSH_STACK(top, val, type) \
  do  { \
    type tmp = (val); \
    push_stack(top, &tmp); \
  } while(0)


#define PEEK_STACK(top, type) \
  *(type *)peek_stack(top)

#endif


/** 
 * the stack takes influence with 
 * linkednode but instead of treating
 * each node with grave importance, I
 * instead view stack as an array
 * that uses linkednode operations :D
 **/
typedef struct {
  ListNode *list;
  int32_t count;
  size_t padding;
} Stack;

Stack *init_stack(size_t padding);

void push_stack(Stack *top, void *val);
void pop_stack(Stack *top);

void *peek_stack(Stack *top);
void release_stack(Stack *top);

#endif
