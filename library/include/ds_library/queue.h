#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include "array.h"

enum PeekType {
  FRONT_PEEK,
  BACK_PEEK
};

typedef struct {
  LinkedNode *node;
  void *start; // front element of queue
} Queue;

typedef struct {
  LinkedNode *node;
  void *start; // front element of queue
} Deque;

Queue *init_queue(void *entry);
void push_queue(Queue *queue, void *value);
void *peek_queue(Queue *queue);
void pop_queue(Queue *queue);
bool empty_queue(Queue *queue);
void release_queue(Queue *queue);

Deque *init_deque(void *entry);
void push_deque(Deque *deque, void *value);
void *peek_deque(Deque *deque, enum PeekType type);
void pop_deque(Deque *deque);
bool empty_deque(Deque *deque);
void release_deque(Deque *deque);

#endif
