#ifndef ___type_items_H___
#define ___type_items_H___

#include "type_enemies.h"


	// a64459 - Paulo Alexandre
    // struct que define os items
typedef struct item 
{
    int posx, posy;
    int magnitude;
	bool used;

} Item;

#endif