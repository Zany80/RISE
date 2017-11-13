#include <input.h>
#include <output.h>
#include <data.h>
#include <screens.h>

#define wall_of_text "You look around and quickly ascertain your location from " \
"your surroundings, hastily preparing an escape plan.\n" \
"\n" \
"Location: some sort of prison cell.\n" \
"\n" \
"Obviously, that is not enough information to figure out an escape " \
"plan, so you look around a bit more and take stock of your " \
"resources.\n" \
"\n" \
"There is the obvious (and cliched) locked door and barred cell. " \
"In the back-right corner, there is a - is that a *cookie*?! " \
"Okaaaaay then. Moving on. Near it, there is a rope, hanging from " \
"the ceiling. Other than that, there is air, which you can't see, " \
"but seeing as you are still breathing you are quite certain it is " \
"there.\n" \
"\n" \
"Select your escape plan:\n" \
"\n" \

#define options "'b' - Bash your head into the wall until your captors " \
"release you\n" \
"'c' - examine the cookie" \
"\n'S' - Save game"

#define wasted_time "After wasting time standing up and sitting down like " \
"some sort of weird chicken human mutant thing, you decide to move on.\n\n"

void cell(){
	cls();
	if (getData()->current_save.misc_data[0]!=0)
		puts(wasted_time);
	puts(wall_of_text);
	puts(options);
	while (1) {
		switch (waitInput()) {
			case keyS:
				setSubtitle("Uh oh! Prison!");
				saveGame();
				return;
			case keyc:
				setScreen(examine_cookie);
				return;
			case keyb:
				setScreen(self_head_bash);
				{
					float f = getData()->current_save.brain_rating;
					f--;
					getData()->current_save.brain_rating;
				}
				return;
		}
	}
}
