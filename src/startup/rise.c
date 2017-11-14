#include <output.h>
#include <system.h>
#include <screens.h>
#include <data.h>

void main() {
	__asm__("ld sp, 0xB000");
	if (swapBanks(255,3) == 1) {
		puts("Failed to swap in persistent memory! Save games will not function!\nRight click anywhere to continue...");
		halt();
	}
	if ( ( (getData()->save_flags) & 0x01 ) != 0x01) {
		initData();
	}
	setScreen(main_menu);
	while (1) {
		getCurrentScreen()();
	}
}

char *title() __naked{
	__asm
	.asciiz "RISE"
	__endasm;
}
