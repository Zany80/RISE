#include <screens.h>
#include <output.h>
#include <system.h>
#include <input.h>

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
	cls();
	puts(menu_string);
	{
		switch(waitInput()){
			case keyn:
				setScreen(new_game);
				break;
			default:
				break;
		}
	}
}
