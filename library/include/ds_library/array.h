#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include "base.h"
#include <stdbool.h>

typedef struct {
  Collection* data; 
} ArrayList;


#ifndef CIRCULAR_LK // circluar linked list macro

typedef struct {
  Collection *data;
  void *next;
} LinkedNode;

#else

typedef struct {
  Collection *data;
  void *next;
  void *prev
} LinkedNode;

#endif

ArrayList *init_array_list(
      void *entry, // data for collection to store
      size_t size,
      size_t padding,
      size_t capacity
    );
LinkedNode *init_linked_list(
      void *entry
    );

void *access_array_list(ArrayList *array, size_t index);
void *access_linked_list(LinkedNode *list, size_t index);

void set_array_list(ArrayList *array, size_t index, void *value);
void set_linked_list(LinkedNode *list, size_t index, void *value);

void push_array_list(ArrayList *array, void *value);
void push_linked_list(LinkedNode *list, void *value);

void pop_array_list(ArrayList *array);
void pop_linked_list(LinkedNode *list);

void release_array_list(ArrayList *array);
void release_linked_list(LinkedNode *list);

bool empty_linked_list(LinkedNode *list);

#endif
