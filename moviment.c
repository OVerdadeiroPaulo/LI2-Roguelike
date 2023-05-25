#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "start.c"


	// a105684 - Joshua David
    // Função que avalia se o terreno é valido para movimento
void move_action (STATE *st, int movex, int movey, int ncols, int nrows) {
	int x = st->playerX + movex + (ncols / 2);
	int y = st->playerY + movey + (nrows / 2);
	int ny = st->playerY - movey + (nrows / 2);


	if (st->dificulty == 1) {
		if (y <= 0 || y >= 55 || x <= 0 || x >= 250) { }
		else if (st->mapaEasy[ny][x].is_water == TRUE &&
			st->mapaEasy[st->playerY + (nrows / 2)][st->playerX + (ncols / 2)].is_water == TRUE) {
				st->playerX += movex;
				st->playerY -= movey;
		}
		else if (st->mapaEasy[y][x].is_wall != TRUE) {
			st->playerX += movex;
			st->playerY += movey;
		}
	}
	
	
	else if (st->dificulty == 2) {	
		if (y <= 0 || y >= 55 || x <= 0 || x >= 250) { }
		else if (st->mapaMid[ny][x].is_water == TRUE &&
			st->mapaMid[st->playerY + (nrows / 2)][st->playerX + (ncols / 2)].is_water == TRUE) {
				st->playerX += movex;
				st->playerY -= movey;
		}
		else if (st->mapaMid[y][x].is_wall != TRUE) {
			st->playerX += movex;
			st->playerY += movey;
		}
	}
	
	
	else if (st->dificulty == 3) {
		if (y <= 0 || y >= 55 || x <= 0 || x >= 250) { }
		else if (st->mapaHard[ny][x].is_water == TRUE &&
			st->mapaHard[st->playerY + (nrows / 2)][st->playerX + (ncols / 2)].is_water == TRUE) {
				st->playerX += movex;
				st->playerY -= movey;
		}
		else if (st->mapaHard[y][x].is_wall != TRUE) {
			st->playerX += movex;
			st->playerY += movey;
		}
	}
}



	// a105684 - Joshua David
    // Função a Seleção no menu
void move_menu (STATE *st, int move, int ncols, int nrows) {
	if  (move == 1)
		if (st->selection == FALSE)
			st->selection = TRUE;
		else
			st->selection = FALSE;
	else if  (move == 2) {
		if (st->menu == 0) {
			if (st->selection == TRUE) {
				gerar(st, ncols, nrows);
				st->menu = 1;
			}
			else if (st->selection == FALSE) {
				endwin ();
				exit (0);
			}
		}
		else if (st->menu == 2) {
			if (st->selection == TRUE)
				st->menu = 1;
			else if (st->selection == FALSE) {
				st->menu = 0;
			}
		}
		else if (st->menu == 3) {
			if (st->selection == TRUE) {
				gerar(st, ncols, nrows);
				st->menu = 1;
			}
			else if (st->selection == FALSE) {
				st->menu = 0;
			}
		}
		else if (st->menu == 4) {
			if (st->selection == TRUE) {
				gerar(st, ncols, nrows);
				st->menu = 1;
			}
			else if (st->selection == FALSE) {
				st->menu = 0;
			}
		}
	}
}



	// a105684 - Joshua David
    // Função que avalia se o terreno é um item ou escada
void activate_move (STATE *st, int ncols, int nrows) {
	int i;
	int  items_easy = 0, items_Mid = 0;

	int x = st->playerX + (ncols / 2);
	int y = st->playerY + (nrows / 2);

	if (st->dificulty == 1) {
		for (i = 0; i < 10; i++) {
			if (st->items_list_easy[i].posx == x&& st->items_list_easy[i].posy == y)
				items_easy = i + 1;
		}

		if (st->mapaEasy[y][x].is_stairs) {
			
       // clausula que recebe o nivel de deficuldade para reposicionar o player dentro de um espaco aberto, caso contrario, poderiamos mudar de nivel e ter as cair numa parede.
           int x = 0;
           int y = 0;  // valor para comecar a colocar o player no centro da dungeon.
    
        for ( ; st->mapaMid[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; y++) {    // loop para dar a volta ao mapa ate encontrar uma posicao aberta.
            for ( ; st->mapaMid[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; x++) { };
        }
    
        st->playerX = x;  // posicao actual X do player.
        st->playerY = y; // posicao actual Y do player. 
    
	    st->dificulty ++; // incrementacao do nivel de dificuldade.
 
       
		}
		else if (items_easy != 0) {
			st->playerHP = st->playerHP + st->items_list_easy[items_easy - 1].magnitude;
			st->items_list_easy[items_easy - 1].used = TRUE;
		}
	}


	else if (st->dificulty == 2) {
		for (i = 0; i < 10; i++) {
			if (st->items_list_Mid[i].posx == x && st->items_list_Mid[i].posy == y)
				items_Mid = i + 1;
		}

		if (st->mapaMid[y][x].is_stairs) {

       // clausula que recebe o nivel de deficuldade para reposicionar o player dentro de um espaco aberto, caso contrario, poderiamos mudar de nivel e ter as cair numa parede.
           int x = 0;
           int y = HEIGHT_dungeon/2;  // valor para comecar a colocar o player no canto da dungeon.
    
        for ( ; st->mapaHard[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; y++) {    // loop para dar a volta ao mapa ate encontrar uma posicao aberta.
            for ( ; st->mapaHard[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; x++) { };
        }
    
        st->playerX = x;  // posicao actual X do player.
        st->playerY = y; // posicao actual Y do player. 
    
	    st->dificulty ++; // incrementacao do nivel de dificuldade.
 

		}
		
		else if (items_Mid != 0) {
			st->playerHP = st->playerHP + st->items_list_Mid[items_Mid - 1].magnitude;
			st->items_list_Mid[items_Mid - 1].used = TRUE;
		}
	}


	else if (st->dificulty == 3) {
		if (st->mapaHard[y][x].is_stairs) {
			clear ();
			st->menu = 3;
		}
	}
}



	// a105684 - Joshua David
    // Função que busca o caractere do jogador
void moviment(STATE *st, int ncols, int nrows) {

	int key = getch();

    switch(key) {
		case KEY_BACKSPACE: activate_move (st, ncols, nrows); break;
		case KEY_UP: move_action(st, +0, -1, ncols, nrows); break;
		case KEY_DOWN: move_action(st, +0, +1, ncols, nrows); break;
		case KEY_LEFT: move_action(st, -1, +0, ncols, nrows); break;
		case KEY_RIGHT: move_action(st, +1, +0, ncols, nrows); break;
		case 'p': st->menu = 2; break;
		case 'q': endwin(); exit(0); break;
	}
}



	// a105684 - Joshua David
    // Função que busca o caractere da seleção de menu
void moviment_menu(STATE *st, int ncols, int nrows) {

	int key = getch();

    switch(key) {
		case KEY_BACKSPACE: move_menu(st, 2, ncols, nrows); break;
		case KEY_UP: move_menu(st, 1, ncols, nrows); break;
		case KEY_DOWN: move_menu(st, 1, ncols, nrows); break;
		case KEY_LEFT: move_menu(st, 1, ncols, nrows); break;
		case KEY_RIGHT: move_menu(st, 1, ncols, nrows); break;
		case 'q': endwin(); exit(0); break;
	}
}