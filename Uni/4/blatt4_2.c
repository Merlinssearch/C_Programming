#include <stdbool.h>
#include <stdio.h>
int main() {

  int x = 1;
  int y = 2;
  bool z = true;
  // y wird eingelsen dann + 1 dies mal 5 und dann + x
  // y + 1 = 3 * 5 = 15 + 1 = 16
  // was aber passiert ist y * 5 + 1 , weil y wird eingelesen , dann wird y ++
  // gerechnet d.h y = 1 * 5 * 10 + x = 1 = 11
  printf("%d \n", y++ * 5 + x);
  // 1 * 5 = 5 | 5 % ++y | y+ 1 = 3 | 5 % 3 = 2
  y = 2;
  printf("%d\n", x * 5 % ++y);
  // es kamm 1 raus -.- , weil vergessen hab 2 zu resten
  //
  printf("%d\n", x++ - y--);
  y = 2;
  x = 1;
  if (x * 5 < y || z && x > y) {
    printf("true \n");
  } else {
    printf("false \n");
  }
  x = 1;
  y = 2;
  // zuerst y + 1 = 2 + 1 = y = 3 = x = 3 = 3
  printf("%d\n", x = y = y + 1);
  return 0;
}
