#include <data.h>
#include <output.h>
#include <screens.h>

data_t * getData() __naked{
	__asm
	ld hl, 0xF000
	ret
	__endasm;
}

void initData(){
	data_t *data=getData();
	puts("First run");
	data->save_flags |= 0x04;
	data->current_screen=main_menu;
}
