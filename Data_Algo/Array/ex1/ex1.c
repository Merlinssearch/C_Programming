#include <stdatomic.h>
#include <stdio.h>

// BubbleSort
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

int searchMax(int arr[], int arrlenght) {
  int max;
  max = arr[0];
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

void SortIntArrayAsc(int arr[], int arraylenght) {
  int swap = 0;
  int doit = 1;
  do {
    doit = 0;
    for (int i = 0; i < arraylenght - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        swap = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = swap;
        doit = 1;
      }
    }
  } while (doit);
}
void SortIntArrayDesc(int arr[], int arraylenght) {
  int swap = 0;
  int doit = 1;
  do {
    doit = 0;
    for (int i = 0; i < arraylenght - 1; i++) {
      if (arr[i] < arr[i + 1]) {
        swap = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = swap;
        doit = 1;
      }
    }
  } while (doit);
}

void PrintArray(int arr[], int arraylenght) {
  for (int i = 0; i < arraylenght; i++) {
    printf("arr[%d] = %d \n", i, arr[i]);
  }
  printf("_____________________________________________\n");
}

void MergeArray(int arr[], int arr2[], int arraylenght, int arraylenght2,
                int MergeArray[]) {

  for (int i = 0; i < arraylenght + arraylenght2; i++) {
    if (i < arraylenght) {
      MergeArray[i] = arr[i];
    } else {
      MergeArray[i] = arr2[i - arraylenght];
    }
  }
}

// Split Array funtion

// void SplitArry(int ArraytoSplit[], int FirstHalfArray[], int SecondArray[])
// {}
// Kompletter Müll was habe ich mir dabei gedacht ? ?? ??! ?! ?!
void NewSortAlg(int arr[], int arraylenght) {
  // int swap = 0;
  int swap = 0;
  // int doit = 1;
  for (int i = 0; i < arraylenght - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      swap = arr[i + 1];
      arr[i + 1] = arr[i];
      arr[i] = swap;
    } else {
      swap = arr[i + 1];
      arr[i + 1] = arr[arraylenght - i];
      arr[arraylenght - i] = swap;
    }
    PrintArray(arr, arraylenght);
  }
}

int main() {

  int arr[30] = {42, 12, 89, 35, 67, 23, 91, 3,  78, 55, 6, 14, 99, 40, 27,
                 72, 34, 91, 58, 12, 43, 86, 19, 65, 27, 3, 99, 44, 50, 7};
  // int arr2[15] = {72, 34, 91, 58, 12, 43, 86, 19, 65, 27, 3, 99, 44, 50, 7};

  int arraylenght = sizeof(arr) / sizeof(arr[0]);
  // int arraylenght2 = sizeof(arr2) / sizeof(arr2[0]);
  //  int MergedArrayLenght = arraylenght + arraylenght2;
  //  int MergedArray[MergedArrayLenght] = {};
  // NewSortAlg(arr, arraylenght);

  // SortIntArrayAsc(arr, arraylenght);
  // SortIntArrayAsc(arr2, arraylenght);

  // MergeArray(arr, arr2, arraylenght, arraylenght2, MergedArray);

  // printf("Vor der Manipulation: \n");
  // PrintArray(MergedArray, MergedArrayLenght);

  // SortIntArrayDesc(MergedArray, MergedArrayLenght);

  // printf("\nNach der Manipulation: \n");
  // PrintArray(MergedArray, MergedArrayLenght);
  return 0;
}
