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