/**********************************************
 > File Name: shell_sort.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 11/13/2022
 > Desc:
***********************************************/

#include "shell_sort.h"
#include <stdio.h>

void shell_sort(int *arr, int size) {
  for (int gap = size / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < size; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}