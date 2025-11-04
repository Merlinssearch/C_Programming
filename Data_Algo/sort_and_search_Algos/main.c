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
  int right = arr_Size - 1;
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

void bubbleSort_desc_for_intArray(int arr[], int arr_Size) {
  bool swaped = false;
  int temp;
  do {
    for (int i = 0; i < arr_Size - 1; i++) {
      if (arr[i] <= arr[i + 1]) {
        temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;
        swaped = true;
      }
    }
  } while (swaped);
}

int int main(int argc, char *argv[]) { return 0; }
