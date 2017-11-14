#include <output.h>
#include <input.h>
#include <data.h>
#include <screens.h>

#define wall_of_text "You decide to take a closer look at the cookie. " \
"I s'pose it makes sense. You likely haven't eaten in days. This *is* a " \
"dictator's prison, after all.\n" \
"\tYou examine the cookie. Or at least, the cookie-shaped object. " \
"Close examination reveals a metallic scent, and it sure doesn't *feel* like " \
"a cookie.\n\n"

#define options "'b' - Break it\n" \
"'e' - Eat it\n" \
"'E' - Take a look elsewhere\n" \
"\n'S' - Save game"

void eat_cookie();
void _options();

void examine_cookie(){
	cls();
	puts(wall_of_text);
	puts(options);
	setSubtitle("Ooh! A cookie!");
	_options();
}

#define wall_of_text2 "You put the cookie in your mouth and attempt to bite it. " \
"\n\nNaturally, you accomplish nothing more than harming your teeth. " \
"Really though, why would you try to bite it? It's made of *metal*!"

void eat_cookie(){
	cls();
	puts(wall_of_text2);
	setSubtitle("No cookie for you :(");
	puts(options);
	_options();
}

void _options(){
	switch (waitInput()) {
		case keyS:
			saveGame();
			break;
		case keyb:
			setScreen(break_cookie);
			break;
		case keye:
			getData()->current_save.current_character.stats.unintelligence++;
			setScreen(eat_cookie);
			break;
		case keyE:
			setScreen(cell);
			break;
	}
}
