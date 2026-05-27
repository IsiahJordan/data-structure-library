#include "ds/queue.h"
#include <stdio.h>
#include <string.h>

Queue *init_queue(size_t padding) {
  Queue *s = (Queue *)malloc(sizeof(Queue));
  if (s == NULL) {
    perror("init_queue: failed malloc"); 
    return NULL;
  }

  s->count = 0;
  s->padding = padding;
  return s;
}

void push_queue(
  Queue *bot, 
  void *val
) {
  if (bot == NULL) {
    perror("push_queue: invalid arguments");
    return;
  }
  
  if (bot->count == 0) {
    bot->list = init_listnode(val, bot->padding, NULL);
  }
  else {
    push_listnode(bot->list, val);
  }
  bot->count++;
}

void pop_queue(
  Queue *bot
) {
  if (bot == NULL || bot->count <= 0) {
    perror("pop_queue: invalid arguments");
    return;
  }

  ListNode *temp = bot->list->next;
  free(bot->list);
  
  bot->list = temp;
  bot->count--;
}

void *front_queue(
  Queue *bot
) {
  if (bot == NULL || bot->count <= 0) {
    return NULL;
  }

  return bot->list->val;
}

void release_queue(
  Queue *bot
) {
  if (bot == NULL) {
    return;
  }
  
  if (bot->list != NULL) {
    release_listnode(bot->list);
  }
  free(bot);
}
