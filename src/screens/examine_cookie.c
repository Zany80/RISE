#include <output.h>
#include <input.h>
#include <data.h>

#define wall_of_text "You decide to take a closer look at the cookie. " \
"I s'pose it makes sense. You likely haven't eaten in days. This *is* a " \
"dictator's prison, after all.\n" \
"\tYou examine the cookie. Or at least, the cookie-shaped object. " \
"Close examination reveals a metallic scent, and it sure doesn't *feel* like " \
"a cookie.\n\n"

#define options "\n\n'S' - Save game"

void examine_cookie(){
	cls();
	puts(wall_of_text);
	puts(options);
	switch (waitInput()) {
		case keyS:
			saveGame();
			break;
	}
}
