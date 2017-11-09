#include <output.h>
#include <data.h>
#include <input.h>
#include <screens.h>

#define main_string "You rise to your feet, leaning against a nearby wall.\n\n"

#define wall_of_text "As you get up, memories rush back in to your skull. Your name is " \
"Adaer Lerauk, and you are a \"covert operative\". You " \
"work for RISE (RISE! Imperialism Shall End!), a group dedicated to " \
"overthrowing the dark prince Algar and creating peace in Varzhul.\n\n" \
"Your current mission is to steal a copy of the battle plans for " \
"the upcoming battle between the forces of RISE and FALL (FALL! " \
"Annihilate Loathsome Lawless!) in the Vale of Larhultz. Clearly " \
"that mission didn't go as planned, though you can't quite " \
"remember what happened. What you *do* know is that you have to " \
"escape and complete your mission - or everyone you care about " \
"will pay the price...\n\n"

#define options "'l' - Lay back down\n'o' - lOok around\n'S' - Save"

#define nothappening "\nYeah, no. I don't have time to write up an amusing " \
"scenario for all however many times you want to do that.\n" \
"Sorry, not sorry.\n"

void to_your_feet() {
	char *save_data = getData()->current_save.misc_data;
	cls();
	puts(main_string);
	if (save_data[0]==0) {
		puts(wall_of_text);
	}
	puts(options);
	while (1) {
		switch (waitInput()) {
			case keyS:
				setSubtitle("To your feet!");
				saveGame();
				return;
			case keyl:
				if (save_data[0]>=3) {
					puts(nothappening);
				}
				else {
					setScreen(awaken);
					save_data[0]++;
					return;
				}
		}
	};
}
