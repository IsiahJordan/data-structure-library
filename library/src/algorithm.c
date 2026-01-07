#include "ds_library/algorithm.h"
#include <stdio.h>
#include <stdint.h>

void *alg_postorder(void *collection, enum NodeType type) {
  switch(type) {
    case INT_TYPE:
      break;
    case FLOAT_TYPE:
      break;
    case DOUBLE_TYPE:
      break;
    case CHAR_TYPE:
      break;
    case STRING_TYPE:
      break;
    case LONG_TYPE:
      break;
    default:
      perror("[algorithm postorder]");
  }
}

void *alg_preorder(void *collection, enum NodeType type) {
  switch(type) {
    case INT_TYPE:
      break;
    case FLOAT_TYPE:
      break;
    case DOUBLE_TYPE:
      break;
    case CHAR_TYPE:
      break;
    case STRING_TYPE:
      break;
    case LONG_TYPE:
      break;
    default:
      perror("[algorithm preorder]");
  }
}
