#include "ds_library/base.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_base_h() {
  // =========== test base.h ===========
  Collection* collect = (Collection*)malloc(sizeof(Collection));    
  if (collect == NULL) {
    perror("collection error");
  }

  int arr[] = {1, 2, 3, 4};
  collect->el = arr;
  collect->size = 10;
  collect->padding = sizeof(int);
  collect->iter = (Iterator*)malloc(sizeof(Iterator));
  if (collect->iter == NULL) {
    perror("iteration error");
  }

  collect->iter->type = ITER_RANDOM;

  assert(collect != NULL);
  assert(collect->size == 10);
  assert(collect->padding == sizeof(int));
  assert(collect->iter != NULL);
  assert(collect->iter->type == ITER_RANDOM);

  printf("Test[1]: Successful\n");
}

int main() {
  test_base_h();  
}

