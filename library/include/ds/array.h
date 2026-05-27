#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * use macro for handling annoying things in code
 **/
#if defined(DS_MACRO_ARR_ENABLED) || defined(DS_MACRO_ENABLED)

/** 
 * macro for handling value passing arguments 
 * which makes it easier to handle void *
 * NOTE: only for none pointer values
 **/
#define PUSH_ARRAY(arr, val, type) \
  { \
    type a = val; \
    push_array(arr, &a); \
  }

#define INSERT_ARRAY(arr, val, index, type) \
  { \
    type a = val; \
    insert_array(arr, &a, index); \
  }

#define SET_ARRAY(arr, val, index, type) \
  { \
    type a = val; \
    set_array(arr, &a, index); \
  }

/** NOTE: ret is a variable where find retuns the value*/
#define FIND_ARRAY(arr, val, ret, type) \
  { \
    type a = val; \
    ret = find_array(arr, &a); \
  }

#endif

typedef struct {
  void *elements; /** storing elements */
  size_t padding; /** size of a single allocated element*/
  size_t capacity; /** current max size of the elements */
  int32_t end; /** last element */
} Array;

Array *init_array(void *elements, size_t padding, size_t capacity, size_t count);

void push_array(Array *array, void *element);
void pop_array(Array *array);

/**
 * insert element between two indexes
 * @param array Array pointer object
 * @param element entry to array
 * @param index location to insert
 * @return NULL
 * */
void insert_array(Array *array, void *element, int32_t index);
void delete_array(Array *array, int32_t index);

void *get_array(Array *array, int32_t index);
void set_array(Array *array, void *element, int32_t index);

/**
 * get index location of element 
 * @param array Array pointer object
 * @param element Element to search
 * @return Index of element or end of the array if none found
 **/
int32_t find_array(Array *array, void *element);

/**
 * resize by setting the capacity
 * @param array Array pointer object
 * @param capacity New size of array
 * @return NULL
 * */
void resize_array(Array *array, size_t capacity);

void release_array(Array *array);

#endif
