#include <stdio.h>
// https://www.hft-stuttgart.de/fileadmin/Dateien/Mathematik/Publikationen/Euklidischer_Algorithmus-neu.pdf
int ggf(int bigger, int smaller) {
  int rest = 1;
  do {
    rest = bigger % smaller;
    // printf("rest: %d bigger : %d mod smaller %d \n", rest, bigger, smaller);
    bigger = smaller;
    smaller = rest;
  } while (rest != 0);
  return bigger;
}

int main() {
  int a, b, c;
  printf("KGV berechnen : \n");
  printf("Gib mit erste Zahl : \n");
  scanf(" %d", &a);
  printf("Gib mit zweite Zahl : \n");
  scanf(" %d", &b);
  if (a > b) {
    c = ggf(a, b);
  } else {
    c = ggf(b, a);
  }
  c = (a * b) / c;
  printf("KGV von %d und %d ist : %d", a, b, c);
}
