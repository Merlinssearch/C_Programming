#include <stdio.h>

/////////////////////////////////////////////////////////

int summenFunktion(int n) {
  if (n == 0) {
    return 0;
  }
  return summenFunktion(n - 1) + n;
}

/////////////////////////////////////////////////////////

int fak(int n) {
  if (n == 0) {
    return 1;
  }
  return fak(n - 1) * n;
}

/////////////////////////////////////////////////////////

int fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
  return fib(n - 2) + fib(n - 1);
}

/////////////////////////////////////////////////////////
int main() {
  int n;
  printf("------------------------------------------\n");
  printf("Gib n für Summenfunktion\n");
  scanf("%d", &n);
  n = summenFunktion(n);
  printf("Die Summe ist : %d \n", n);
  printf("------------------------------------------\n");
  printf("Gib n für Fakulteatfunktion\n");
  scanf("%d", &n);
  n = fak(n);
  printf("Die Fak ist : %d \n", n);
  printf("------------------------------------------\n");

  printf("Gib n für fib\n");
  scanf("%d", &n);
  n = fib(n);
  printf("Die  fib ist : %d \n", n);
  printf("------------------------------------------\n");

  return 0;
}
