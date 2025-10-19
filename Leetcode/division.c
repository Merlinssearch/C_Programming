#include <limits.h>
#include <stdio.h>
int divide(int dividend, int divisor) {
  if (dividend == INT_MIN && (divisor == -1)) {
    return INT_MAX;
  }
  if (dividend == 2147483647 && (divisor == -1)) {
    return -2147483647;
  }
  if (dividend == INT_MIN && divisor == 1) {
    return INT_MIN;
  }
  int new = 0;
  long dividend2 = dividend;
  long divisor2 = divisor;
  int isnegativ1 = 1;
  int isnegativ2 = 1;
  if (dividend2 < 0) {
    dividend2 = dividend2 * (-1);
    isnegativ1 = 0;
  }
  if (divisor2 < 0) {
    divisor2 = divisor2 * (-1);
    isnegativ2 = 0;
  }
  while (1) {
    dividend2 = dividend2 - divisor2;
    if (dividend2 < 0) {
      break;
    }
    new ++;
  }
  if (isnegativ1 == 0 && isnegativ2 == 0) {
    return new;
  }
  if (isnegativ1 == 0 || isnegativ2 == 0) {
    return new * (-1);
  }
  return new;
}
int main() { printf("%d", divide(100, 32)); }
