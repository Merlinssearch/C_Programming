#include <stdio.h>
int main() {

  int n;
  printf("Gib mir eine Int um den Rest einer Division durch 57 auszugeben \n");
  scanf("%d", &n);
  n %= 57;
  if (n == 0) {
    printf("Scherzkeks \n");
  } else {
    printf("Der Rest ist %d", n);
  }
  return 0;
}
