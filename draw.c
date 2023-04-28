#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "start.c"



	// Função que desenha as coordenadas do jogador
	// Ultilizar essa função para eventualmente desenhar
	// a vida e itens do jogador
void draw_Cood (STATE *st, int ncols, int nrows){

	move(nrows - 2, 5);
	attron(COLOR_PAIR(COLOR_BLUE));
	printw("(%d, %d) %d %d", st->playerX, st->playerY, ncols, nrows);
	attroff(COLOR_PAIR(COLOR_BLUE));

}



	// Função que desenha o jogador
void draw_player (STATE *st) {

	attron(COLOR_PAIR(COLOR_CYAN));
	mvaddch(st->playerY, st->playerX, '@' | A_BOLD);
	attroff(COLOR_PAIR(COLOR_CYAN));

}



	// Função que identifica parede, inimigos ou vazio na CELL
void draw_objects (STATE *st, int x, int y) {

	int vertical = st->playerY + y;
	int horizontal = st->playerX + x;

	// if (exist_Enemy(st, x, y)) {
	// 	attron(COLOR_PAIR(COLOR_CYAN));
	//  	mvaddch (vertical, horizontal, '#' | A_BOLD);
	// 	attroff(COLOR_PAIR(COLOR_CYAN));
	// }
	
		// Caso seja uma Parede
	if (st->mapaEasy[horizontal][vertical].is_wall == TRUE) {
		attron(COLOR_PAIR(COLOR_GREEN));
		mvaddch (vertical, horizontal, '#' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_GREEN));
	}
		// Caso seja um terreno de Rio
	else if (st->mapaEasy[horizontal][vertical].is_water == TRUE) {
		attron(COLOR_PAIR(COLOR_BLUE));
		mvaddch (vertical, horizontal, '~' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
		// Caso seja um terreno de Relva
	else if (st->mapaEasy[horizontal][vertical].is_grass == TRUE) {
		attron(COLOR_PAIR(COLOR_GREEN));
		mvaddch (vertical, horizontal, '.' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_GREEN));
	}
		// Caso seja um terreno vazio
	else {
		attron(COLOR_PAIR(COLOR_WHITE));
		mvaddch (vertical, horizontal, '-' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_WHITE));
	}
}



	// Função que desenha a iluminação
void draw_light (STATE *st, int raio) {
	int x;
	int y;

		// Definição do circulo de luz do jogador
	for (x = 0; x < 2*raio+1; x++) {
		for (y = 0; y < 2*raio+1; y++) {
			float d = sqrt ((x * x) + (y * y));
			if (d <= raio) {
				draw_objects(st, x, y);
				draw_objects(st, -x, y);
				draw_objects(st, x, -y);
				draw_objects(st, -x, -y);
			}
		}
	}
}



	// Função para apagar certa área do ecrã
void earse_all (STATE *st, int cumprimento, int altura) {
	int x, y;

	for (x = 0; x < cumprimento; x++) {
		for (y = 0; y < altura; y++) {
			mvaddch(st->playerY + y, st->playerX + x, ' ' | A_BOLD);
			mvaddch(st->playerY + y, st->playerX - x, ' ' | A_BOLD);
			mvaddch(st->playerY - y, st->playerX + x, ' ' | A_BOLD);
			mvaddch(st->playerY - y, st->playerX - x, ' ' | A_BOLD);
		}
	}
}