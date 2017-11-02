#include <output.h>
#include <system.h>
#include <screens.h>
#include <data.h>

void _sdcc_call_hl() __naked{
	__asm
	push hl
	ret
	__endasm;
}

void main() {
	__asm__("ld sp, 0xB000");
	setScreen(0);
	if(swapBanks(255,3)==1){
		puts("Failed to swap in persistent memory! Save games will not function!\nRight click anywhere to continue...");
		halt();
	}
	if ( ( (getData()->save_flags) & 0x01 ) != 0x01){
		initData();
	}
	setScreen(main_menu);
	while (1) {
		getCurrentScreen()();
	}
}
