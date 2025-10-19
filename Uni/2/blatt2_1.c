#include <stdio.h>
int main() {

  int Umfang, Fleche, a, b;

  printf("---------------------------------------------\n");
  printf("Umfang und Flächeninhalt berechner 3000 \n");
  printf("---------------------------------------------\n");
  printf("Gib mir ein Int für Seite A und drücke enter\n");
  scanf("%d", &a);
  printf("Gib mir ein Int für Seite B und drücke enter\n");
  scanf("%d", &b);
  printf("---------------------------------------------\n");
  printf("Umfang : %d | Flächeninhalt : %d\n", 2 * (a + b), a * b);
  printf("---------------------------------------------\n");

  return 0;
}

