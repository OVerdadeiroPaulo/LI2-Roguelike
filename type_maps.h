#ifndef ___type_maps_H___
#define ___type_maps_H___

	// Deinição para cada bloco de piso
typedef struct cell {
	bool is_wall;
	bool is_water;
	bool is_grass;
	bool is_mud;
    bool is_stairs_up;
    bool is_stairs_down;

} CELL;
#endif