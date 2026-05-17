
#define DS_MACRO_ENABLED

#include <stdio.h>
#include <assert.h>
#include "ds/array.h"


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
}

int main() {
  test_arr();
}

