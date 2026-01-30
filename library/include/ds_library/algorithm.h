#ifndef DS_ALGORITHM_H
#define DS_ALGORITHM_H


/*
 * requires left and right child
 * such us the binary tree data structure
 * */

#include "ds_library/array.h"

typedef struct {
  void *value;
  size_t index;
  size_t count;
} BTreeArgs;

typedef bool (*Callback)(void*, BTreeArgs);

// assuming visited has enough capacity
// to fit all of binary tree. Also binary
// tree is needed which will be cased on implement
void alg_postorder(void *tree, Callback callback, ArrayList *visited, bool *proceed, BTreeArgs args);
void alg_preorder(void *tree, Callback callback, ArrayList *visited, bool *proceed, BTreeArgs args);
void alg_inorder(void *tree, Callback callback, ArrayList *visited, bool *proceed, BTreeArgs args);

#endif
