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
  BTreeArgs args = {};
  bool proceed = true;

  switch (type) {
    case INORDER_METHOD:
      ArrayList *in_vis = create_array_list(tree->data->size, tree->data->type);
      alg_inorder(tree, NULL, in_vis, &proceed, args);

      void* in_val = access_array_list(in_vis, index);
      return in_val;
    case POSTORDER_METHOD:
      ArrayList *post_vis = create_array_list(tree->data->size, tree->data->type);
      alg_postorder(tree, NULL, post_vis, &proceed, args);

      void* post_val = access_array_list(post_vis, index);
      return post_val;
    case PREORDER_METHOD:
      ArrayList *pre_vis = create_array_list(tree->data->size, tree->data->type);
      alg_preorder(tree, NULL, pre_vis, &proceed, args);

      void* pre_val = access_array_list(pre_vis, index);
      return pre_val;
    default:
      perror("[BinaryTree access]");
      return NULL;
  }
}

// this is not accessible and design to be 
// a utility to push back binary tree
bool _push_callback_bt(void *tree, BTreeArgs args) {
  BinaryTree *_tree = tree;
  if (_tree != NULL) {
    perror("push callback tree not defined");
    return true;
  }
  else if (_tree->left == NULL && args.index == args.count) {
    BinaryTree *ext = init_binary_tree(args.value, _tree->data->type);
    _tree->left = ext;
    return false;
  }
  else if (_tree->left != NULL && _tree->right == NULL && args.index == args.count)
  {
    BinaryTree *ext = init_binary_tree(args.value, _tree->data->type);
    _tree->right = ext;
    return false;
  }

  return true;
}

void push_binary_tree(BinaryTree *tree, void *addition, size_t index, enum TraverseMethod type) {
  bool proceed_flag = true; // required for function callback

  switch (type) {
    case INORDER_METHOD:
      ArrayList *in_vis = create_array_list(tree->data->size, tree->data->type);
      BTreeArgs args = { .value = addition, .index = index, .count = 0 };
      alg_inorder(tree, _push_callback_bt, in_vis, &proceed_flag, args);
      return;
    case POSTORDER_METHOD:
      ArrayList *post_vis = create_array_list(tree->data->size, tree->data->type);
      alg_postorder(tree, _push_callback_bt, post_vis, &proceed_flag, args);
      return;
    case PREORDER_METHOD:
      ArrayList *pre_vis = create_array_list(tree->data->size, tree->data->type);
      alg_preorder(tree, _push_callback_bt, pre_vis, &proceed_flag, args);
      return;
    default:
      perror("[BinaryTree push]");
      return;
  }
}

// this is not accessible and design to be 
// a utility to pop back binary tree
bool _pop_callback_bt(void *tree, BTreeArgs args) {
  BinaryTree *_tree = tree;

  if (_tree != NULL) {
    perror("pop callback tree not defined");
    return true;
  }
  else if (_tree->left == NULL && _tree->right == NULL && args.index == args.count) {
    _tree = NULL;
    return false;
  }

  return true;
}

void pop_binary_tree(BinaryTree *tree, size_t index, enum TraverseMethod type) {
  bool proceed_flag = true;

  switch (type) {
    case INORDER_METHOD:
      ArrayList *in_vis = create_array_list(tree->data->size, tree->data->type);
      BTreeArgs args = { .value = NULL, .index = index, .count = 0 };
      alg_inorder(tree, _pop_callback_bt, in_vis, &proceed_flag, args);
      return;
    case POSTORDER_METHOD:
      ArrayList *post_vis = create_array_list(tree->data->size, tree->data->type);
      alg_postorder(tree, _pop_callback_bt, post_vis, &proceed_flag, args);
      return;
    case PREORDER_METHOD:
      ArrayList *pre_vis = create_array_list(tree->data->size, tree->data->type);
      alg_preorder(tree, _pop_callback_bt, pre_vis, &proceed_flag, args);
      return;
    default:
      perror("[BinaryTree pop]");
      return;
  }

}


