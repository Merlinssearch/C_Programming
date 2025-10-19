#include <climits>
#include <stdio.h>
int isPaldindrom(int toTest) {
  int Reverse = 0;
  int toTets;
  do {
    Reverse *= 10;

    Reverse += toTest % 10;

    toTest /= 10;
  } while (toTest > 0);
  return Reverse;
}

int main() {
  int toTest;
  printf("Gib Zahl : \n");
  scanf("%d", &toTest);
  int Reverse = isPaldindrom(toTest);
  printf("toTest : %d | Reverse : %d", toTest, Reverse);
  return 0;
}
