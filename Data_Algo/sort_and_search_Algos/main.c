#include "stdbool.h"
#include "stdio.h"

int getIndex_LinearSearch_from_IntArray(int arr[], int arr_Size, int target) {
  for (int i = 0; i < arr_Size; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int getIndex_binarySearch_from_AscIntArray(int arr[], int arr_Size,
                                           int target) {
  int left = 0;
  int right = arr_Size;
  int middle;
  if (arr[0] == target) {
    return 0;
  }
  do {
    middle = left + (right - left) / 2;
    if (!(arr[middle] > target)) {
      right = middle;
    } else {
      left = middle;
    }
  } while (left < right);
  return -1;
}

int main() { return 0; }
