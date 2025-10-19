#include <stdio.h>
int main() {
  float test1, test2;
  test1 = 0.1 + 0.2;
  test2 = 0.1 + 0.3;
  printf("%.20f \n", test1);
  printf("%.20f \n", test2);
  // da zahlen 1/n^2 dargestell werden können aus diesen kombination nicht alle
  // gleitkommazahlen genau dargestellt werden versuchen immer mit integer zu
  // rechen
  printf("----------------------------------------------------\n");
  printf("Harmoische Reihe für float \n");
  float sum = 1;
  for (int i = 2; i <= 10000; i++) {
    sum += 1.0 / i;
  }
  printf("%.20f \n", sum);
  sum = 1;
  for (int i = 2; i <= 100000; i++) {
    sum += 1.0 / i;
  }
  printf("%.20f\n", sum);
  sum = 1;
  for (int i = 2; i <= 1000000; i++) {
    sum += 1.0 / i;
  }
  printf("%.20f\n", sum);
  printf("----------------------------------------------------\n");
  printf("Harmoische Reihe für double \n");
  double sum2 = 1;
  for (int i = 2; i <= 10000; i++) {
    sum2 += 1.0 / i;
  }
  printf("%.20f\n", sum2);
  sum2 = 1;
  for (int i = 2; i <= 100000; i++) {
    sum2 += 1.0 / i;
  }
  printf("%.20f\n", sum2);
  sum2 = 1;
  for (int i = 2; i <= 1000000; i++) {
    sum2 += 1.0 / i;
  }
  printf("%.20f\n", sum2);
}
/*n = 10.000 → 9, 7876060360443822
• n = 100.000 → 12, 0901461298634279
• n = 1.000.000 → 14, 3927267228657236 */
