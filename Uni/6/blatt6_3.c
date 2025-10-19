#include <stdio.h>

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
  int a = 174, b = 102, c;
  printf("GGF berechnen : \n");
  printf("Gib mit erste Zahl : \n");
  scanf(" %d", &a);
  printf("Gib mit zweite Zahl : \n");
  scanf(" %d", &b);
  if (a > b) {
    c = ggf(a, b);
  } else {
    c = ggf(b, a);
  }
  printf("%d ist der GGF von %d und %d ", c, a, b);
  return 0;
}
