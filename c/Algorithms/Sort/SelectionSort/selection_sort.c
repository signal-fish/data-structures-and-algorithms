/**********************************************
 > File Name: selection_sort.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 11/12/2022
 > Desc:
***********************************************/

#include "selection_sort.h"
#include <stdio.h>

void selection_sort(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (i != min) {
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}