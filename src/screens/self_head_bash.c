#include <output.h>
#include <input.h>
#include <data.h>
#include <system.h>
#include <screens.h>

#define wall_of_text "You bash your head into the wall. "\
"Your head starts to hurt. What do you do?\n" \
"\n"

#define second_wall "You bash your head into the wall a second time. " \
"*Ow.*\n\n"

#define third_wall "As you bash your head on the wall a third time, " \
"one of the guards takes notice. \"Hey guys!\" he yells, presumably to some " \
"of the other guards. So far so good. \"We have a code 4S in cell Z32!\"\n\n" \
"...does 4S mean \"Let him out?\"\n\n"

#define fourth_wall "As you bash your head against the wall a fourth time, " \
"the wall crumbles. Ohhhh. *That*'s what code 4S is - the 4-strike wall. " \
"Seems that was surprisingly effective! Time to run!\n\n"

#define options "'c' - Continue bashing your head\n" \
"'a' - Admit defeat\n" \
"\n'S' - Save game"


void self_head_bash(){
	const char * texts[] = {wall_of_text,second_wall,third_wall,fourth_wall};
	cls();
	puts(texts[getData()->current_save.misc_data[1]]);
	puts(options);
	switch (waitInput()) {
		case keyS:
			setSubtitle("Headbashing #x. How Dramatic.");
			getData()->current_save.subtitle[strlen("Headbashing #")]=getData()->current_save.misc_data[1]+'1';
			saveGame();
			break;
		case keyc:
			getData()->current_save.current_character.stats.unintelligence += 2.5;
			if (getData()->current_save.misc_data[1]++ == 4){
				setScreen(head_bash_escape);
			}
			break;
	}
}
