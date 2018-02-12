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
        //mx: a terminál hossza, my: a terminál magassága

        xj = (xj - 1) % mx;
        xk = (xk + 1) % mx;

        yj = (yj - 1) % my;
        yk = (yk + 1) % my;

        clear ();
        
        //vízszintes sorok
        for(int j = 0; j <= mx / 2; j++)
        {
            mvprintw (0, j, "-");
            mvprintw (my / 2, j,"-");
        }
        
        //föggőleges sorok
        for(int j = 1; j <= my / 2 -1; j++)
        {
            mvprintw(j, 0, "|");
            mvprintw(j, mx / 2, "|");
        }

        mvprintw (abs ((yj + (my - yk)) / 2),
                  abs ((xj + (mx - xk)) / 2), "O");

        refresh ();
        usleep (150000);

    }
    return 0;
}
