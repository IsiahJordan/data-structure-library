#ifndef DS_ALGORITHM_H
#define DS_ALGORITHM_H


/*
 * requires left and right child
 * such us the binary tree data structure
 * */

enum NodeType {
  INT_TYPE,
  FLOAT_TYPE,
  CHAR_TYPE,
  LONG_TYPE,
  DOUBLE_TYPE,
  STRING_TYPE
};

void *alg_postorder(void *collection, enum NodeType type);
void *alg_preorder(void *collection, enum NodeType type);

#endif
