#include <stdio.h>
#include <stdlib.h>
int main() {
  int arraysize = 20;
  int *pIntArray = malloc(sizeof(int) * arraysize);
  if (pIntArray == NULL) {
    printf("Malloc failed");
    return 1;
  }
  for (int i = 0; i < arraysize; i++) {
    pIntArray[i] = i;
  }
  for (int i = 0; i < arraysize; i++) {
    printf("%d \n", pIntArray[i]);
  }
  free(pIntArray);
  for (int i = 0; i < arraysize; i++) {
    printf("%d \n", pIntArray[i]);
  }
  return 0;
}
