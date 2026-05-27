#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include "list.h"

#if defined(DS_MACRO_QUEUE_ENABLED) || defined(DS_MACRO_ENABLED)

#define FRONT_QUEUE(bot, type) \
  *(type *)front_queue(bot)

#endif


/** 
 * practically similar to stack
 * but we treat the insertion as 
 * a push back rather than insert
 * in index 0
 **/
typedef struct {
  ListNode *list;
  int32_t count;
  size_t padding;
} Queue;

Queue *init_queue(size_t padding);

void push_queue(Queue *bot, void *val);
void pop_queue(Queue *bot);

void *front_queue(Queue *bot);
void release_queue(Queue *bot);

#endif
