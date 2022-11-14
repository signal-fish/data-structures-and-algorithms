
/**********************************************
 > File Name: circular_queue.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 11/14/2022
 > Desc: Implement queue with array
***********************************************/

#include "circular_queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *init_circular_queue(int cap) {
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
  if (queue == NULL) {
    return;
  }
  free(queue->arr);
  queue->arr = NULL;
  queue->capacity = 0;
  queue->length = 0;
  queue->head = -1;
  queue->tail = -1;
  free(queue);
  queue = NULL;
  return;
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
    queue->length++;
    queue->arr[queue->tail] = data;
    return 0;
  }
  queue->tail = (queue->tail + 1) % queue->capacity;
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
  queue->length--;
  if (is_empty(queue)) {
    queue->head = -1;
    queue->tail = -1;
    return res;
  }
  queue->head = (queue->head + 1) % queue->capacity;
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
  if (is_empty(queue)) {
    printf("head->[]<-tail\n");
    return;
  }
  printf("head->[");
  for (int i = queue->head; i <= queue->tail; i++) {
    if (i == queue->tail) {
      printf("%d]<-tail\n", queue->arr[i]);
      return;
    }
    printf("%d ", queue->arr[i]);
  }
}