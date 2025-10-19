/*
 *M¨axchen (blatt2_2.c)
Schreiben Sie ein Programm, um das Spiel M¨axchen zu simulieren. Dazu werden zur
Laufzeit zwei ganze Zahlen von 1 bis 6 eingegeben, wobei die kleinere Zahl
zuerst einzugeben ist. Die Ausgabe soll wie folgt sein: • Falls beide Zahlen
gleich sind, wird - durch Leerzeichen getrennt - das Wort Pasch und die
eingegebene Zahl ausgegeben. • bei einer 1 und einer 2 wird das Wort Maexchen
ausgegeben. • Wenn es weder Pasch noch M¨axchen gibt, dann wir die gr¨oßte
zweistellige Zahl, die sich mit den beiden Zahlen bilden l¨asst (z.B. 43 bei
einer 3 und einer 4) ausgegeben.
*/
#include <stdio.h>
int main() {
  int wurfel1, wurfel2;
  printf("Gibt mir den ersten Würfel wurf \n");
  scanf("%d", &wurfel1);
  printf("Gibt mir den Zweiten Wurfel wurf \n");
  scanf("%d", &wurfel2);
  if (wurfel1 == wurfel2) {
    printf("Pasch : %d %d \n", wurfel1, wurfel2);
  } else if ((wurfel1 == 1 && wurfel2 == 2) || (wurfel1 == 2 && wurfel2 == 1)) {
    printf("Mäxchen!! \n");
  } else if (wurfel1 > wurfel2) {
    printf("%d%d", wurfel1, wurfel2);
  } else if (wurfel2 > wurfel1) {
    printf("Den Wert %d%d gewürfelt", wurfel2, wurfel1);
  }
  return 0;
}
