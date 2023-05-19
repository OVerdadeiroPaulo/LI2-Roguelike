#ifndef ___type_items_H___
#define ___type_items_H___

#include "type_enemies.h"

typedef struct item // struct que define os items
{
    int posx, posy;
    int magnitude;
	bool used;

} Item;

#endif