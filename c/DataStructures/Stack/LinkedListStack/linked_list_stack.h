/**********************************************
 > File Name: linked_list_stack.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: This is a header file of linked_list_stack.c
***********************************************/

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct LinkedListStack {
  int length;
  Node *topNode;
} Stack;

#define is_empty(stack) (stack->length == 0)
#define len(stack) (stack->length)

Node *new_node(int);
Stack *init_stack();
void destroy(Stack *);
int push(Stack *, int);
int pop(Stack *);
int get_top(Stack *);
void print(Stack *);