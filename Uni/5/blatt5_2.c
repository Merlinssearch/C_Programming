#include <stdio.h>

void PrintArray(int arr[], int arraylenght) {
  for (int i = 0; i < arraylenght; i++) {
    printf("arr[%d] = %d \n", i, arr[i]);
  }
  printf("_____________________________________________\n");
}
int searchMax(int arr[], int arrlenght) {
  int max = arr[0];
  for (int i = 0; i < arrlenght; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  FILE *fileptr;
  FILE *newFilePtr;
  fileptr = fopen("test.txt", "r");
  int test[100];

  int i = 0;
  while (fscanf(fileptr, "%d", &test[i]) == 1) {
    i++;
  }
  PrintArray(test, i);
  int max = searchMax(test, i);
  printf("Maximum : %d", max);
  newFilePtr = fopen("ergebniss.txt", "w");
  for (int j = 0; j < i; j++) {
    fprintf(newFilePtr, "%d ", test[j]);
  }
}
