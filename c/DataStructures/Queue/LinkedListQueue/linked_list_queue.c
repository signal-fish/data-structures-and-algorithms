/**********************************************
 > File Name: linked_list_queue.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: Implement stack with array
***********************************************/

#include "linked_list_queue.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    return NULL;
  }
  node->val = data;
  node->next = NULL;
  return node;
}

Queue *init_list_queue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue == NULL) {
    return NULL;
  }
  queue->length = 0;
  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

void destroy(Queue *queue) {
  if (queue == NULL) {
    return;
  }
  if (is_empty(queue)) {
    free(queue);
    queue = NULL;
    return;
  }
  Node *cur = queue->tail;
  while (cur != NULL) {
    Node *temp = cur;
    cur = cur->next;
    free(temp);
    temp = NULL;
  }
  free(queue);
  queue = NULL;
  return;
}

int en_queue(Queue *queue, int data) {
  Node *n_node = new_node(data);
  if (n_node == NULL) {
    return -1;
  }
  if (is_empty(queue)) {
    queue->head = n_node;
    queue->tail = n_node;
    queue->length++;
    return 0;
  }
  Node *temp = queue->tail;
  queue->tail = n_node;
  n_node->next = temp;
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
  int res = queue->head->val;
  if (len(queue) == 1) {
    queue->length--;
    free(queue->head);
    queue->head = NULL;
    queue->tail = NULL;
    return res;
  }
  Node *cur = queue->tail;
  while (cur->next != queue->head) {
    cur = cur->next;
  }
  queue->length--;
  free(queue->head);
  queue->head = cur;
  return res;
}

void print(Queue *queue) {
  if (queue == NULL) {
    return;
  }
  if (is_empty(queue)) {
    printf("head->[]<-tail\n");
    return;
  }
  int arr[len(queue)];
  Node *cur = queue->tail;
  for (int i = 0; i < len(queue); i++) {
    arr[i] = cur->val;
    cur = cur->next;
  }
  printf("head->[");
  for (int i = len(queue) - 1; i >= 0; i--) {
    if (i == 0) {
      printf("%d]<-tail\n", arr[i]);
      return;
    }
    printf("%d<-", arr[i]);
  }
}