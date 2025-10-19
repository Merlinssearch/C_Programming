#include <stdio.h>
int main() {
  int x, n = 10, *y = &n;
  printf("Name : x | Speicher : %p | Wert : %d | Typ : int  \n", (void *)&x, x);
  printf("Name : n | Speicher : %p | Wert : %d | Typ : int  \n", (void *)&n, n);
  printf("Name : y | Speicher : %p | Wert : %p | Typ : int* \n", (void *)&y, y);
  return 0;
}
