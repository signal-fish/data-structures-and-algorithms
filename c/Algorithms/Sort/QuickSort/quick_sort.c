/**********************************************
 > File Name: quick_sort.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 11/13/2022
 > Desc:
***********************************************/

#include "quick_sort.h"
#include <stdio.h>

int partition(int *arr, int low, int high) {
  int pivot = arr[high];
  int i, j;
  i = j = low;
  while (i <= high) {
    if (arr[i] > pivot) {
      i++;
    } else {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j++;
    }
  }
  return j - 1;
}

void __quick_sort(int *arr, int low, int high) {
  if (low < high) {
    int p = partition(arr, low, high);
    __quick_sort(arr, low, p - 1);
    __quick_sort(arr, p + 1, high);
  }
}

void quick_sort(int *arr, int size) {
  __quick_sort(arr, 0, size - 1);
}