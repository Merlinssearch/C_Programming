#include <stdio.h>
int main() {
  char firstword[] = "LongestPreaFix";
  char secondword[] = "LongestPreFix";
  int firstwordLenght = (sizeof(firstword) / sizeof(firstword[0])) - 1;
  int secondwordLenght = (sizeof(secondword) / sizeof(secondword[0])) - 1;
  int sizeofArray, sizeOfPreFix = 0;
  // Max Size Needed of CharArray
  if (firstwordLenght > secondwordLenght ||
      firstwordLenght == secondwordLenght) {
    sizeofArray = firstwordLenght;
  } else if (firstwordLenght < secondwordLenght) {
    sizeofArray = secondwordLenght;
  }
  printf("sizeofArray : %d \n", sizeofArray);
  char PreFixSum[sizeofArray] = {};
  // Check every Char and break if diffrent
  for (size_t i = 0; i <= sizeofArray; i++) {
    if (firstword[i] == secondword[i]) {
      PreFixSum[i] = firstword[i];
      // printf("%c ", firstword[i]);
    } else {

      break;
    }
  }
  printf("%s \n", PreFixSum);
  return 0;
}
