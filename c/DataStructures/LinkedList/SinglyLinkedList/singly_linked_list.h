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

List *new_singly_linked_list();
int destroy(List *);
int append(List *, int);
int get_item(List *, int);
int prepend(List *, int);
int insert(List *, int, int);
void print(List *);
int update(List *, int, int);
int delete_node(List *, int);
int clear(List *);
int count(List *, int);
void asc_sort(List *);