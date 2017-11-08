#include <output.h>
#include <input.h>

#define wall_of_text "You wake up with a pounding headache. \"Where - where am I?\" you mutter, slowly becoming more alert."
#define layagain " You lay back down, grasping your head in pain."
#define nootherreason " There's obviously no other reason for you to sit back down, so that must be it."
#define reallyman " ...really? Really? Was this *really* necessary? Stop fooling around!"
#define options "s' - Stand up\n'S' - Save"

void awaken(){
	cls();
	puts(wall_of_text);
	puts(options);
	switch(waitInput()){
		case keyS:

			break;
		case keys:
			
			break;
	}
}
