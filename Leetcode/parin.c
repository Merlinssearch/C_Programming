#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool isValid(char *s) {
  int stackcounter = -1;
  char stack[strlen(s)];

  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      stackcounter++;
      stack[stackcounter] = s[i];
    } else if (s[i] == ')' && stack[stackcounter] == '(') {
      stackcounter--;
    } else if (s[i] == ']' && stack[stackcounter] == '[') {
      stackcounter--;
    } else if (s[i] == '}' && stack[stackcounter] == '{') {
      stackcounter--;
    } else {
      return false;
    }
  }
  if (stackcounter != -1)
    return false;
  return true;
}
int main() {
  // Testfälle
  char *testCases[] = {
      "()",     // True
      "()[]{}", // True
      "(]",     // False
      "([)]",   // False
      "{[]}",   // True
      "",       // True (leerer String ist gültig)
      "((((",   // False
      "([{}])", // True
      "({[})"   // False
  };

  for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
    printf("Testfall %d: %s\n", i + 1, testCases[i]);
    if (isValid(testCases[i])) {
      printf("Ergebnis: Gültig\n");
    } else {
      printf("Ergebnis: Ungültig\n");
    }
  }

  return 0;
}
