/**********************************************
 > File Name: linked_list_queue.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: This is a header file of linked_list_queue.c
***********************************************/

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct LinkedListQueue {
  int length;
  Node *head;
  Node *tail;
} Queue;

#define is_empty(queue) (queue->length == 0)
#define len(queue) (queue->length)

Node *new_node(int);
Queue *init_list_queue();
void destroy(Queue *);
int en_queue(Queue *, int);
int de_queue(Queue *);
void print(Queue *);