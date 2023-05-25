#include <string.h>
#include <ncurses.h>
#include <stdbool.h>

#include "state.h"


	// aXXXXXX - Paulo Alexandre
    // Funções para inicializzar items aleatorios
void random_Items (STATE *st, int ncols, int nrows) {
    int i = 0;
    srand(time(NULL));

    for (i = 0; i < 10; i++) {

        int x = rand() % 250;
        int y = rand() % 55;
        
        for ( ; st->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; x++) {
            for ( ; st->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; y++) { };
        }

        st->items_list_easy[i].posx = x;
        st->items_list_easy[i].posy = y;
        st->items_list_easy[i].magnitude = 10 + ((rand() % 2) * 5);
        st->items_list_easy[i].used = FALSE;
    }

    for (i = 0; i < 10; i++) {

        int x = rand() % 250;
        int y = rand() % 55;
        
        for ( ; st->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; x++) {
            for ( ; st->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; y++) { };
        }

        st->items_list_Mid[i].posx = x;
        st->items_list_Mid[i].posy = y;
        st->items_list_Mid[i].magnitude = 5 + ((rand() % 2) * 5);
        st->items_list_Mid[i].used = FALSE;
    }
}



	// aXXXXXX - Paulo Alexandre
    // Funções para desenhar os inimigos.
void draw_items (Item item, int x, int y){
    if (item.magnitude <= 10 && item.magnitude >= 0) {
        attron(COLOR_PAIR(COLOR_WHITE));
        mvaddch(y, x, '+' | A_BOLD);
        attroff(COLOR_PAIR(COLOR_RED));
    }
    else if (item.magnitude > 10 && item.magnitude <= 30) {
        attron(COLOR_PAIR(COLOR_YELLOW));
        mvaddch(y, x, '+' | A_BOLD);
        attroff(COLOR_PAIR(COLOR_YELLOW));
    }
}