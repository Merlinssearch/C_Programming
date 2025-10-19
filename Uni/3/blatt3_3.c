#include <stdio.h>
int main() {
  long double temp;
  for (long double i = 1; i <= 100; i++) {
    temp = i * i * i - 73 * i * i + 1655 * i - 11951;
    if (temp == 0) {
      printf("%Lf | %Lf  \n", temp, i);
    }
  }
  return 0;
}
