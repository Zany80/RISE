#include <screens.h>
#include <data.h>

screen_t getCurrentScreen() {
	return *(getData()->current_save.current_screen);
}

void setScreen(screen_t s){
	getData()->current_save.current_screen=s;
}
