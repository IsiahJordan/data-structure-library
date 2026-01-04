#ifndef DS_BASE_H
#define DS_BASE_H

/*
 * this designed to handle 
 * common structure and 
 * iterator process including 
 * macros
 * 
 * Definitions:
 *  - Collection is the convinient
 *    name for the struct of different 
 *    ways to store values
 * */

#include <stdlib.h>

typedef enum {
  ITER_RANDOM,
  ITER_SEQUENCE
} IterType;

// Iteration Options
typedef struct {
  void *(*index_next)(void *collection, size_t index); // index based computation
} RandomAccessIterator;

typedef struct {
  void *(*node_next)(void *collection); // linked based
} SequentialIterator;

typedef struct {
  IterType type;
  union {
    RandomAccessIterator ra;
    SequentialIterator seq;
  };
} Iterator;

// Valid structures
typedef struct {
  void *el;
  size_t capacity; // max size
  size_t size; // current occupated elements
  size_t padding; // size type
  Iterator *iter;
} Collection;

#endif
