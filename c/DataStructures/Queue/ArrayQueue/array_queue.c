/**********************************************
 > File Name: array_queue.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: Implement stack with array
***********************************************/

#include "array_queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *init_queue(int cap) {
  if (cap < 0) {
    return NULL;
  }
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue == NULL) {
    return NULL;
  }
  queue->arr = (int *)malloc(sizeof(int) * cap);
  if (queue->arr == NULL) {
    free(queue);
    queue = NULL;
    return NULL;
  }
  queue->capacity = cap;
  queue->length = 0;
  queue->head = -1;
  queue->tail = -1;
  return queue;
}

void destroy(Queue *queue) {
}

int en_queue(Queue *queue, int data) {
  if (queue == NULL) {
    return -1;
  }
  if (is_full(queue)) {
    return -1;
  }
  if (is_empty(queue)) {
    queue->head++;
    queue->tail++;
    queue->arr[queue->tail] = data;
    queue->length++;
    return 0;
  }
  queue->tail++;
  queue->arr[queue->tail] = data;
  queue->length++;
  return 0;
}

int de_queue(Queue *queue) {
  if (queue == NULL) {
    return -1;
  }
  if (is_empty(queue)) {
    return -1;
  }
  int res = queue->arr[queue->head];
  queue->head++;
  queue->length--;
  if (is_empty(queue)) {
    queue->head = -1;
    queue->tail = -1;
    return res;
  }
  return res;
}

int get_head(Queue *queue) {
  if (queue == NULL) {
    return -1;
  }
  return is_empty(queue) ? -1 : queue->arr[queue->head];
}

void print(Queue *queue) {
  if (queue == NULL) {
    return;
  }
  printf("head<-[");
  if (is_empty(queue)) {
    printf("]<-tail\n");
    return;
  }
  for (int i = queue->head; i <= queue->tail; i++) {
    if (i == queue->tail) {
      printf("%d", queue->arr[i]);
      break;
    }
    printf("%d ", queue->arr[i]);
  }
  printf("]<-tail\n");
  return;
}