#include "stdbool.h"
#include <stdio.h>

bool mauern(int klein, int groß, int ziel) {
  bool itworks = false;
  int großmax = 0;
  if (groß != 0) {
    großmax = ziel / 5;
  }
  printf("großmax : %d \n", großmax);
  int maxklein = ziel - (großmax * 5);
  if (maxklein <= klein && großmax <= groß) {
    itworks = true;
  } else {
    itworks = false;
  }
  return itworks;
}

int main() {
  printf("%d \n", mauern(9, 0, 8));
  printf("%d \n", mauern(3, 1, 9));
  printf("%d \n", mauern(3, 2, 10));
  return 0;
}
