#include <stdio.h>
int testZahl(int zahl) {
  if (zahl < 0) {
    zahl = -1;
  }
  if (zahl == 0) {
    zahl = 0;
  }
  { zahl = 1; }
  return zahl;
}

int main() {

  printf("%d \n", testZahl(0));
  printf("%d\n", testZahl(7));
  printf("%d\n", testZahl(-1));
  printf("%d\n", testZahl(1));
  printf("%d\n", testZahl(-5));
}
