#include "ds/array.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

/** Utility Macros :D */
#define MAX(a, b) a <= b? b: a
#define MIN(a, b) a <= b? a: b

Array *init_array(
  void *elements, 
  size_t padding, 
  size_t capacity, 
  size_t count
) {
  Array *array = (Array *)malloc(sizeof(Array));
  if (array == NULL) {
    perror("init_array: failed malloc");
    return NULL;
  }
  
  array->elements = malloc(padding * capacity); /** allocate a predifine size */
  if (array->elements == NULL) {
    perror("init_array: failed malloc");
    return NULL;
  }

  array->padding = padding;
  array->capacity = capacity;
  /** making the assumption that the last element of the array 
   * is always equal to count - 1
   **/
  array->end = count - 1;

  return array;
}

void push_array(
  Array *array, 
  void *element
) {
  if (array == NULL) {
    perror("push_array: invalid arguments");
    return;
  }
  
  if (array->end == array->capacity) {
    resize_array(array, (size_t)(1.5f * array->capacity));
  }
  
  set_array(array, element, array->end + 1);
}

void pop_array(
  Array *array
) {
  if (array == NULL || array->end < 0) {
    perror("pop_array: invalid arguments");
    return;
  }

  /** 
   * made sure to set NULL to prevent
   * insert reintroducing Non-Null values
   **/
  char repl = 0; /** replace 0 value */
  set_array(array, &repl, array->end);
  array->end--;
}

void insert_array(
  Array *array, 
  void *element, 
  int32_t index
) {
 if (array == NULL || array->end + 1 == array->capacity || index >= array->capacity || index < 0) {
    perror("insert_array: invalid arguments");
    return;
  }

  if (array->end < index) {
    array->end = index;
    set_array(array, element, index);
  } else {
    /** prevent overlapping memory blocks hence decrement */
    for (int32_t i = array->end; i >= index; i--) {
      void *src = get_array(array, i);
      void *dest = get_array(array, i + 1);
      memcpy(dest, src, array->padding);
    }
    set_array(array, element, index);
    array->end++;
  }
}

void delete_array(
  Array *array, 
  int32_t index
) {
  if (array == NULL || index > array->end || index < 0) {
    perror("delete_array: invalid arguments");
    exit(0);
  }

  if (index < array->end) {
    /** prevent overlapping memory blocks */
    for (int32_t i = index; i < array->end; i++) {
      void *src = get_array(array, i + 1);
      void *dest = get_array(array, i);
      memcpy(dest, src, array->padding);
    }
  }

  char repl = 0; /** replace end with 0*/
  set_array(array, &repl, index);

  array->end--;
}

void *get_array(
  Array *array, 
  int32_t index
) {
  if (index < 0 || index >= (int32_t)array->capacity) {
    perror("get_array: invalid arguments");
    exit(0);
  }
  return (char*)array->elements + index*array->padding;
}

void set_array(
  Array *array, 
  void *element,
  int32_t index
) {
 if (array == NULL || index >= array->capacity || index < 0) {
    perror("set_array: invalid arguments");
    exit(0);
  }

  if (index > array->end) {
    array->end = index;
  }

  void *dest = (char*)array->elements + index*array->padding;
  memcpy(dest, element, array->padding);
}

int32_t find_array(
  Array *array, 
  void *element
) {
  if (array == NULL) {
    perror("push_array: invalid arguments");
    return array->end;
  }

  for (size_t i = 0; i < array->end + 1; i++) {
    if (*(char *)get_array(array, i) == *(char *)element) {
      return i;
    }
  }

  return array->capacity;
}

void resize_array(
  Array *array, 
  size_t capacity
) {
  if (array == NULL) {
    perror("resize_array: invalid arguments");
    return;
  }

  array->elements = realloc(array->elements, array->padding * capacity);
  if (array->elements == NULL) {
    perror("resize_array: failed to realloc");
    return;
  }

  array->capacity = capacity;
}

void release_array(
  Array *array
) {
  if (array == NULL) {
    perror("release_array: invalid arguments");
    return;
  }

  free(array);
}
