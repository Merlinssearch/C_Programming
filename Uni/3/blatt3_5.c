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
  int sum = 0;
  printf("Gibt mir eine Integer Zahl woraus die Quersumme berechnet wird : \n");
  scanf("%d", &input);
  while (input > 0) {
    sum += input % 10;
    input /= 10;
  }
  printf("Die Quersumme ist : %d \n", sum);
  printf("Gibt mir eine Integer Zahl woraus die Iterierte-Quersumme berechnet "
         "wird : \n");
  scanf("%d", &input);
  while (input > 10) {
    input = querSumme(input);
  }
  printf("Die Quersumme ist : %d \n", input);

  return 0;
}
