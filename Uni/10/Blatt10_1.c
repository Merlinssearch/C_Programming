#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned long nummer;
  char name[100];
  short geb_jahr;
  unsigned short geschlecht;
} kunde;

int einfuegen(kunde kdb[], int index) {
  if (index >= 999) {
    printf("Maximale Anzahl erreicht.\n");
    return index;
  }

  kunde neuer_kunde;

  printf("Geben Sie die neue Kundennummer an: \n");
  scanf("%lu", &neuer_kunde.nummer);

  printf("Geben Sie den Namen ein: \n");
  scanf("%s", neuer_kunde.name);

  printf("Geben Sie das Geburtsjahr ein: \n");
  scanf("%hd", &neuer_kunde.geb_jahr);

  printf("Geben Sie das Geschlecht ein (0 = divers, 1 = weiblich, 2 = "
         "männlich): \n");
  scanf("%hu", &neuer_kunde.geschlecht);

  kdb[index] = neuer_kunde;
  printf("Kunde erfolgreich hinzugefügt!\n");
  return index + 1;
}

void printkunde(kunde kdb[], int index) {
  kunde k = kdb[index];
  printf("------------------------------------ \n");
  printf("Kundendaten:\n");
  printf("Nummer: %lu\n", k.nummer);
  printf("Name: %s\n", k.name);
  printf("Geburtsjahr: %hd\n", k.geb_jahr);

  printf("Geschlecht: ");
  if (k.geschlecht == 0) {
    printf("divers\n");
  } else if (k.geschlecht == 1) {
    printf("weiblich\n");
  } else {
    printf("männlich\n");
  }

  printf("------------------------------------ \n");
}


void anzeigen(kunde kdb[], int index) {
  if (index == 0) {
    printf("Die Datenbank ist leer!\n");
    return;
  }

  int pos, wahl;
  printf("<0> Alle Kunden anzeigen\n");
  printf("<1> Bestimmten Kunden anzeigen (Index)\n");
  printf("<2> Nach Namen suchen\n");
  printf("Ihre Wahl: ");
  scanf("%d", &wahl);

  if (wahl == 1) {
    printf("Geben Sie die Indexnummer des Kunden ein (0 bis %d): \n",
           index - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= index) {
      printf("Fehler: Ungültiger Index!\n");
      return;
    }
    printkunde(kdb, pos);

  } else if (wahl == 0) {
    for (int i = 0; i < index; i++) {
      printkunde(kdb, i);
    }

  } else if (wahl == 2) {
    char suchname[100];
    printf("Geben Sie den Namen ein, nach dem gesucht werden soll: ");
    scanf("%s", suchname);

    int gefunden = 0;
    for (int i = 0; i < index; i++) {
      if (strcmp(kdb[i].name, suchname) == 0) {
        printkunde(kdb, i);
        gefunden = 1;
      }
    }

    if (!gefunden) {
      printf("Kein Kunde mit dem Namen '%s' gefunden.\n", suchname);
    }
  } else {
    printf("Ungültige Auswahl!\n");
  }
}

int main() {
  int MAX_CUSTOMERS = 999;
  kunde kunden_db[MAX_CUSTOMERS];
  int index = 0, operation;

  do {
    printf("------------------------------------ \n");
    printf("<1> Neuen Datensatz anlegen\n");
    printf("<2> Vorhandenen Datensatz abrufen\n");
    printf("<0> Programm beenden , oder einfach Stecker vom PC ziehen\n");
    printf("Ihre Wahl: ");
    scanf("%d", &operation);
    printf("------------------------------------ \n");

    if (operation == 1) {
      index = einfuegen(kunden_db, index);
    } else if (operation == 2) {
      anzeigen(kunden_db, index);
    } else if (operation != 0) {
      printf("Ungültige Auswahl! Bitte versuch es nicht neu.\n");
    }
  } while (operation != 0);

  printf("Programm beendet.\n");
  return 0;
}
