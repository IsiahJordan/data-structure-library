#include "ds_library/algorithm.h"
#include "ds_library/tree.h"
#include "ds_library/stack.h"
#include "ds_library/queue.h"
#include <stdio.h>
#include <stdint.h>

void alg_postorder(void *tree, Callback callback, ArrayList *visited, bool *proceed, BTreeArgs args) {
  BinaryTree *_tree = (BinaryTree*)tree;
  if (_tree == NULL || (proceed == NULL && *proceed == false)) {
    return;
  }
  else if (_tree->left == NULL && _tree->right == NULL) {
    if (callback != NULL) {
      *proceed = callback(_tree, args);
    }

    push_array_list(visited, _tree->data->el);
    return; 
  }
  
  alg_postorder(_tree->left, callback, visited, proceed, args);
  alg_postorder(_tree->right, callback, visited, proceed, args);

  if (callback != NULL) {
    *proceed = callback(_tree, args);
    args.count = args.count == NULL ? NULL : args.count + 1;
  }
  push_array_list(visited, _tree->data->el);
}

void alg_preorder(void *tree, Callback callback, ArrayList *visited, bool *proceed, BTreeArgs args) {
  BinaryTree *_tree = (BinaryTree*)tree;

  if (_tree == NULL || (proceed != NULL && *proceed == false)) {
    return;
  }
  else if (_tree->left == NULL && _tree->right == NULL) {
    if (callback != NULL) {
      *proceed = callback(_tree, args);
    }
    push_array_list(visited, _tree->data->el);
    return; 
  }
  
  if (callback != NULL) {
    *proceed = callback(_tree, args);
  }
  push_array_list(visited, _tree->data->el);
  alg_postorder(_tree->left, callback, visited, proceed, args);
  alg_postorder(_tree->right, callback, visited, proceed, args);
}

void alg_inorder(void *tree, Callback callback, ArrayList *visited, bool *proceed, BTreeArgs args) {
  BinaryTree *_tree = (BinaryTree*)tree;
  if (_tree == NULL || (proceed != NULL && *proceed == false)) {
    return;
  }
  else if (_tree->left == NULL && _tree->right == NULL) {
    if (callback != NULL) {
      *proceed = callback(_tree, args);
    }
    push_array_list(visited, _tree->data->el);
    return; 
  }
  
  alg_postorder(_tree->left, callback, visited, proceed, args);

  if (callback != NULL) {
    *proceed = callback(_tree, args);
  }
  push_array_list(visited, _tree->data->el);
  alg_postorder(_tree->right, callback, visited, proceed, args);
}
