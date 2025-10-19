#include <ncurses.h>
#include <stdbool.h>
// #include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Window Setting
void startNurses() {
  // int screen_height, screen_width;
  // getmaxyx(stdscr, screen_height, screen_width);
  initscr();
  noecho();
  nodelay(stdscr, TRUE);
}

int randomGen(int min, int max) {
  int random;
  unsigned int seed = time(0);
  random = rand_r(&seed) % (max - min + 1) + min; // stole this shit
  return random;
}

void userInput(bool *gameLoop, int *x, int *y, bool *direction_up,
               bool *direction_down, bool *direction_left,
               bool *direction_right) {
  int input;
  for (int i = 0; i < 20; i++) {
    input = getch();
    if (input == 'q') {
      *gameLoop = false; // quit game
      break;
    } else if (input == 'w' && *direction_down == false) {
      *direction_up = true;
      *direction_left = *direction_down = *direction_right = false;
    } else if (input == 'a' && *direction_right == false) {
      *direction_left = true;
      *direction_down = *direction_up = *direction_right = false;
    } else if (input == 's' && *direction_up == false) {
      *direction_down = true;

      *direction_left = *direction_up = *direction_right = false;
    } else if (input == 'd' && *direction_left == false) {
      *direction_right = true;
      *direction_left = *direction_down = *direction_up = false;
    }
    napms(1);
  }
}

void movePlayer(int *x, int *y, bool *direction_up, bool *direction_down,
                bool *direction_left, bool *direction_right, int *taily,
                int *tailx) {
  int xpos_max = COLS;
  int xpos_min = 0;
  int ypos_max = LINES;
  int ypos_min = 0;
  // int tailx = *x;
  // int taily = *y;

  if (*direction_up) {
    (*y) = ((*y) <= ypos_min + 1) ? ypos_max - 2 : (*y - 1);
    napms(43);
  } else if (*direction_left) {
    (*x) = ((*x) <= xpos_min + 2) ? xpos_max - 2 : (*x - 1);
    napms(28);
  } else if (*direction_down) {
    (*y) = ((*y) >= ypos_max + 2) ? ypos_min + 1 : (*y + 1);
    napms(43);
  } else if (*direction_right) {
    (*x) = ((*x) >= xpos_max - 2) ? xpos_min + 1 : (*x + 1);
    napms(28);
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
  // Up line
  for (int i = 1; i < COLS - 1; i++) {
    mvprintw(y2, i, "-");
    mvprintw(0, 4, "POS_X : %d | POS_Y : %d", posx, posy); // for debuging
  }
  // Down line
  for (int i = 1; i < COLS - 1; i++) {
    mvprintw(LINES - 1, i, "-");
  }
  // Left line
  for (int i = 1; i < LINES - 1; i++) {
    mvprintw(i, x2, "|");
  }
  // Right line
  for (int i = 1; i < LINES - 1; i++) {
    mvprintw(i, COLS - 1, "|");
  }
}

void drawTail(int *x, int *y, bool *direction_up, bool *direction_down,
              bool *direction_left, bool *direction_right, int *taily,
              int *tailx) {
  (*taily) = (*y);
  (*tailx) = (*x);
  if (*direction_up) {
    (*taily) -= 1;
  } else if (*direction_left) {
    (*taily) += 1;
  } else if (*direction_down) {
    (*taily) += 1;
  } else if (*direction_right) {
    (*taily) -= 1;
  }
}

int main() {
  bool gameLoop = TRUE;
  startNurses();
  // starting point for snake (x and y )
  int x = COLS / 2;
  int y = LINES / 2;
  int tailx = x, taily = y;
  bool direction_up = false;
  bool direction_down = false;
  bool direction_left = false;
  bool direction_right = false;
  while (gameLoop) {
    erase();
    drawUI(&x, &y);
    mvprintw(y, x, "#");
    // mvprintw(taily, tailx, "+");
    //  drawTail(5, &x, &y, &direction_up, &direction_down, &direction_left,
    //           &direction_right);
    userInput(&gameLoop, &x, &y, &direction_up, &direction_down,
              &direction_left, &direction_right);

    movePlayer(&x, &y, &direction_up, &direction_down, &direction_left,
               &direction_right, &taily, &tailx);
    drawTail(&x, &y, &direction_up, &direction_down, &direction_left,
             &direction_right, &taily, &tailx);
  }
  // refresh();
  endwin();
  return 0;
}
