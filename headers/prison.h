#pragma once

typedef void (*tile_handler_t)();

typedef struct{
	 char symbol;
	 tile_handler_t handler;
} prison_tile_t;

typedef struct{
	char posX;
	char posY;
	// 16 rows of 16 tiles
	prison_tile_t tiles[16][16];
} prison_map_t;

void init_prison(prison_map_t* map);
void escaped_yay();
