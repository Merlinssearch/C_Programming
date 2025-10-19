#include <stdio.h>
int rund(int n) {

  if (n % 10 >= 5) {
    n = n + (10 - (n % 10));
  } else {
    n = n - (n % 10);
  }
  return n;
}

int main() {
  int input = 0;
  int sum = 0;
  printf("Gib 3 Int die gerundet auf 10 summiert \n");
  scanf(" %d", &input);
  sum += rund(input);
  scanf(" %d", &input);
  sum += rund(input);
  scanf(" %d", &input);
  sum += rund(input);
  printf("Die summe ist %d\n", sum);
}
