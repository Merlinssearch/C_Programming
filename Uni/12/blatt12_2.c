#include <stdio.h>
int ackermann(int n, int m) {
  if (n == 0 && m >= 0) {
    return m + 1;
  }

  if (m == 0 && n >= 1) {
    return ackermann(n - 1, 1);
  }

  if (n >= 1 && m >= 1) {
    return ackermann(n - 1, ackermann(n, m - 1));
  }
  return 1;
}

int main() {
  int m, n;
  printf("Wenn levi nicht da ist ruf Ackermann");
  printf("Wie viele Ackermann brauchst du ? ");
  printf("Gib M \n");
  scanf("%d", &n);
  printf("Gib n \n");
  scanf("%d", &m);
  n = ackermann(n, m);
  printf("Ackermannzahl : %d ", n);
  return 0;
}
