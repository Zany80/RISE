#include <input.h>

enum keycode_t pollInput() __naked{
	__asm
	in a, (1)
	ld l, a
	ret
	__endasm;
}

enum keycode_t waitInput(){
	enum keycode_t code;
	while((code=pollInput())==0);
	return code;
}
