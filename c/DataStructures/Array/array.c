/**********************************************
 > File Name: array.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: Implement array with struct and
   pointer
***********************************************/

#include "array.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize an array
Array *init_array(int cap) {
  if (cap < 0) {
    return NULL;
  }
  Array *array = NULL;
  array = (Array *)malloc(sizeof(array));
  if (array == NULL) {
    return NULL;
  }
  array->capacity = cap;
  array->size = 0;
  array->arr = (int *)malloc(cap * sizeof(int));
  if (array->arr == NULL) {
    free(array);
    array = NULL;
    return NULL;
  }
  return array;
}

// destroy an array
void destroy(Array *array) {
  if (array == NULL || array->arr == NULL) {
    return;
  }
  array->capacity = 0;
  array->size = 0;
  free(array->arr);
  array->arr = NULL;
  free(array);
  array = NULL;
  return;
}

// print an array
void print(Array *array) {
  if (array == NULL || array->arr == NULL) {
    return;
  }
  if (is_empty(array)) {
    printf("[]\n");
    return;
  } else {
    printf("[");
    for (int i = 0; i < array->size; i++) {
      if (i != array->size - 1) {
        printf("%d, ", (array->arr[i]));
      } else {
        printf("%d]\n", array->arr[i]);
      }
    }
  }
  return;
}

// get an element of an array at the specified position
int get(Array *array, int idx) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  if (idx < 0 || idx >= array->size) {
    return -1;
  }
  return array->arr[idx];
}

// append an element to the end of an array
int append(Array *array, int elem) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  if (is_full(array)) {
    return -1;
  }
  if (array->size < array->capacity) {
    array->arr[array->size] = elem;
    array->size++;
    return 0;
  }
  return -1;
}

// Remove an element at the end of the array
int pop(Array *array) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  if (array->size > 0) {
    int res = array->arr[array->size - 1];
    array->arr[array->size - 1] = 0;
    array->size--;
    return res;
  } else {
    return -1;
  }
}

// Add an element at the specified position
int insert(Array *array, int idx, int elem) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  if (idx < 0 || idx > array->capacity || is_full(array)) {
    return -1;
  }
  if (idx >= array->size) {
    array->arr[idx] = elem;
    array->size = idx + 1;
  } else {
    for (int i = array->size; i > idx; i--) {
      array->arr[i] = array->arr[i - 1];
    }
    array->arr[idx] = elem;
    array->size++;
  }
  return 0;
}

// Find the number of specified element in the array
int count(Array *array, int elem) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  int count = 0;
  if (array->size == 0) {
    return count;
  } else {
    for (int i = 0; i < array->size; i++) {
      if (array->arr[i] == elem) {
        count++;
      }
    }
    return count;
  }
}

// Find the first index of given element of at the array
int array_index(Array *array, int elem) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  for (int i = 0; i < array->size; i++) {
    if (array->arr[i] == elem) {
      return i;
    }
  }
  return -1;
}

// Find the last index of given element at the array
int array_last_index(Array *array, int elem) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  for (int i = array->size - 1; i >= 0; i--) {
    if (array->arr[i] == elem) {
      return i;
    }
  }
  return -1;
}

// Update the element of the array at the specified position
int update(Array *array, int idx, int elem) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  if (array->size == 0 || idx < 0 || idx > array->size) {
    return -1;
  } else {
    array->arr[idx] = elem;
    return 0;
  }
}

// Reverse the order of the array
Array *reverse(Array *array) {
  if (array == NULL || array->arr == NULL) {
    return NULL;
  }
  if (array->size < 2) {
    return array;
  } else {
    int mid = array->size / 2;
    for (int i = 0; i < mid; i++) {
      int temp = array->arr[i];
      array->arr[i] = array->arr[array->size - 1 - i];
      array->arr[array->size - 1 - i] = temp;
    }
    return array;
  }
}

// Sort the array in ascending order
Array *asc_sort(Array *array) {
  for (int i = 1; i < array->size; i++) {
    int sentry = array->arr[i];
    int j;
    for (j = i - 1; j >= 0 && array->arr[j] > sentry; j--) {
      array->arr[j + 1] = array->arr[j];
    }
    array->arr[j + 1] = sentry;
  }
  return array;
}

// Remove an element at the specified position
int remove_item(Array *array, int idx) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  if (idx < 0 || idx > array->size || is_empty(array)) {
    return -1;
  } else {
    int res = array->arr[idx];
    for (int i = idx; i < array->size - 1; i++) {
      array->arr[i] = array->arr[i + 1];
    }
    array->size--;
    return res;
  }
}

// Remove all the elements from the array
int clear(Array *array) {
  if (array == NULL || array->arr == NULL) {
    return -1;
  }
  for (int i = 0; i < array->size; i++) {
    *(array->arr + i) = 0;
  }
  array->size = 0;
  return 0;
}