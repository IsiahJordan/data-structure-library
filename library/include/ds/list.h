#ifndef DS_LIST_H
#define DS_LIST_H

#include <stdlib.h>
#include <stdint.h>

/**
 * use macro for handling annoying things in code
 **/
#if defined(DS_MACRO_LST_ENABLED) || defined(DS_MACRO_ENABLED)

/** practice is left are function args and the right are additions */

#define INIT_LISTNODE(val, padding, next, ret, type) \
  { \
    type a = val; \
    ret = init_listnode(&a, padding, next); \
  }

#define PUSH_LISTNODE(head, val, type) \
 { \
   type a = val; \
   push_listnode(head, &a); \
 }

#define INSERT_LISTNODE(head, val, index, type) \
 { \
   type a = val; \
   insert_listnode(head, &a, index); \
 }

#define SET_LISTNODE(head, val, index, type) \
 { \
   type a = val; \
   set_listnode(head, &a, index); \
 }

#define FIND_LISTNODE(head, val, ret, type) \
 { \
   type a = val; \
   ret = find_listnode(head, &a); \
 }

#define GET_LISTNODE(head, index, type) \
  *(type*)(get_listnode(head, index)->val)
 
#endif

/**
 * ds handles singly linked list
 **/

typedef struct {
  void *val;
  size_t padding; /** size of data type in bytes */
  void *next; 
} ListNode;

/** create singly linked list 
 * @param val Store any data value to head node (optionally NULL) 
 * @param padding Fixed data type size for all nodes
 * @param next Optionally NULL
 * return Pointer to linked list node
 **/
ListNode *init_listnode(void *val, size_t padding, void *next);

/**1
 * push value and create a new list node as tail
 * @param head Start node
 * @param val Value to store
 * @return NULL
 **/
void push_listnode(ListNode *head, void *val);
void pop_listnode(ListNode *head);

void insert_listnode(ListNode *head, void *val, int32_t index);
void delete_listnode(ListNode *head, int32_t index);

void set_listnode(ListNode *head, void *val, int32_t index);
ListNode *get_listnode(ListNode *head, int32_t index);
ListNode *tail_listnode(ListNode *head);

int32_t find_listnode(ListNode *head, void *val);

/** count how many nodes */
size_t count_listnode(ListNode *head);

#endif
