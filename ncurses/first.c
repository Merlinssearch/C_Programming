#include "ncurses.h"
#include <fcntl.h>
#include <stdbool.h>
#include <sys/select.h>
#include <unistd.h>
// move always in One direction which is pressed
// loop
/*

void userInput () {
    bool waitInput = true;
    while (waitInput) {
      getch();

  }

}

 */
int main() {
  initscr();
  const int midlines = LINES / 2;
  const int midcol = COLS / 2;
  // int y2 = midlines - 3;
  // int x2 = midcol;
  int y = midlines;
  int x = midcol;
  int key;
  bool doit = true;
  // bool waitInput = true;
  noecho();
  nodelay(stdscr, true);
  while (doit) {
    erase();
    mvprintw(y, x, "#");
    // x++;
    // y++;
    //  mvprintw(y2, x2, "#");
    key = getch();
    switch (key) {
    case 'w':
      if (y == 0) {
        y = LINES;
      } else {
        y--;
      }
      break;
    case 'a':
      if (x == 0) {
        x = COLS;
      } else {
        x--;
      }
      break;
    case 's':
      if (y == LINES) {
        y = 0;
      } else {
        y++;
      }
      break;
    case 'd':
      if (x == COLS) {
        x = 0;
      } else {
        x++;
      }
      break;
    default:
      continue;
    }

    refresh();
  }

  napms(3000);
  endwin();
  return 0;
}
