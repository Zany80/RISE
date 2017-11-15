#include <screens.h>
#include <output.h>
#include <input.h>
#include <data.h>
#include <sprites.h>
#include <system.h>

#define menu_string (const char *) \
						"RISE\n" \
						"\n" \
						"Created by Noam Preil.\n" \
						"Copyright 2017 Noam Preil.\n" \
						"Art created by and copyright of Thomas Fenton.\n" \
						"\n" \
						"Select option: \n" \
						"\t'n' - New Game\n" \
						"\t'l' - Load Game\n" \
						"\t'a' - About page\n" \
						"\t's' - Settings screen\n" \
						"\n"

extern char * ICON_DATA;

void main_menu(){
	char invalid=8;
	char * icon=ICON_DATA;
	static char uploaded=0;
	// make sure RAM is in a sane state - banks *will* be swapped later,
	// but they have to have the proper defaults.
	//~ swapBanks(1, 1);
	if(uploaded==0){
		uploaded=1;
		uploadSprite32_32(1,icon,1);
	}
	while (1) {
		keycode_t keycode;
		if(invalid==8){
			cls();
			puts(menu_string);
			invalid=0;
		}	
		drawSprite32_32(1,200,30);
		switch(keycode=waitInput()){
			case keyn:
				setScreen(newGame);
				return;
			case keyl:
				setScreen(loadGame);
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
