#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void handle_sigint(int sig) {
    endwin();
    printf("\nПрограмма завершена.\n");
    exit(0);
}

int main() {
  signal(SIGINT, handle_sigint); 

  initscr();
  noecho();
  curs_set(0);
  srand(time(NULL));
  
  char* frame[10] = {
    "frames/0.txt",
    "frames/1.txt",
    "frames/2.txt",
    "frames/3.txt",
    "frames/4.txt",
    "frames/5.txt",
    "frames/6.txt",
    "frames/7.txt",
    "frames/8.txt",
    "frames/9.txt",
  };

  FILE *fp;

  start_color();
  init_pair(0, COLOR_BLUE, COLOR_BLACK);
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_RED, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);

  struct timespec req, rem;
  req.tv_sec = 0; // 0 секунд
  req.tv_nsec = 60000000; // 10 миллисекунд (10,000,000 наносекунд)
  
  for (int i = 0; ; i++) {
    // getch();
    nanosleep(&req, &rem);
    clear();
    if (i >= 10) i = 0;
    fp = fopen(frame[i], "r");
    char t;

    int o = rand() % 7;

    while (fscanf(fp, "%c", &t) != EOF) {
      attron(COLOR_PAIR(o));
      printw("%c", t);
      attroff(COLOR_PAIR(o));
    }
    refresh();
    fclose(fp);
  }
  
  endwin();
  return 0;
}
