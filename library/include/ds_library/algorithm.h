#ifndef DS_ALGORITHM_H
#define DS_ALGORITHM_H


/*
 * requires left and right child
 * such us the binary tree data structure
 * */

#include "ds_library/array.h"
#include <stdbool.h>

// assuming visited has enough capacity
// to fit all of binary tree
void alg_postorder(void *tree, ArrayList *visited);
void alg_preorder(void *tree, ArrayList *visited);
void alg_inorder(void *tree, ArrayList *visited);

#endif
