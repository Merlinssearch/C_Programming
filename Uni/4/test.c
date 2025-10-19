
#include <stdio.h>
int main() {

  int i = 2;
  int total = 0;
  while (i <= 9) {
    total += ++i;
  }
  printf("%d", total);
  return 0;
}
