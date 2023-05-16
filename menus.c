#include <ncurses.h>

char caixa(int xini, int yini, int xfin, int yfin) {
    int x = xini;
    int y = yini;
    char ret = ' ';
    if ((x == xini && y == yini) || (x == xfin && y == yfin)) {
        ret = '+';
    }
    if ((x == xini && y > yini && y < yfin) || (x == xfin && y > yini && y < yfin)) {
        ret = '|';
    }
    if ((x > xini && y == yini && x < xfin) || (x > xini && y == yfin && x < xfin)) {
        ret = '-';
    }
    if (x < xfin && y < yfin && x > xini && y > yini) {
        ret = ' ';
    }
    return ret;
}
