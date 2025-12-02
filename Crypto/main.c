#include <stdio.h>

// Extended Euclidean Algorithmus

// Recursions beispiel
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b % a, a, &x1, &y1);

  *x = y1 - (b / a) * x1;
  *y = x1;

  return gcd;
}

int gcdExtendedIterative(int a, int b, int *x, int *y) {
  int x0 = 1, y0 = 0; // Startwerte für x, y
  int x1 = 0, y1 = 1; // Startwerte für x, y in Iteration
  int q, r;

  printf("%4s %4s %4s | %5s %5s | %5s %5s\n", "a", "b", "q", "x0", "y0", "x1",
         "y1");
  printf("-----------------------------------------------\n");
  printf("%4d %4d %4s | %5d %5d | %5d %5d\n", a, b, "-", x0, y0, x1, y1);

  while (b != 0) {
    q = a / b;
    r = a % b;

    printf("%4d %4d %4d | %5d %5d | %5d %5d  -> ", a, b, q, x0, y0, x1, y1);

    a = b;
    b = r;

    int xTemp = x1;
    int yTemp = y1;

    x1 = x0 - q * x1;
    y1 = y0 - q * y1;

    x0 = xTemp;
    y0 = yTemp;

    printf("x1 = %d, y1 = %d\n", x1, y1);
  }

  *x = x0;
  *y = y0;
  return a;
}

int main() {
  int a = 47, b = 8;
  int x, y;
  int g = gcdExtendedIterative(a, b, &x, &y);
  printf("\nResult: gcd = %d, x = %d, y = %d\n", g, x, y);
  printf("Verification: %d*%d + %d*%d = %d\n", a, x, b, y, a * x + b * y);
  return 0;
}
