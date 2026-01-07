#include "ds_library/base.h"
#include "ds_library/array.h"
#include "ds_library/tree.h"
#include "ds_library/queue.h"
#include "ds_library/stack.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_base_h() {
  Collection* collect = (Collection*)malloc(sizeof(Collection));    
  if (collect == NULL) {
    perror("collection error");
    return;
  }

  int arr[] = {1, 2, 3, 4};
  collect->el = arr;
  collect->size = 10;
  collect->padding = sizeof(int);
  collect->iter = (Iterator*)malloc(sizeof(Iterator));
  if (collect->iter == NULL) {
    perror("iteration error");
    return;
  }

  collect->iter->type = ITER_RANDOM;

  assert(collect != NULL);
  assert(collect->size == 10);
  assert(collect->padding == sizeof(int));
  assert(collect->iter != NULL);
  assert(collect->iter->type == ITER_RANDOM);

  free(collect->iter);
  collect->iter = NULL;
  free(collect);

  printf("Test[1]: Successful\n");
}

void test_array_h() {
  int arr[] = {1, 2, 3, 4};
  ArrayList *array = init_array_list(arr, 4, sizeof(int), 10);
  if (array == NULL) {
    perror("array error");
    return;
  }

  // ==== test access ====
  int val = *(int*)access_array_list(array, 2);
  assert(val == 3);
  
  // ==== test set ====
  int param = 1;
  set_array_list(array, 2, &param);
  val = *(int*)access_array_list(array, 2);
  assert(val == 1);

  // ==== test push ====
  param = 5;
  push_array_list(array, &param);
  val = *(int*)access_array_list(array, 4);
  assert(val == 5);

  // ==== test pop ====
  pop_array_list(array);

  free(array);

  int param2 = 1;
  LinkedNode *list = init_linked_list(&param2);
  if (list == NULL) {
    perror("list error");
    return;
  }

  // ==== test access ====
  int val2 = *(int*)access_linked_list(list, 0);
  assert(val2 == 1);

  // ==== test set ====
  int param3 = 3;
  set_linked_list(list, 0, &param3);
  val2 = *(int*)access_linked_list(list, 0);
  assert(val2 == 3);

  // ==== test push ====
  param3 = 4;
  push_linked_list(list, &param3);
  val2 = *(int*)access_linked_list(list, 1);
  assert(val2 == 4);

  // ==== test pop ====
  pop_linked_list(list);

  // ==== test empty ====
  pop_linked_list(list);
  assert(empty_linked_list(list));

  free(list);

  printf("Test[2]: Successful\n");
}

void test_stack_h() {
  int params1 = 1;
  Stack *stack = init_stack(&params1);
  if (stack == NULL) {
    perror("stack error");
    return;
  }

  int params2 = 2;
  push_stack(stack, &params2);
  int val = *(int*)peek_stack(stack);
  assert(val == 2);

  pop_stack(stack);
  val = *(int*)peek_stack(stack);

  assert(val == 1);
  assert(empty_stack(stack) == false);

  release_stack(stack);

  printf("Test[3]: Successful\n");
}

void test_queue_h() {
  int params1 = 1;
  Queue *queue = init_queue(&params1);
  if (queue == NULL) {
    perror("queue error");
    return;
  }

  int params2 = 2;
  push_queue(queue, &params2);
  int val = *(int*)peek_queue(queue);
  assert(val == 1);

  pop_queue(queue);
  val = *(int*)peek_queue(queue);

  assert(val == 1);
  assert(empty_queue(queue) == false);

  release_queue(queue);

  printf("Test[4]: Successful\n");
}

void test_tree_h() {
  int params1 = 1;
  BinaryTree *tree = init_binary_tree(&params1);  
  if (tree == NULL) {
    perror("binary tree error");
    return;
  }

  printf("Test[5]: Successful\n");  
}


int main() {
  test_base_h();  
  test_array_h();
  test_stack_h();
  test_queue_h();
  test_tree_h();
}

