/*1. Spannung, Strom und Widerstand (blatt6_1.c)
Implementieren Sie mit Hilfe von Funktionen das in den Folien vorgestellte
C-Programm zur Berechnung der Spannung. Verwenden Sie den Code von Folie 9
und 13. Erweitern Sie ihr Programm, d.h. die main-Funktion, um eine Schleife, in
der der Benutzer immer wieder gefragt wird, ob er Spannung U, Strom I oder
Widerstand R berechnen m¨ochte. Davon abh¨angig soll entweder U, I oder R mit
Hilfe geeigneter Funktionen (wie im ersten Teil bereits fur die Spannung
umgesetzt) berechnet werden. */
#include <stdio.h>
float berechneSpannung() {
  float u, r, i; // Lokale Variable
  printf("Gib mir den Wert des Widerstands in Ohm:\n");
  scanf(" %f", &r);
  printf("Gib mir den Wert der Stromstärke in Amper:\n");
  scanf(" %f", &i);
  u = r * i; // Spannungsberechnung
  return u;  // Rueckgabe von Ergebnis
}
float berechneWiderstand() {
  float r, u, i;
  printf("Gib mir den Wert der Spannung in Volt:\n");
  scanf(" %f", &u);
  printf("Gib mir den Wert der Stromstärke in Amper:\n");
  scanf(" %f", &i);
  r = u / i;
  return r;
}

float berechneStrom() {
  float i, r, u;
  printf("Gib mir den Wert der Spannung in Amper:\n");
  scanf(" %f", &u);
  printf("Gib mir den Wert der Spannung in Amper:\n");
  scanf(" %f", &r);
  i = r / u;
  return i;
}

int main() {
  float output;
  char input;
  char input2 = 'y';
  do {
    printf("Stromstärke/Widerstand/Spannungs-Rechner:\n");
    printf("Was möchtest du berechnen R , I oder U ? Tippe nur den Buchstaben "
           "ein : \n");
    scanf(" %c", &input);
    if (input == 'r' || input == 'R') {
      output = berechneWiderstand();
      printf("Der Widerstand beträgt : %f Ohm \n", output);
    } else if (input == 'u' || input == 'U') {
      output = berechneSpannung();
      printf("Die Spannung beträgt : %f Volt \n", output);
    } else if (input == 'i' || input == 'I') {
      output = berechneStrom();
      printf("Die Stromstärke beträgt : %f Amper \n", output);
    } else {
      printf("Falscher input \n");
    }
    printf("Programm neustarten ? yes = y / no = n  \n");
    scanf(" %c", &input2);
    if (input2 == 'n' || input2 == 'n') {
      printf("Neustart: \n");
    }
  } while (input2 != 'n');
  return 0;
}
