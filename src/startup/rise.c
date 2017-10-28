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
	if((getData()->save_flags&0x04)!=0x04){
		initData();
	}	
	while (1) {
		getCurrentScreen()();
	}
}
