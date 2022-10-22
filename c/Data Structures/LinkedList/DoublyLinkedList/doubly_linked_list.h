/**********************************************
 > File Name: doubly_linked_list.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/22/2022
 > Desc: This is a header file of
   doubly_linked_list.c
***********************************************/

typedef struct node {
  int val;
  struct node *prev;
  struct node *next;
} Node;

typedef struct doubly_linked_list {
  int length;
  Node *head;
} List;

#define is_empty(list) (list->length == 0)
#define len(list) (list->length)