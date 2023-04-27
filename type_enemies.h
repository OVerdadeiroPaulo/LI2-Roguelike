#ifndef __type_enemies_H__
#define __type_enemies_H__


 	// Definição para os inimigos e monstros
typedef struct enemy {
	int enemyX;
	int enemyY;

	bool is_Following;
	bool just_Walking;
	bool attack;

} ENEMY;

#endif