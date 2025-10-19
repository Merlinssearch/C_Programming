#include <stdio.h>
int querSumme(int zahl) {
  int sum = 0;
  while (zahl > 0) {
    sum += zahl % 10;
    zahl /= 10;
  }
  zahl = sum;
  return zahl;
}
int main() {
  int input;
  printf("Gibt mir eine Integer Zahl woraus die Iterierte-Quersumme berechnet "
         "wird : \n");
  scanf("%d", &input);
  while (input > 10) {
    input = querSumme(input);
  }
  printf("Die Quersumme ist : %d \n", input);
  return 0;
}
