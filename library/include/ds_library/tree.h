#ifndef DS_TREE_H
#define DS_TREE_H

#include "base.h"
#include "algorithm.h"

typedef struct {
  Collection *data;
  void *left;
  void *right;
} BinaryTree;

// on what order do you want
// the traversing of nodes
typedef enum {
  INORDER_METHOD,
  POSTORDER_METHOD,
  PREORDER_METHOD,
  LEVELORDER_METHOD
} TraverseMethod;

BinaryTree *init_binary_tree(void* entry);
void *access_binary_tree(BinaryTree* tree, size_t index, TraverseMethod type);
void push_binary_tree(BinaryTree* tree, size_t index, TraverseMethod type);
void pop_binary_tree(BinaryTree* tree, size_t index, TraverseMethod type);

#endif
