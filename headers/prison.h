#pragma once

typedef void (*tile_handler_t)();

typedef struct{
	 char symbol;
	 tile_handler_t handler;
} prison_tile_t;

typedef struct{
	char posX;
	char posY;
	prison_tile_t tiles[256];
} prison_map_t;

void init_prison(prison_map_t* map);
