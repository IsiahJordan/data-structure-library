#include "ds_library/algorithm.h"
#include "ds_library/tree.h"
#include "ds_library/stack.h"
#include "ds_library/queue.h"
#include <stdio.h>
#include <stdint.h>

void alg_postorder(void *tree, ArrayList *visited) {
  BinaryTree *_tree = (BinaryTree*)tree;
  if (_tree == NULL) {
    return;
  }
  else if (_tree->left == NULL && _tree->right == NULL) {
    push_array_list(visited, _tree->data->el);
    return; 
  }
  
  alg_postorder(_tree->left, visited);
  alg_postorder(_tree->right, visited);
  push_array_list(visited, _tree->data->el);
}

void alg_preorder(void *tree, ArrayList *visited) {
  BinaryTree *_tree = (BinaryTree*)tree;

  if (_tree == NULL) {
    return;
  }
  else if (_tree->left == NULL && _tree->right == NULL) {
    push_array_list(visited, _tree->data->el);
    return; 
  }
  
  push_array_list(visited, _tree->data->el);
  alg_postorder(_tree->left, visited);
  alg_postorder(_tree->right, visited);
}

void alg_inorder(void *tree, ArrayList *visited) {
  BinaryTree *_tree = (BinaryTree*)tree;

  if (_tree == NULL) {
    return;
  }
  else if (_tree->left == NULL && _tree->right == NULL) {
    push_array_list(visited, _tree->data->el);
    return; 
  }
  
  alg_postorder(_tree->left, visited);
  push_array_list(visited, _tree->data->el);
  alg_postorder(_tree->right, visited);
}
