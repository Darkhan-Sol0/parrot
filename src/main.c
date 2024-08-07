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

  const char *home = getenv("HOME");
  
  // char* frame[10] = {
  //   "~/parrot/frames/0.txt",
  //   "~/parrot/frames/1.txt",
  //   "~/parrot/frames/2.txt",
  //   "~/parrot/frames/3.txt",
  //   "~/parrot/frames/4.txt",
  //   "~/parrot/frames/5.txt",
  //   "~/parrot/frames/6.txt",
  //   "~/parrot/frames/7.txt",
  //   "~/parrot/frames/8.txt",
  //   "~/parrot/frames/9.txt",
  // };

  char frame[10][256];
    for (int i = 0; i < 10; i++) {
        snprintf(frame[i], sizeof(frame[i]), "%s/parrot/frames/%d.txt", home, i);
    }

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
