#include <stdio.h>

int main() {
  int a, b;
  int result = 0;
  // Todo nicht fertig gemacht
  printf("Gibt mir ein Int für A: \n");
  scanf("%d", &a);
  printf("Gibt mir ein Int für B: \n");
  scanf("%d", &b);
  // Dies soll Integer-Division a / b umsetzen:
  // muss kleiner gleich sein sonst fehlt immer ein Schritt
  while (a - b >= 0) {
    result++;
    a = a - b;
  }
  printf("%d\n", result);
  return 0;
}
