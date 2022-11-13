/**********************************************
 > File Name: bubble_sort.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 11/12/2022
 > Desc:
***********************************************/

#include "bubble_sort.h"
#include <stdio.h>

void bubble_sort(int *arr, int size) {
  int flag = 1;
  for (int i = 0; i < size && flag; i++) {
    flag = 0;
    for (int j = size - 2; j >= i; j--) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = 1;
      }
    }
  }
}