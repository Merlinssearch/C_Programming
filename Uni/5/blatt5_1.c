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
int main() {
  int Min;
  int intArray[10];
  int arraylenght = sizeof(intArray) / sizeof(intArray[0]);
  printf("Gebe mir 10 Positive Int Zahlen \n");
  for (int i = 0; i <= 9; i++) {
    do {
      printf("%d te Zahl : \n", i + 1);
      scanf("%d", &intArray[i]);
      if (intArray[i] < 0) {
        printf("Diese Eingabe wird irgnoriert weil deine Zahl kleiner als 0 "
               "ist \n");
      }
    } while (intArray[i] < 0);
  }
  Min = searchMin(intArray, arraylenght);
  printf("Die kleinste Zahl ist : %d \n", Min);
  return 0;
}
