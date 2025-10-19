#include <stdio.h>
#include <stdlib.h>
void sortIntArray(int array[], int arraylenght) {
  int doit = 1;
  int swap = 0;
  do {
    doit = 0;
    for (int i = 0; i < arraylenght - 1; i++) {
      if (array[i] < array[i + 1]) {
        swap = array[i];
        array[i] = array[i + 1];
        array[i + 1] = swap;
        doit = 1;
      }
    }
  } while (doit);
}

int main() {
  int version;
  printf("Version 1 : soll in einer Version bei Eingabe einer negativen Zahl "
         "sofort abgebrochen werden. \n");
  printf("Version 2 : soll in einer anderen Version negative Zahlen ignoriert "
         "werden \n");
  printf("Für Version 1 Tippe 1 | Für Version 2 Tippe 2 \n");
  scanf("%d", &version);
  int intArray[10];
  int arraylenght = sizeof(intArray) / sizeof(intArray[0]);
  printf("Gebe mir 10 Zahlen \n");
  for (int i = 0; i <= 9; i++) {
    printf("%d te Zahl : \n", i + 1);
    do {
      scanf("%d", &intArray[i]);
      if (intArray[i] < 0 && version == 1) {
        printf("Ein Fehler ist aufgetreten ! Keine Negativen Zahlen -.- ! ");
        exit(1);
      }
      if (intArray[i] < 0) {
        printf("Diese Eingabe wird irgnoriert weil deine Zahl kleiner als 0 "
               "ist \n");
      }
      break;
    } while (intArray > 0);
  }
  sortIntArray(intArray, arraylenght);
  printf("%d \n", intArray[0]);
  return 0;
}
