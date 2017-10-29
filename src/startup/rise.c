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
	__asm__("ld sp, 0xF000");
	if ( ( (getData()->save_flags) & 0x01 ) != 0x01){
		initData();
	}
	main_menu();
	while (1) {
		getCurrentScreen()();
	}
}
