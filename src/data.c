#include <data.h>
#include <output.h>
#include <screens.h>

data_t * getData(){
	return (data_t*)0xF000;
}

void initData(){
	data_t *data=getData();
	puts("First run");
	data->save_flags |= 0x04;
	setScreen(main_menu);
}
