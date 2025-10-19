#include <ncurses.h>
#include <stdbool.h>
// #include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct player {
  int x_Pos;
  int y_Pos;
  bool direction_up;
  bool direction_down;
  bool direction_left;
  bool direction_right;
};

void startNurses() {
  initscr();
  noecho();
  nodelay(stdscr, true);
  // The nodelay option causes getch to be a non-blocking call. If no input is
  // ready, getch returns ERR. If disabled (bf is FALSE), getch waits until a
  // key is pressed.
}

int randomGen(int min, int max) {
  int random;
  unsigned int seed = time(0);
  random = rand_r(&seed) % (max - min + 1) + min; // stole this shit
  return random;
}

void drawUI(int *x, int *y) {
  int y2 = 0;
  int x2 = 0;
  int posx = (*x);
  int posy = (*y);
  // ECKEN
  mvprintw(0, COLS - 1, "+");
  mvprintw(LINES - 1, COLS - 1, "+");
  mvprintw(0, 0, "+");
  mvprintw(LINES - 1, 0, "+");
  // Erste Reihe
  for (int i = 1; i < COLS - 1; i++) {
    mvprintw(y2, i, "-");
    mvprintw(0, 4, "POS_X : %d | POS_Y : %d", posx, posy); // for debuging
  }
  // Unterste Reihe
  for (int i = 1; i < COLS - 1; i++) {
    mvprintw(LINES - 1, i, "-");
  }
  // Left
  for (int i = 1; i < LINES - 1; i++) {
    mvprintw(i, x2, "|");
  }
  // Right
  for (int i = 1; i < LINES - 1; i++) {
    mvprintw(i, COLS - 1, "|");
  }
}
void CaptureUserInput() {}

int main() {
  int x_Pos = COLS / 2;
  int y_Pos = LINES / 2;
  bool direction_up;
  bool direction_down;
  bool direction_left;
  bool direction_right;

  struct player Head;
  bool gameloop = true;
  startNurses();
  while (gameloop) {
  }
  return 0;
}
