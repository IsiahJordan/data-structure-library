#include "ds_library/tree.h"
#include "ds_library/array.h"
#include <stdio.h>

BinaryTree *init_binary_tree(void *entry, enum DataType type) {
  Collection *collect = (Collection*)malloc(sizeof(Collection));
  if (collect == NULL) {
    perror("[BinaryTree init]");
    return NULL;
  }

  collect->el = entry;
  collect->size = 1;
  collect->type = type;
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

void *access_binary_tree(BinaryTree *tree, size_t index, enum TraverseMethod type) {
  switch (type) {
    case INORDER_METHOD:
      ArrayList *in_vis = create_array_list(tree->data->size, tree->data->type);
      alg_inorder(tree, in_vis);

      void* in_val = access_array_list(in_vis, index);
      return in_val;
    case POSTORDER_METHOD:
      ArrayList *post_vis = create_array_list(tree->data->size, tree->data->type);
      alg_postorder(tree, post_vis);

      void* post_val = access_array_list(post_vis, index);
      return post_val;
    case PREORDER_METHOD:
      ArrayList *pre_vis = create_array_list(tree->data->size, tree->data->type);
      alg_preorder(tree, pre_vis);

      void* pre_val = access_array_list(pre_vis, index);
      return pre_val;
    default:
      perror("[BinaryTree access]");
      return NULL;
  }
}

void push_binary_tree(BinaryTree *tree, size_t index, enum TraverseMethod type) {

}

void pop_binary_tree(BinaryTree *tree, size_t index, enum TraverseMethod type) {

}
