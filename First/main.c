#include <stdio.h>
int main(int argc, const char *argv[]) {
  printf("Enter a Intager Number greater then 0 \n");
  int PalindromtoTest;
  scanf("%d", &PalindromtoTest);
  int CompareInt = PalindromtoTest;
  int reminder, reverse = 0, mod = 10;
  while (PalindromtoTest > 0) {
    reminder = PalindromtoTest % mod;

    reverse = (reverse * 10 + reminder);

    printf("reminder : %d,mod: %d, Reverse: %d \n", reminder, mod, reverse);
    PalindromtoTest = PalindromtoTest / 10;
  }
  if (reverse == CompareInt) {
    printf("The Number: %d , is a Palindrom", CompareInt);
  } else {
    printf("The Number %d , is not a Palindrom", CompareInt);
  }
  return 0;
}
