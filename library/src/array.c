#include "ds_library/array.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

void* _random_access(void* collection, size_t index) {
  ArrayList* collect = (ArrayList*)collection;
  if (collect == NULL) {
    perror("[ArrayList random access]");
    return NULL;
  }
  else if (index >= collect->data->size) {
    perror("[ArrayList random access]");
    return NULL;
  }

  return (void*)((char*)collect->data->el + index*collect->data->padding);
}

void* _sequence_access(void* collection) {
  LinkedNode* collect = (LinkedNode*)collection; 
  if (collect == NULL || collect->next == NULL) {
    perror("[LinkedNode random access]");
    return NULL;
  }
  
  return collect->next;
}

// ========== Accessible Features ==========

ArrayList *init_array_list(
      void *entry, // data for collection to store
      size_t size,
      size_t padding,
      size_t capacity
    ){
  Collection *collect = (Collection*)malloc(sizeof(Collection));
  if (collect == NULL) {
    perror("[ArrayList init]");
    return NULL;
  }

  collect->el = entry;
  collect->size = size;
  collect->padding = padding;
  collect->capacity = capacity;
  collect->iter = (Iterator*)malloc(sizeof(Iterator));
  if (collect->iter == NULL) {
    perror("[ArrayList init]");
    return NULL;
  }

  collect->iter->type = ITER_RANDOM;
  collect->iter->ra.index_next = _random_access;

  ArrayList* ds = (ArrayList*)malloc(sizeof(ArrayList));
  if (ds == NULL) {
    perror("[ArrayList init]");
    return NULL;
  }

  ds->data = collect;

  return ds;
}

LinkedNode *init_linked_list(void *entry){
  Collection *collect = (Collection*)malloc(sizeof(Collection));
  if (collect == NULL) {
    perror("[LinkedNode init]");
    return NULL;
  }

  collect->el = entry;
  collect->iter = (Iterator*)malloc(sizeof(Iterator));
  if (collect->iter == NULL) {
    perror("[LinkedNode init]");
    return NULL;
  }

  collect->iter->type = ITER_SEQUENCE;
  collect->iter->seq.node_next = _sequence_access;

  LinkedNode* ds = (LinkedNode*)malloc(sizeof(LinkedNode));
  if (ds == NULL) {
    perror("[LinkedNode init]");
    return NULL;
  }

  ds->data = collect;
  ds->next = NULL;

  return ds;
}

void *access_array_list(ArrayList* array, size_t index){
  return array->data->iter->ra.index_next((void*)array, index); 
}

void *access_linked_list(LinkedNode* list, size_t index){
  LinkedNode* curr = list;

  for (size_t i = 0; i < index; i++) {
    if (curr == NULL) {
      perror("[LinkNode access]");
      break;
    }
    
    curr = (LinkedNode*)curr->data->iter->seq.node_next((void*)curr);
  }

  if (curr == NULL) {
    perror("[LinkNode access]");
    return NULL;
  }

  return curr->data->el;
}

void set_array_list(ArrayList *array, size_t index, void *value){
  if (array == NULL) {
    perror("[ArrayList insert]");
    return;
  }
  else if (index >= array->data->size) {
    perror("[ArrayList insert]");
    return;
  }

  void* dest = (char*)array->data->el + index*array->data->padding; 

  memcpy(dest, value, array->data->padding);
}

void set_linked_list(LinkedNode *list, size_t index, void *value){
  LinkedNode* curr = list;

  for (size_t i = 0; i < index; i++) {
    if (curr == NULL) {
      perror("[LinkNode insert]");
      break;
    }
    
    curr = (LinkedNode*)curr->data->iter->seq.node_next((void*)curr);
  }

  if (curr == NULL) {
    perror("[LinkNode insert]");
    return;
  }

  curr->data->el = value;
}

void release_array_list(ArrayList *array) {
  free(array);
}

void release_linked_list(LinkedNode *list){
  free(list);
}

