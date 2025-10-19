#include <stdio.h>
int main() {

  FILE *fileptr;
  fileptr = fopen("new.txt", "r");
  int a = 0, e = 0, i = 0, o = 0, u = 0;
  char character;
  int lenght = 0;
  while ((character = fgetc(fileptr)) != EOF) {
    lenght++;
    if (character == 'a' | character == 'A') {
      a++;
    }
    if (character == 'e' | character == 'E') {
      e++;
    }
    if (character == 'i' | character == 'I') {
      i++;
    }
    if (character == 'o' | character == 'O') {
      o++;
    }
    if (character == 'u' | character == 'U') {
      u++;
    }
  }
  printf("a = %d |e = %d |i = %d |o = %d |u = %d | \n Fulllenght = % d ", a, e,
         i, o, u, lenght);
  return 0;
}
