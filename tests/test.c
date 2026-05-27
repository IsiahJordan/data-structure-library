
#define DS_MACRO_ENABLED

#include <stdio.h>
#include <assert.h>
#include "ds/array.h"
#include "ds/list.h"
#include "ds/stack.h"
#include "ds/queue.h"


void test_arr() {
  Array *arr = init_array(NULL, sizeof(int), 10, 0);
  assert(arr != NULL);
  
  int val = 1;
  push_array(arr, &val);
  assert(arr->end == 0);
  assert(*(int *)get_array(arr, 0) == 1);

  PUSH_ARRAY(arr, 10, int);
  assert(arr->end == 1);
  assert(*(int *)get_array(arr, 1) == 10);

  pop_array(arr);
  assert(arr->end == 0);
  assert(*(int *)get_array(arr, 0) == 1);

  INSERT_ARRAY(arr, 3, 0, int);
  assert(arr->end == 1);
  assert(*(int *)get_array(arr, 0) == 3);
  
  int32_t search;
  FIND_ARRAY(arr, 3, search, int);
  assert(search == 0);

  delete_array(arr, 1);
  assert(arr->end == 0);
  assert(*(int *)get_array(arr, 1) != 1);

  resize_array(arr, 2);
  assert(arr->capacity == 2);

  release_array(arr);
}

void test_listnode() {
  ListNode *node = init_listnode(NULL, sizeof(int), NULL); 
  assert(node != NULL);

  PUSH_LISTNODE(node, 10, int);
  assert(count_listnode(node) == 1);
  assert(GET_LISTNODE(node, 1, int) == 10);

  pop_listnode(node);
  assert(count_listnode(node) == 0);
  
  PUSH_LISTNODE(node, 10, int);
  PUSH_LISTNODE(node, 10, int);

  INSERT_LISTNODE(node, 11, 1, int);
  assert(count_listnode(node) == 3);
  assert(GET_LISTNODE(node, 1, int) == 11);

  INSERT_LISTNODE(node, 3, 2, int);
  assert(count_listnode(node) == 4);
  assert(GET_LISTNODE(node, 2, int) == 3);
  
  SET_LISTNODE(node, 10, 0, int);
  assert(count_listnode(node) == 4);
  assert(GET_LISTNODE(node, 0, int) == 10);

  int32_t index;
  FIND_LISTNODE(node, 10, index, int);
  assert(index == 0);

  ListNode *tail = tail_listnode(node);
  assert(*(int*)tail->val == 10);

  release_listnode(node);
}

void test_stack() {
  Stack *stack = init_stack(sizeof(int));
  assert(stack != NULL);

  int val = 1;
  push_stack(stack, &val);
  assert(PEEK_STACK(stack, int) == 1);

  int val2 = 3;
  push_stack(stack, &val2);
  assert(PEEK_STACK(stack, int) == 3);

  pop_stack(stack);
  assert(PEEK_STACK(stack, int) == 1);
  pop_stack(stack);
  assert(peek_stack(stack) == NULL);
  release_stack(stack);
}

void test_queue() {
  Queue *queue = init_queue(sizeof(int));
  assert(queue != NULL);

  int val = 1;
  push_queue(queue, &val);
  assert(FRONT_QUEUE(queue, int) == 1);

  int val2 = 3;
  push_queue(queue, &val2);
  assert(FRONT_QUEUE(queue, int) == 1);

  pop_queue(queue);
  assert(FRONT_QUEUE(queue, int) == 3);
  release_queue(queue);
}

int main() {
  test_arr();
  test_listnode();
  test_stack();
  test_queue();
}

