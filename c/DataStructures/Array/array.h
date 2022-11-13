/**********************************************
 > File Name: array.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: This is a header file of array.c
***********************************************/

typedef struct _array {
  int capacity;
  int size;
  int *arr;
} Array;

#define is_empty(array) (array->size == 0)
#define is_full(array) (array->size == array->capacity)

Array *init_array(int);
void destroy(Array *);
void print(Array *);
int get(Array *, int);
int append(Array *, int);
int pop(Array *);
int insert(Array *, int, int);
int count(Array *, int);
int array_index(Array *, int);
int array_last_index(Array *, int);
int update(Array *, int, int);
Array *reverse(Array *);
Array *asc_sort(Array *);
int remove_item(Array *, int);
int clear(Array *);