#include <screens.h>
#include <data.h>

void main() {
	__asm__("ld sp, 0xB000");
	if ( ( (getData()->save_flags) & 0x01 ) != 0x01) {
		initData();
	}
	setScreen(main_menu);
	while (true) {
		getCurrentScreen()();
	}
}

char *title() __naked{
	__asm
	.asciiz "RISE"
	__endasm;
}
