#include "ds_library/tree.h"
#include <stdio.h>

BinaryTree *init_binary_tree(void *entry) {
  Collection *collect = (Collection*)malloc(sizeof(Collection));
  if (collect == NULL) {
    perror("[BinaryTree init]");
    return NULL;
  }

  collect->el = entry;
  BinaryTree *ds = (BinaryTree*)malloc(sizeof(BinaryTree));
  if (ds == NULL) {
    perror("[BinaryTree init]");
    return NULL;
  }

  ds->data = collect;
  ds->left = NULL;
  ds->right = NULL;

  return ds;
}

void *access_binary_tree(BinaryTree *tree, size_t index, TraverseMethod type) {

}

void push_binary_tree(BinaryTree *tree, size_t index, TraverseMethod type) {

}

void pop_binary_tree(BinaryTree *tree, size_t index, TraverseMethod type) {

}
