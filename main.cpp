#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <unistd.h>

int
main (void)
{
    int xj = 0, xk = 0, yj = 0, yk = 0;


    WINDOW *ablak;
    ablak = initscr();
    noecho ();
    cbreak ();
    nodelay (ablak, true);

    for (;;)
    {

        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        int mx = (w.ws_col - 1) * 2, my = w.ws_row * 2 - 1;

        xj = (xj - 1) % mx;
        xk = (xk + 1) % mx;

        yj = (yj - 1) % my;
        yk = (yk + 1) % my;

        clear ();

        for(int j = 0; j <= mx / 2; j++)
        {
            mvprintw (0, j, "-");
            mvprintw (my / 2, j,"-");
        }


        mvprintw (abs ((yj + (my - yk)) / 2),
                  abs ((xj + (mx - xk)) / 2), "O");

        refresh ();
        usleep (150000);

    }
    return 0;
}
