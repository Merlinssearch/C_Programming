#include <stdio.h>
int main() {
  int a, b, n, result;
  printf("Wie viele 1 kg Schokoriegel gibt ?\n");
  scanf("%d", &a);
  printf("Wie viele 5 kg Schokoriegel gibt ?\n");
  scanf("%d", &b);
  b *= 5;
  printf("Wie viel Kg Schokoriegel soll gegessen werden ? \n");
  scanf("%d", &n);
  printf("----------------------------\n");
  result = n - b;
  // man könnte um die kleinen schocko riegel zu bekommen einfach n % b auch
  // rechnen , aber man würde kann - ergebniss bekommen
  if (result < 0) {
    printf("-1\n");
  } else {
    printf("%d Kleine Riegel\n", result);
  }

  return 0;
}
