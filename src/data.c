#include <data.h>
#include <output.h>
#include <input.h>
#include <system.h>
#include <screens.h>
#include <sprites.h>

data_t * getData(){
	return (data_t*)0xF000;
}

void newGame(){
	data_t *data = getData();
	setScreen(select_file);
}

void select_file(){
	cls();
	{
		data_t *data = getData();
		unsigned char save_file=0;
		puts("Select file: \n\nFile 1: ");
		puts(((data->save_flags&0x02)==0x02)?"Used":"Free");
		puts("\nFile 2: ");
		puts(((data->save_flags&0x04)==0x04)?"Used":"Free");
		puts("\nFile 3: ");
		puts(((data->save_flags&0x08)==0x08)?"Used":"Free");
		puts("\n\n(Press 1-3 on the keyboard)\n\n");
		while (save_file == 0){
			keycode_t keycode = waitInput();
			switch (keycode){
				case key1:
					save_file=1;
					break;
				case key2:
					save_file=2;
					break;
				case key3:
					save_file=3;
					break;
				default:
					break;
			}
		}
		{
			while(1);
		}
	}
}

void initData(){
	data_t *data=getData();
	data->save_flags |= 0x01;
	data->last_save_file=0;
}
