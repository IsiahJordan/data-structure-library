#include "ds/list.h"
#include <stdio.h>

ListNode *init_listnode(
  void *val, 
  size_t padding, 
  void *next
) {
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));
  if (node == NULL) {
    perror("init_listnode: invalid arguments");
    return NULL;
  }

  node->val = val;
  node->padding = padding;
  node->next = next;
  return node;
}

void push_listnode(
  ListNode *head, 
  void *val
) {
  if (head == NULL) {
    perror("push_listnode: invalid arguments");
    return;
  }

  ListNode *iter = head; /** prevent changing memblock with next */

  /** if NULL val in head, we still view at as a occupied */
  while (iter->next != NULL) {
    iter = (ListNode *)iter->next;
  }

  iter->next = init_listnode(val, iter->padding, NULL);
}

void pop_listnode(
  ListNode *head
) {
  if (head == NULL) {
    perror("pop_listnode: invalid arguments");
    return;
  }

  ListNode *iter = head;

  while (iter->next != NULL) {
    ListNode *next = iter->next;
    if (next->next == NULL) {
      break;
    }

    iter = (ListNode *)iter->next;
  }

  free(iter->next);
  iter->next = NULL;
}

void insert_listnode(
  ListNode *head, 
  void *val, 
  int32_t index
) {
  if (head == NULL || index < 0) {
    perror("insert_listnode: invalid arguments");
    return;
  }
  
  ListNode *prev = NULL;
  ListNode *iter = head;

  while (index > 0 && iter != NULL) {
    prev = iter;
    iter = (ListNode *)iter->next;
    index--;
  }

  if (index > 0) {
    perror("insert_listnode: index overflow");
    return;
  }

  ListNode *temp = init_listnode(val, head->padding, (void *)iter);
  if (prev != NULL) {
    prev->next = temp;
  }
}

void delete_listnode(
  ListNode *head, 
  int32_t index
) {
  if (head == NULL || index < 0) {
    perror("delete_listnode: invalid arguments");
    return;
  }
  
  ListNode *prev = NULL;
  ListNode *iter = head;

  while (index > 0 && iter != NULL) {
    prev = iter;
    iter = (ListNode *)iter->next;
    index--;
  }

  if (index > 0) {
    perror("delete_listnode: index overflow");
    return;
  }

  prev->next = iter->next;
  free(iter);
}

void set_listnode(
  ListNode *head, 
  void *val, 
  int32_t index
) {
  if (head == NULL) {
    perror("set_listnode: invalid argument");
    return;
  }
  
  ListNode *iter = head;
  while (index > 0 && iter != NULL) {
    iter = (ListNode *)iter->next;
    index--;
  }

  if (index > 0) {
    perror("set_listnode: index overflow");
    return;
  }

  iter->val = val;
}

ListNode *get_listnode(
  ListNode *head, 
  int32_t index
) {
  if (head == NULL) {
    perror("get_listnode: invalid argument");
    return NULL;
  }
  
  ListNode *iter = head; /** prevent replacing head pointer with next */

  while (index > 0 && iter != NULL) {
    iter = (ListNode *)iter->next;
    index--;
  }

  if (index > 0) {
    perror("get_listnode: index overflow");
    return NULL;
  }

  return iter;
}

ListNode *tail_listnode(
  ListNode *head
) {
  if (head == NULL) {
    perror("tail_listnode: invalid argument");
    return NULL;
  }
  
  ListNode *iter = head;
  while (iter->next != NULL) {
    iter = (ListNode *)iter->next;
  }

  return iter;
}

int32_t find_listnode(
  ListNode *head, 
  void *val
) {
  if (head == NULL) {
    perror("find_listnode: invalid argument");
    return -1;
  }
  
  int32_t index = 0; 
  ListNode *iter = head;
  while (iter != NULL && (char *)val != (char *)iter->val) {
    index++;
    iter = (ListNode *)iter->next;
    if (iter == NULL) {
      return -1;
    }
  }

  return index;
}

size_t count_listnode(
  ListNode *head
) {
  
  size_t count = 0;
  ListNode *iter = head;
  while (iter != NULL && iter->next != NULL) {
    iter = (ListNode *)iter->next;
    count++;
  }

  return count;
}

void release_listnode(ListNode *head) {
  if (head == NULL) {
    return;
  }

  ListNode *iter = head;
  while(iter->next != NULL) {
    iter = iter->next;
    free(head);
    head = iter;
  }
  free(iter);
}
