#include <system.h>
#include <output.h>
#include <input.h>
#include <data.h>

#define wall_of_text "The year is 1394. For years, the dark prince Algar has ruled the country of Vlarzel" \
" with an iron fist. Now, people are starting to " \
 "fight back.\n" \
 "\n" \
 "Your job as the player is to maintain a network of informants, " \
 "plan out battles, and overthrow him.\n" \
 "\n" \
 "Unlike in most games, you don't control one character, or even a " \
 "group of characters. You alternate between many different people " \
 "with the job of coordinating them.\n" \
 "\n" \
 "However, there *are* still traditional RPG elements - exploring, " \
 "fighting, character classes, levelling up - but the characters " \
 "are premade, and each one has their own \"feel\".\n" \
 "\n" \
 "Good luck.\n\n'b' - Begin"

void _intro_screen(){
	switch(waitInput()){
		case keyb:
			setSubtitle("Awaken");
			setScreen(awaken);
			break;
	}
}

void intro_screen(){
	cls();
	puts(wall_of_text);
	setScreen(_intro_screen);
}
