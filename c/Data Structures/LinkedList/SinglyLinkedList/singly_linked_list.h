/**********************************************
 > File Name: singly_linked_list.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/18/2022
 > Desc: This is a header file of
   singly_linked_list.c
***********************************************/

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct SinglyLinkedList {
  Node *head;
  int length;
} List;

#define is_empty(list) (list->length == 0)
#define len(list) (list->length)