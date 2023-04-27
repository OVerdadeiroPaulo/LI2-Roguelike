#ifndef ___STATE_H___
#define ___STATE_H___

#include "type_maps.h"
#include "type_enemies.h"



	// Definição do Jogo e estados
typedef struct state {
	int playerX;
	int playerY;

	int max_width;
	int max_heigth;

	CELL mapaEasy[250][55];
	CELL mapaMid[750][300];
	CELL mapaHard[1500][750];


	ENEMY enemy_list [5];

} STATE;

#endif