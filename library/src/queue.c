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

Deque *init_deque(void *entry) {
  LinkedNode *node = init_linked_list(entry);
  Deque *deque = (Deque*)malloc(sizeof(Deque));
  
  deque->node = node;
  deque->start = entry;

  return deque;
}

void push_deque(Deque *deque, void *value, enum ViewType type) {
  if (deque == NULL) {
    perror("[deque push]");
    return;
  }

  switch(type) {
    case BACK_VIEW:
      push_linked_list(deque->node, value);
      break;
    case FRONT_VIEW:
      insert_linked_list(deque->node, 0, value);
      break;
    default:
      perror("[deque push]");
      break;
  }
}

void *peek_deque(Deque *deque, enum ViewType type) {
  if (deque == NULL) {
    perror("[deque peek]");
    return NULL;
  }
  else if (deque->node->data->size == 0) {
    return NULL;
  } 
  
  switch (type) {
    case FRONT_VIEW:
      void *value = access_linked_list(deque->node, 0);
      return value;
    case BACK_VIEW:
      value = access_linked_list(deque->node, deque->node->data->size-1);
      return value;
    default:
      return NULL;
  }
}

void pop_deque(Deque *deque, enum ViewType type) {
  if (deque == NULL) {
    perror("[deque pop]");
    return;
  }

  switch(type) {
    case BACK_VIEW:
      pop_linked_list(deque->node);
      break;
    case FRONT_VIEW:
      erase_linked_list(deque->node, 0);
      break;
    default:
      perror("[deque push]");
      break;
  }
}

bool empty_deque(Deque *deque) {
  if (deque == NULL) {
    return true;
  }

  empty_linked_list(deque->node);
}


void release_deque(Deque *deque) {
  free(deque);
}
