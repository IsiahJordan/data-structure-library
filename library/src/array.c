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

  collect->el = malloc(padding*capacity);
  if (collect->el == NULL) {
    perror("[ArrayList init]");
    free(collect);
    return NULL;
  }
  else if (entry && size > 0) {
    memcpy(collect->el, entry, size * padding);
  }

  collect->size = size;
  collect->padding = padding;
  collect->capacity = capacity;
  collect->iter = (Iterator*)malloc(sizeof(Iterator));
  if (collect->iter == NULL) {
    perror("[ArrayList init]");
    free(collect);
    return NULL;
  }

  collect->iter->type = ITER_RANDOM;
  collect->iter->ra.index_next = _random_access;

  ArrayList* ds = (ArrayList*)malloc(sizeof(ArrayList));
  if (ds == NULL) {
    perror("[ArrayList init]");
    free(collect);
    free(ds);
    return NULL;
  }

  ds->data = collect;

  return ds;
}

LinkedNode *init_linked_list(void *entry) {
  Collection *collect = (Collection*)malloc(sizeof(Collection));
  if (collect == NULL) {
    perror("[LinkedNode init]");
    return NULL;
  }

  collect->el = entry;
  collect->size = 1;
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

void *access_linked_list(LinkedNode* list, size_t index) {
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

void set_array_list(ArrayList *array, size_t index, void *value) {
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

void set_linked_list(LinkedNode *list, size_t index, void *value) {
  if (list == NULL) {
    perror("[LinkedNode pop]");
    return;
  }

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

void push_array_list(ArrayList *array, void *value) {
  if (array == NULL) {
    perror("[ArrayList push]");
    return;
  }
  else if (array->data->capacity == array->data->size) {
    perror("[ArrayList push]");
    return;
  } 
  
  void* dest = (char*)array->data->el + array->data->size*array->data->padding;
  memcpy(dest, value, array->data->padding);

  array->data->size++;
}

void push_linked_list(LinkedNode *list, void *value) {
  if (list == NULL) {
    perror("[LinkedNode pop]");
    return;
  }

  LinkedNode* curr = list;

  while(curr->next != NULL) {    
    curr = (LinkedNode*)curr->data->iter->seq.node_next((void*)curr);
  }

  curr->next = init_linked_list(value);
  list->data->size++;
}

void pop_array_list(ArrayList *array) {
  if (array == NULL) {
    perror("[ArrayList pop]");
    return;
  }
  else if (array->data->size == 0) {
    perror("[ArrayList pop]");
    return;
  } 
  
  array->data->size--;
}

void pop_linked_list(LinkedNode *list) {
  if (list == NULL) {
    perror("[LinkedNode pop]");
    return;
  }

  LinkedNode* curr = list;

  while(curr->next != NULL) {    
    LinkedNode* next = curr->next;
    if (next->next == NULL) {
      break;
    }
    curr = (LinkedNode*)curr->data->iter->seq.node_next((void*)curr);
  }

  free(curr->next);
  curr->next = NULL;
  list->data->size--;
}

bool empty_linked_list(LinkedNode *list) {
  if (list == NULL) {
    return true;
  }

  return list->data->size == 0;  
}

void erase_linked_list(LinkedNode *list, size_t index) {
  if (list == NULL) {
    perror("[LinkedNode erase]");
    return;
  }
  else if (index < 0 || index >= list->data->size) {
    perror("[LinkedNode erase]");
    return;
  }
  
  LinkedNode *curr = list;
  size_t before_curr = 0;

  if (before_curr == index) {
    curr = (LinkedNode*)list->data->iter->seq.node_next((void*)curr);
    release_linked_list(list);
    list = curr;
  }
  else {
    for (size_t i = 0; i < index-1; i++) {
      if (curr->next == NULL) {
        perror("[LinkedNode erase]");
        return;
      }

      curr = (LinkedNode*)curr->data->iter->seq.node_next((void*)curr);
    }

    LinkedNode *next_node = (LinkedNode*)curr->data->iter->seq.node_next((void*)curr);
    curr->next = next_node->next;
    release_linked_list(next_node);
  } 
}

void insert_linked_list(LinkedNode *list, size_t index, void *value) {
  if (list == NULL) {
    perror("[LinkedList insert]");
    return;
  }
  else if (index < 0 || index >= list->data->size) {
    perror("[LinkedNode insert]");
    return;
  }
  
  size_t before_curr = 0;
  LinkedNode *node  = init_linked_list(value);

  if (before_curr == index) {
    node->next = list;
    list = node;
  }
  else {
    LinkedNode *curr = list;
    LinkedNode *next_node = curr->next;

    for (size_t i = 0; i < index; i++) {
      curr = (LinkedNode*)curr->data->iter->seq.node_next((void*)curr);
      next_node = curr->next;
    }

    curr->next = node;
    if (next_node != NULL) {
      node->next = next_node;
    }
  } 
}

void release_array_list(ArrayList *array) {
  free(array);
}

void release_linked_list(LinkedNode *list) {
  free(list);
}

ArrayList *create_array_list(size_t capacity, enum DataType type) {
  switch (type) {
    case INT_TYPE:
      int int_empty[] = {};
      ArrayList *int_array = init_array_list(int_empty, 0, sizeof(int), capacity);
      return int_array;
    case FLOAT_TYPE:
      float float_empty[] = {};
      ArrayList *float_array = init_array_list(float_empty, 0, sizeof(float), capacity);
      return float_array;
    case DOUBLE_TYPE:
      double double_empty[] = {};
      ArrayList *double_array = init_array_list(double_empty, 0, sizeof(double), capacity);
      return double_array;
    case CHAR_TYPE:
      char char_empty[] = {};
      ArrayList *char_array = init_array_list(char_empty, 0, sizeof(char), capacity);
      return char_array;
    case STRING_TYPE:
      char* string_empty[] = {};
      ArrayList *string_array = init_array_list(string_empty, 0, sizeof(char*), capacity);
      return string_array;
    case LONG_TYPE:
      long long_empty[] = {};
      ArrayList *long_array = init_array_list(long_empty, 0, sizeof(long), capacity);
      return long_array;
    default:
      perror("[ArrayList create]");
      return NULL;
  }
}
