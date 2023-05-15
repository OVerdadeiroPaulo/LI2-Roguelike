#ifndef ___STATE_H___
#define ___STATE_H___

#include "type_maps.h"
#include "type_enemies.h"



	// Definição do Jogo e estados
typedef struct state {
	int playerX;
	int playerY;

		// 0 if Easy
		// 1 if medium
		// 2 if Hard
	int dificulty;

	CELL mapaEasy[55][250];
	CELL mapaMid[150][300];
	CELL mapaHard[200][350];

	ENEMY enemy_list[5];

} STATE;

#endif