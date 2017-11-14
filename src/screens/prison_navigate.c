#include <output.h>
#include <data.h>
#include <prison.h>
#include <input.h>
#include <system.h>

void prison_navigate(){
	prison_map_t *map = (prison_map_t*)getData()->current_save.misc_data;
	int i, j;
	if (((char*)map)[255] == 0) {
		init_prison(map);
		((char*)map)[255] = 1;
	}
	cls();
	puts("Escape!\n\n");
	for (i = 0; i != 16; i++) {
		for (j = 0; j != 16; j++) {
			if (map->tiles[i][j].symbol != 0) {
				putch(map->tiles[i][j].symbol);
			}
		}
		putch('\n');
		for (j = 0; j !=64; j++) {
			putch('-');
		}
		putch('\n');
	}
	halt();
	switch (waitInput()) {
		
	}
}

void init_prison(prison_map_t *map){
	map->posX = 0;
	map->posY = 0;
	map->tiles[0][0].symbol = '!';
	map->tiles[0][0].handler = escaped_yay;
}

void escaped_yay(){
	
}
