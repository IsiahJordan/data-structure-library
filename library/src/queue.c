#include "ds_library/queue.h"
#include <stdio.h>

Queue *init_queue(void *entry) {
  LinkedNode *node = init_linked_list(entry);
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  
  queue->node = node;
  queue->start = entry;

  return queue;
}

void push_queue(Queue *queue, void *value) {
  if (queue == NULL) {
    perror("[queue push]");
    return;
  }

  push_linked_list(queue->node, value);
}

void *peek_queue(Queue *queue) {
  if (queue == NULL) {
    perror("[queue peek]");
    return NULL;
  }
  else if (queue->node->data->size == 0) {
    return NULL;
  } 

  void *value = access_linked_list(queue->node, 0);
  return value;
}

void pop_queue(Queue *queue) {
  if (queue == NULL) {
    perror("[queue pop]");
    return;
  }

  pop_linked_list(queue->node);
}

bool empty_queue(Queue *queue) {
  if (queue == NULL) {
    return true;
  }

  empty_linked_list(queue->node);
}

void release_queue(Queue *queue) {
  free(queue);
}

