

#include <stdio.h>

int firstdigit(int Zahl) {
  while (Zahl >= 10) {
    Zahl /= 10;
  }
  return Zahl;
}
int main() {

  int a, b;
  printf("Prüfen ob die letzte Ziffer 2er Zahlen gleich sind: \n");
  printf("---------------------------------------------------------------------"
         " \n");
  printf("Gib mir eine Int Zahl : a \n");
  scanf("%d", &a);
  printf("Gib mir eine Int Zahl : b \n");
  scanf("%d", &b);
  printf("---------------------------------------------------------------------"
         " \n");

  if (a % 10 == b % 10) {
    printf("die letzten Ziffern a : %d| b: %d | sind gleich \n", a % 10,
           b % 10);
  } else {
    printf("die letzten Ziffern a : %d| b: %d | sind nicht gleich \n", a % 10,
           b % 10);
  }
  printf("---------------------------------------------------------------------"
         " \n");
  printf("Prüfen ob die erste Ziffer 2er Zahlen gleich sind: \n");
  printf("---------------------------------------------------------------------"
         " \n");
  printf("Gib mir eine Int Zahl : a \n");
  scanf("%d", &a);
  printf("Gib mir eine Int Zahl : b \n");
  scanf("%d", &b);
  printf("---------------------------------------------------------------------"
         " \n");
  a = firstdigit(a);
  b = firstdigit(b);
  printf("Letzte Ziffer a : %d | Letzte Ziffer b : %d \n", a, b);
  if (a == b) {
    printf("Die erste Ziffer sind gleich\n");
  } else {
    printf("Die erste Ziffer sind nicht gleich \n");
  }
  return 0;
}
