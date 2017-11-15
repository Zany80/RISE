#include <data.h>
#include <screens.h>

const char *wall_of_text = "You wake up with a pounding headache. \"Where - where am I?\" you mutter, slowly becoming more alert.";
//#define wall_of_text 
#define layagain " You lay back down, grasping your head in pain."
#define nootherreason " There's obviously no other reason for you to sit back down, so that must be it."
#define reallyman " ...really? Really? Was this *really* necessary? Stop fooling around!"
#define options "\n\ns' - Stand up\n'S' - Save"

void awaken(){
	char i = getData()->current_save.misc_data[0];
	cls();
	if (i >= 1) {
		puts(layagain);
	}
	else {
		puts(wall_of_text);
	}
	if (i >= 2) {
		puts(nootherreason);
	}
	if (i ==3) {
		puts(reallyman);
	}
	puts(options);
	switch (waitInput()) {
		case keys:
			setScreen(to_your_feet);
			break;
		case keyS:
			// Call up the save menu
			saveGame();
			break;
	}
}
