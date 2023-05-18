#ifndef __type_enemies_H__
#define __type_enemies_H__


 	// Definição para os inimigos e monstros
typedef struct enemy {
	int attack, hp;
	int enemyX;
	int enemyY;
	int direction;

	// 4 tipos de inimigos
	// 1 - 'r'
	// 2 - 'a'
	// 3 - 'X'
	// 4 - 'G' 
	int type; 

	bool is_Following;
	bool just_Walking;
	bool can_attack;
} ENEMY;

#endif