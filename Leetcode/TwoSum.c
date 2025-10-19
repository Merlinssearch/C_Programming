

#include <stdio.h>
int main() {
  int intArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arraylenght = sizeof(intArray) / sizeof(intArray[0]);
  int sum;
  printf("Gib zahl : \n");
  scanf("%d", &sum);
  for (int i = 0; i <= arraylenght; i++) {
    for (int j = 0; i <= arraylenght; i++) {
      if (intArray[i] + intArray[j] == sum) {
        printf("%d , %d", i + 1, j + 1);
      }
    }
  }
}
