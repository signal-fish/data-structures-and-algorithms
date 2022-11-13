/**********************************************
 > File Name: insertion_sort.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 11/13/2022
 > Desc:
***********************************************/

#include "insertion_sort.h"
#include <stdio.h>

void insertion_sort(int *arr, int size) {
  for (int i = 1; i < size; i++) {
    int sentry = arr[i];
    int j;
    for (j = i - 1; j >= 0 && arr[j] > sentry; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = sentry;
  }
}