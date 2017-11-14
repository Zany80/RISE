#include <output.h>
#include <input.h>
#include <data.h>

#define wall_of_text "Clearly, the construction crew that built this prison " \
"cut a few corners - they must have used inferior building materials, which " \
"made your escape possible.\n\n" \
"Time to get out of here!\n\n"

#define options "'t' - time to leave\n" \
"\n'S' - Save game"

void head_bash_escape(){
	cls();
	puts(wall_of_text);
	puts(options);
	switch (waitInput()) {
		case keyS:
			setSubtitle("Would never work in real life");
			saveGame();
	}
}
