#include <data.h>
#include <output.h>
#include <input.h>
#include <system.h>
#include <screens.h>
#include <sprites.h>

data_t * getData(){
	return (data_t*)0xF000;
}

void fileInfo(){
	data_t *data=getData();
	char i;
	cls();
	puts("Select a file: \n\n");
	for(i=1;i<4;i++){
		puts("File ");
		putch(i+'0');
		puts(": ");
		if((data->save_flags&1<<i)==1<<i){
			puts(data->save_files[i-1].title);
			puts("\n\t");
			puts(data->save_files[i-1].subtitle);
			putch('\n');
		}
		else{
			puts("Free\n");
		}
	}
	puts("\n'm' - back to Main Menu\n");
}

void newGame(){
	char i=0;
	data_t *data=getData();
	fileInfo();
	while(i==0){
		switch(i=waitInput()){
			case key1:
			case key2:
			case key3:
				break;
			case keym:
				setScreen(main_menu);
				return;
			default:
				i=0;
				break;
		}
	}
	if (data->save_flags&(1<<i)){
		puts("File already in use!\n\nClear? (y/n)");
		while(1){
			switch(waitInput()){
				case keyn:
					return;
				case keyy:
					initFile(&data->save_files[i-1]);
					return;
			}
		}
	}
	else{
		initFile(&data->current_save);
		save(&data->save_files[i-1]);
		data->save_flags |= (1<<i);
	}
}

void load(save_file_t *s);

void loadGame(){
	char i;
	data_t *data=getData();
	fileInfo();
	i=0;
	while(i==0){
		switch(i=waitInput()){
			case key1:
			case key2:
			case key3:
				break;
			case keym:
				setScreen(main_menu);
				return;
			default:
				i=0;
				break;
		}
	}
	if (data->save_flags&(1<<i)){
		puts("Loading file ");
		putch(i+'0');
		puts("...\n\n");
		load(&data->save_files[i-1]);
	}
	else{
		initFile(&data->current_save);
		save(&data->save_files[i-1]);
		data->save_flags |= (1<<i);
	}
}

void save(save_file_t *file){
	save_file_t *current=&getData()->current_save;
	file->current_screen=current->current_screen;
	strcpy(file->title,current->title);
	strcpy(file->subtitle,current->subtitle);
}

void load(save_file_t *file){
	getData()->current_save.current_screen=file->current_screen;
}

void initFile(save_file_t *file){
	data_t *data=getData();
	strcpy(data->current_save.title,"Introduction");
	strcpy(data->current_save.subtitle,"The Dark Prince");
	data->current_save.current_screen=intro_screen;
	save(file);
}

void initData(){
	data_t *data=getData();
	data->save_flags |= 0x01;
	data->last_save_file=0;
}

void setTitle(const char *title){
	strcpy(getData()->current_save.title,title);
}

void setSubtitle(const char *subtitle){
	strcpy(getData()->current_save.subtitle,subtitle);
}
