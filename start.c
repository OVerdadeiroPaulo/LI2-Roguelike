#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"


	// Inicialização do mapa e Jogador
void gerar(STATE *s, int nCols, int nRows) {
	int i, j;

	s->playerX = nCols / 2;
	s->playerY = nRows / 2;

	for (i = 0; i < nCols; i++) {
		for (j = 0; j < nRows; j ++) {
			if (i == 0 || i == nCols - 1 || j == 0 || j == nRows - 1) {
				s->mapaEasy[i][j].is_wall = TRUE;
				s->mapaEasy[i][j].was_seen = TRUE;
			} else if (i == 20) {
				s->mapaEasy[i][j].is_wall = TRUE;
				s->mapaEasy[i][j].was_seen = TRUE;
			} else if (j == 20) {
				s->mapaEasy[i][j].is_wall = TRUE;
				s->mapaEasy[i][j].was_seen = TRUE;
			} else if (i == 120) {
				s->mapaEasy[i][j].is_wall = TRUE;
				s->mapaEasy[i][j].was_seen = TRUE;
			}
			else {
				s->mapaEasy[i][j].is_wall = FALSE;
				s->mapaEasy[i][j].was_seen = FALSE;
			}
	 	}
	}

	// s->enemy_list[1].enemyX = 5;
	// s->enemy_list[1].enemyY = 10;

}



	// Função que gera um mapa aleatorio
void random_mapa( ) {

}



 	// Função que inicia os inimigos em posições aleatórias
void random_Enemy( ) {
	
}



 	// Dado uma coordenada identifica se existe inimigo
int exist_Enemy(STATE *s, int x, int y) {
	int i;
	int res = 0;

	for (i = 0; i < 5 && res == 0; i++) {
	 	if (s->enemy_list[i].enemyX == x && s->enemy_list[i].enemyY == y)
	 		res = 1;
	}

	return res;
}