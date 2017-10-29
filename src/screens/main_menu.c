#include <screens.h>
#include <output.h>
#include <input.h>
#include <data.h>

#define menu_string (const char *) \
						"RISE\n" \
						"\n" \
						"Created by Noam Preil.\n" \
						"Copyright 2017 Noam Preil.\n" \
						"\n" \
						"Select option: \n" \
						"\t'n' - New Game\n" \
						"\t'l' - Load Game\n" \
						"\t'a' - About page\n" \
						"\t's' - Settings screen\n" \
						"\n"

void main_menu(){
	int invalid=8;
	while (1) {		
		keycode_t keycode;
		if(invalid==8){
			cls();
			puts(menu_string);
			invalid=0;
		}
		switch(keycode=waitInput()){
			case keyn:
				newGame();
				return;
			default:
				invalid++;
				puts("Invalid key: ");
				puts(toAscii(keycode));
				putch(0x0A);
				break;
		}
	}
}
