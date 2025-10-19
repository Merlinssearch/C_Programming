#include <math.h>
#include <stdio.h>
int main() {
  double sumofpi = 0;
  double pointNumber = -1.0;
  for (int i = 1; i <= 1000001; i = i + 2) {
    pointNumber = pointNumber * (-1);
    sumofpi += pointNumber / i;
  }
  printf("%f \n", sumofpi * 4.0);
  double divider = 1;
  double num = 0;
  double sum = 1;
  int count = 2;
  for (int i = 0; i <= 100000; i++) {
    num += 2;
    sum *= num / divider;
    divider += 2;
    sum *= num / divider;
  }
  printf("%f \n", sum * 2);
  return 0;
}
