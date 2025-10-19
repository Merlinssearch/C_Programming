#include <stdio.h>

int minimumRek(int arr[], int size) {
  if (size == 1) {
    return arr[0];
  }

  int min = minimumRek(arr, size - 1);

  if (arr[size - 1] < min) {
    return arr[size - 1];
  } else {
    return min;
  }
}

int minimumIter(int arr[], int arrLength) {
  int min = arr[0];
  for (int i = 1; i < arrLength; i++) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return min;
}

int produktRek(int arr[], int arrLength) {
  if (arrLength == 0) {
    return 1; // Empty array case: product is 1 (neutral element of
              // multiplication)
  }

  int multi = arr[arrLength - 1] * produktRek(arr, arrLength - 1);
  return multi;
}

int produktIter(int arr[], int arrLength) {
  int multi = 1;
  for (int i = 0; i < arrLength; i++) {
    multi *= arr[i];
  }
  return multi;
}

int main() {
  int arr[30] = {42, 12, 89, 35, 67, 23, 91, 3,  78, 55, 6, 14, 99, 40, 27,
                 72, 34, 91, 58, 12, 43, 86, 19, 65, 27, 3, 99, 44, 50, 7};

  printf("minimumRek: %d\n", minimumRek(arr, 30));
  printf("minimumIter: %d\n", minimumIter(arr, 30));
  printf("produktRek: %d\n", produktRek(arr, 30));
  printf("produktIter: %d\n", produktIter(arr, 30));

  return 0;
}
