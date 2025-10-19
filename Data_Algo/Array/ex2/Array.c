#include <stdio.h>
int searchMin(int arr[], int arrlenght) {
  int min;
  min = arr[0];
  for (int i = 0; i < arrlenght; i++) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return min;
}

int max(int arr[], int arrlenght) {
  int max = arr[0];
  for (int i = 0; i < arrlenght; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

int sumArray(int arr[], int arrlenght) {
  int sum = 0;
  for (int i = 0; i < arrlenght; i++) {
    sum = sum + arr[i];
  }
  return sum;
}

int main() {
  int arr[15] = {42, 12, 89, 35, 67, 23, 91, 3, 78, 55, 6, 14, 99, 40, 27};
  int arrlenght = sizeof(arr) / sizeof(arr[0]);
  int min2 = searchMin(arr, arrlenght);
  int max2 = max(arr, arrlenght);
  int sum2 = sumArray(arr, arrlenght);

  printf("Min in array : %d \n", min2);
  printf("Max in array : %d \n", max2);
  printf("Sum of array : %d", sum2);

  return 1;
}
