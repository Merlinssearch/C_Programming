#include <stdio.h>
int main() {
  int sum = 0;
  int x;
  printf("Gib mir eine Ineger Zahl X , um die Summer aller Teiler zu berechnen "
         ":\n");
  scanf("%d", &x);
  for (int i = 1; i <= x; i++) {
    if (x % i == 0) {
      sum += i;
      printf("%d ist ein Teiler von %d ohne rest  \n", i, x);
    }
  }
  printf("Die Summe aller Teiler ist : %d \n", sum);
  return 0;
}
