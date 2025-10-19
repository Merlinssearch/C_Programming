#include <ncurses.h>
#include <stdbool.h>
// #include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct snake {
  int x_pos;
  int y_pos;
  int snakeLenght;
};
struct tail {
  int taillenght;
  int x_pos[100];
  int y_pos[100];
};
// Windows Setting
void startNurses() {
  initscr();
  noecho();
  nodelay(stdscr, TRUE);
}
// to spawn Snack food
int randomGen(int min, int max) {
  int random;
  unsigned int seed = time(0);
  random = rand_r(&seed) % (max - min + 1) + min;
  return random;
}
void userInput(bool *gameLoop, int *x, int *y, bool *direction_up,
               bool *direction_down, bool *direction_left,
               bool *direction_right) {
  // int midLines = LINES / 2;
  // int midCols = COLS / 2;
  int input;
  int xpos_max = COLS;
  int xpos_min = 0;
  int ypos_max = LINES;
  int ypos_min = 0;
  // *direction_left = *direction_down = *direction_up = *direction_right =
  // false;
  for (int i = 0; i < 20; i++) {
    input = getch();
    if (input == 'q') {
      *gameLoop = false; // quit game
      break;
    } else if (input == 'w') {
      (*y) = ((*y) <= ypos_min + 1) ? ypos_max - 2 : (*y - 1);
      *direction_up = true;
      *direction_left = *direction_down = *direction_right = false;
    } else if (input == 'a') {
      *direction_left = true;
      *direction_down = *direction_up = *direction_right = false;
      (*x) = ((*x) <= xpos_min + 2) ? xpos_max - 2 : (*x - 1);
    } else if (input == 's') {
      *direction_down = true;
      *direction_left = *direction_up = *direction_right = false;
      (*y) = ((*y) >= ypos_max + 2) ? ypos_min + 1 : (*y + 1);
    } else if (input == 'd') {
      *direction_right = true;
      *direction_left = *direction_down = *direction_up = false;
      (*x) = ((*x) >= xpos_max - 2) ? xpos_min + 1 : (*x + 1);
    }
    napms(1);
  }
}

void drawTail(int taillenght, int *x, int *y, bool *direction_up,
              bool *direction_down, bool *direction_left,
              bool *direction_right) {
  if (*direction_up == true) {
    for (int i = 0; i < taillenght; i++) {

      mvprintw(*y + i, *x, "x");
    }
  }
}

// Todo : Points and maybe life something like that
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
    mvprintw(0, 4, "POS_X : %d | POS_Y : %d", posx, posy);
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

int main() {
  bool gameLoop = TRUE;
  startNurses();
  // starting point for snake (x and y )
  int x = COLS / 2;
  int y = LINES / 2;
  bool direction_up = false;
  bool direction_down = false;
  bool direction_left = false;
  bool direction_right = false;

  // int taillenght;
  //  Game loop
  while (gameLoop) {
    drawUI(&y, &x);

    mvprintw(y, x, "#");
    drawTail(5, &x, &y, &direction_up, &direction_down, &direction_left,
             &direction_right);
    // drawTail(5, &x, &y, &direction_up, &direction_down, &direction_left,
    //          &direction_right);

    userInput(&gameLoop, &x, &y, &direction_up, &direction_down,
              &direction_left, &direction_right);
    erase();
  }
  // refresh();
  endwin();
  return 0;
}
