#include <screens.h>
#include <output.h>
#include <input.h>
#include <data.h>

#include <sprites.h>

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

extern char * ICON_DATA;

void main_menu(){
	int invalid=8;
	char * icon=ICON_DATA;
	uploadSprite32_32(1,icon,15);
	while (1) {
		keycode_t keycode;
		if(invalid==8){
			cls();
			puts(menu_string);
			drawSprite32_32(1,200,30);
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
