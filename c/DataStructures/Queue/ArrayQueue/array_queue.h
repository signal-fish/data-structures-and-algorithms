/**********************************************
 > File Name: array_queue.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: This is a header file of array_queue.c
***********************************************/

typedef struct ArrayQueue {
  int capacity;
  int length;
  int head;
  int tail;
  int *arr;
} Queue;

#define is_empty(queue) (queue->length == 0)
#define is_full(queue) (queue->length == queue->capacity)

Queue *init_queue(int);
void destroy(Queue *);
int en_queue(Queue *, int);
int de_queue(Queue *queue);
int get_head(Queue *);
void print(Queue *);