#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include "array.h"

typedef struct {
  LinkedNode *node;
  void *start; // front element of queue
} Queue;

Queue *init_queue(void *entry);
void push_queue(Queue *queue, void *value);
void *peek_queue(Queue *queue);
void pop_queue(Queue *queue);
bool empty_queue(Queue *queue);
void release_queue(Queue *queue);

#endif
