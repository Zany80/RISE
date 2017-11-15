#include <data.h>
#include <prison.h>

void prison_navigate(){
	prison_map_t *map = get_prison_map();
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

prison_map_t *get_prison_map(){
	//use bank 4 for prison map data, map to 0x4000-0x8000 in RAM
	//Note: DO NOT UNDER ANY CIRCUMSTANCES allow code to exceed 16KB!
	//This is going to be a problem, I just know it. Unfortunately, bank 3 is used for pmem, and 2 is used for the stack.
	swapBanks(4,1);
	return (prison_map_t*)0x4000;
}

void init_prison(prison_map_t *map){
	map->posX = 0;
	map->posY = 0;
	map->tiles[0][0].symbol = '!';
	map->tiles[0][0].handler = escaped_yay;
}

void escaped_yay(){
	
}
