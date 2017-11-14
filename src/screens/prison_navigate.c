#include <output.h>
#include <data.h>
#include <prison.h>

void prison_navigate(){
	prison_map_t *map = (prison_map_t*)getData()->current_save.misc_data;
	if (((char*)map)[255] == 0) {
		init_prison(map);
		((char*)map)[255] = 1;
	}
	cls();
	puts("Escape!\n\n");
}

void init_prison(prison_map_t *map){
	map->posX = 0;
	map->posY = 0;
}
