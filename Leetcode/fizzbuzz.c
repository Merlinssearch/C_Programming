#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **fizzBuzz(int n, int *returnSize) {
  *returnSize = n;
  char **fizzBuzz = (char **)malloc(n * sizeof(char));
  for (int i = 1; i <= n; i++) {
    if (i % 15 == 0) {
      fizzBuzz[i - 1] = (char *)malloc(9 * sizeof(char));
      strcpy(fizzBuzz[i - 1], "FizzBuzz");
    } else if (i % 3 == 0) {
      fizzBuzz[i - 1] = (char *)malloc(5 * sizeof(char));
      strcpy(fizzBuzz[i - 1], "Fizz");
    } else if (i % 5 == 0) {
      fizzBuzz[i - 1] = (char *)malloc(5 * sizeof(char));
      strcpy(fizzBuzz[i - 1], "Buzz");
    } else {
      fizzBuzz[i - 1] = (char *)malloc(2 * sizeof(char));
      sprintf(fizzBuzz[i - 1], "%d", i);
    }
  }
  return fizzBuzz;
}

int main() {
  int n = 15;
  int returnSize;
  char **result = fizzBuzz(n, &returnSize);

  for (int i = 0; i < returnSize; i++) {
    printf("%s\n", result[i]);
    free(result[i]);
  }
  free(result);
  return 0;
}
