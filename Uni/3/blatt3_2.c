/*
a) . . . alle Zahlen von 100 bis 200 auf der Konsole ausgibt.
b) . . . nur alle geraden Zahlen zwischen 111 und 222 ausgibt.
c) . . . alle durch 3 teilbaren Zahlen zwischen 333 und 222 absteigend ausgibt.
d) . . . die Summe aller durch 3 teilbaren ganzen Zahlen zwischen 1 und 1000
aufaddiert. e) . . . eine Ganzzahl n einliest und true ausgibt, wenn die Ziffer
7 in der Dezimaldarstellung von n vorkommt, sonst false. f) . . . die Anzahl der
Vorkommen der Ziffer 7 in der Dezimaldarstellung von n (s.o.) ausgibt.
*/

#include <stdio.h>
int main() {
  long temp, count, zahl;
  printf("Alle Zahlen von 100-200 \n");
  for (int i = 100; i <= 200; i++) {
    printf("%d \n", i);
  }
  printf("--------------------------------------\n");
  printf("Alle geraden Zahlen von 111 - 222 \n");
  for (int i = 111; i <= 222; i++) {
    if (i % 2 == 0) {
      printf("%d \n", i);
    }
  }
  printf("--------------------------------------\n");
  printf("Alle Zahlen von 333 - 222 die durch 3 ohne rest teilbar sind \n");
  for (int i = 333; i >= 222; i--) {
    if (i % 3) {
      printf("%d\n", i);
    }
  }
  printf("--------------------------------------\n");
  for (int i = 1; i <= 1000; i++) {
    if (i % 3) {
      temp += i;
    }
  }
  printf("Summer aller durch 3 Teilbaren Zahlen von 1 - 1000 = %ld \n", temp);
  printf("--------------------------------------\n");
  scanf("%ld", &temp);
  zahl = temp;
  while (temp > 0) {
    if (temp % 10 == 7) {
      count++;
    }
    temp /= 10;
  }
  printf("Die Zahl : %ld | Hat : %ld , Siebenen ! \n", zahl, count);
  return 0;
}
