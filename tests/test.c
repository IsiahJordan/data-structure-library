#include "ds_library/base.h"
#include "ds_library/array.h"
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

  int val = *(int*)access_array_list(array, 2);
  assert(val == 3);
  
  int param = 1;
  set_array_list(array, 2, &param);
  val = *(int*)access_array_list(array, 2);
  assert(val == 1);

  free(array);

  int param2 = 1;
  LinkedNode *list = init_linked_list(&param2);
  if (list == NULL) {
    perror("list error");
    return;
  }

  int val2 = *(int*)access_linked_list(list, 0);
  assert(val2 == 1);

  int param3 = 3;
  set_linked_list(list, 0, &param3);
  val2 = *(int*)access_linked_list(list, 0);
  assert(val2 == 3);

  free(list);

  printf("Test[2]: Successful\n");
}

int main() {
  test_base_h();  
  test_array_h();
}

