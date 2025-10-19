#include <stdio.h>
int main() {
  int signedNumber = 1;
  int add = 1;
  unsigned int unsignedNumber = 1;
  int scanedNumber = 1;
  long long longNumber = 1;
  long long unsigned longUnsigendNumber = 1;
  printf("Gib ein zahl N um N! (fakultät) zu berechnen. \n");
  scanf("%d", &scanedNumber);
  printf("scanedNumber: %d \n", scanedNumber);
  for (int i = 0; i < scanedNumber; i++) {
    signedNumber *= add;
    add++;
  }
  add = 1;
  for (int i = 0; i < scanedNumber; i++) {
    unsignedNumber *= add;
    add++;
  }
  // ab dem punkt hätte ich für N! auch eine funktion schreiben können -.-
  // jetzt zu spät copy and past tut es auch
  add = 1;
  for (int i = 0; i < scanedNumber; i++) {
    longNumber *= add;
    add++;
  }
  add = 1;
  for (int i = 0; i < scanedNumber; i++) {
    longUnsigendNumber *= add;
    add++;
  }
  printf("signedNumber | %d! = %d \n", scanedNumber, signedNumber);
  printf("unsignedNumber | %d! = %u \n", scanedNumber, unsignedNumber);
  printf("Long long Number | %d! = %lld\n", scanedNumber, longNumber);
  printf("Long long unsignedNumber | %d! | %llu\n", scanedNumber,
         longUnsigendNumber);

  return 0;
}
/*
 * Console Output :
Gib ein zahl N um N! (fakultät) zu berechnen.
12
scanedNumber: 12
signedNumber | 12! = 479001600
unsignedNumber | 12! = 479001600
Long long Number | 12! = 479001600
Long long unsignedNumber | 12! | 479001600

maxim  …/C_Programming/Uni/4    v14.2.1  23:24 
./blatt4_3 Gib ein zahl N um N! (fakultät) zu berechnen. 13 scanedNumber: 13
signedNumber | 13! = 1932053504
unsignedNumber | 13! = 1932053504
Long long Number | 13! = 6227020800
Long long unsignedNumber | 13! | 6227020800

maxim  …/C_Programming/Uni/4    v14.2.1  23:24 
./blatt4_3 Gib ein zahl N um N! (fakultät) zu berechnen. 14 scanedNumber: 14
signedNumber | 14! = 1278945280
unsignedNumber | 14! = 1278945280
Long long Number | 14! = 87178291200
Long long unsignedNumber | 14! | 87178291200

maxim  …/C_Programming/Uni/4    v14.2.1  23:24 
./blatt4_3 Gib ein zahl N um N! (fakultät) zu berechnen. 15 scanedNumber: 15
signedNumber | 15! = 2004310016
unsignedNumber | 15! = 2004310016
Long long Number | 15! = 1307674368000
Long long unsignedNumber | 15! | 1307674368000

maxim  …/C_Programming/Uni/4    v14.2.1  23:24 
./blatt4_3 Gib ein zahl N um N! (fakultät) zu berechnen. 16 scanedNumber: 16
signedNumber | 16! = 2004189184
unsignedNumber | 16! = 2004189184
Long long Number | 16! = 20922789888000
Long long unsignedNumber | 16! | 20922789888000

maxim  …/C_Programming/Uni/4    v14.2.1  23:24 
./blatt4_3 Gib ein zahl N um N! (fakultät) zu berechnen. 17 scanedNumber: 17
signedNumber | 17! = -288522240
unsignedNumber | 17! = 4006445056
Long long Number | 17! = 355687428096000
Long long unsignedNumber | 17! | 355687428096000

maxim  …/C_Programming/Uni/4    v14.2.1  23:28 
./blatt4_3 Gib ein zahl N um N! (fakultät) zu berechnen. 20 scanedNumber: 20
signedNumber | 20! = -2102132736
unsignedNumber | 20! = 2192834560
Long long Number | 20! = 2432902008176640000
Long long unsignedNumber | 20! | 2432902008176640000

maxim  …/C_Programming/Uni/4    v14.2.1  23:29 
./blatt4_3 Gib ein zahl N um N! (fakultät) zu berechnen. 21 scanedNumber: 21
signedNumber | 21! = -1195114496
unsignedNumber | 21! = 3099852800
Long long Number | 21! = -4249290049419214848
Long long unsignedNumber | 21! | 14197454024290336768




*/
