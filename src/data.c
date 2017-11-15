#include <data.h>
#include <output.h>
#include <input.h>
#include <system.h>
#include <screens.h>
#include <sprites.h>

data_t * getData(){
	//ensure pmem is activated
	if (swapBanks(255,3) == 1) {
		puts("Uh oh");
		halt();
	}
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
}

void newGame(){
	char i=0;
	data_t *data=getData();
	fileInfo();
	puts("\n'm' - back to Main Menu\n");
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
	puts("\n'm' - back to Main Menu\n");
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

void saveGame() {
	char i;
	data_t *data=getData();
	fileInfo();
	puts("\n'b' - back\n");
	i=0;
	while(i==0){
		switch(i=waitInput()){
			case key1:
			case key2:
			case key3:
				break;
			case keyb:
			case keyB:
				return;
			default:
				i=0;
				break;
		}
	}
	if (data->save_flags&(1<<i)){
		puts("Are you sure you want to overwrite file ");
		putch(i+'0');
		puts("? ('y'/'n') n\n");
		while (1) {
			switch (waitInput()) {
				case keyy:
				case keyY:
					save(&data->save_files[i-1]);
					return;
				case keyn:
				case keyN:
					return;
			}
		}
	}
	else{
		save(&data->save_files[i-1]);
		data->save_flags |= (1<<i);
	}
}

void save(save_file_t *file){
	save_file_t *current=&getData()->current_save;
	file->current_screen=current->current_screen;
	strcpy(file->title,current->title);
	strcpy(file->subtitle,current->subtitle);
	memcpy(file->misc_data,current->misc_data,3*1024);
	memcpy((char*)&file->current_character,(char*)&current->current_character,sizeof(character_t));
}

void load(save_file_t *file){
	save_file_t * current=&(getData()->current_save);
	current->current_screen=file->current_screen;
	memcpy(current->misc_data,file->misc_data,3*1024);
	strcpy(current->title,file->title);
	strcpy(current->subtitle,file->subtitle);
	memcpy((char*)&current->current_character,(char*)&file->current_character,sizeof(character_t));
}

void initFile(save_file_t *file){
	int i;
	save_file_t *current=&(getData()->current_save);
	strcpy(current->title,"Introduction");
	strcpy(current->subtitle,"The Dark Prince");
	current->current_screen=intro_screen;
	for (i = 0; i != 1024; i++) {
		current->misc_data[i] = 0;
	}
	strcpy(current->adaer_lerauk.name,"Adaer Lerauk");
	current->adaer_lerauk.sprite.size = 0;
	current->adaer_lerauk.stats.agility = 7;
	current->adaer_lerauk.stats.endurance = 4.6;
	current->adaer_lerauk.stats.listen = -3;
	current->adaer_lerauk.stats.pain_tolerance = 3.2;
	current->adaer_lerauk.stats.silence = 3;
	current->adaer_lerauk.stats.sneak = 4;
	current->adaer_lerauk.stats.spot = 8;
	current->adaer_lerauk.stats.strength = 1;
	current->adaer_lerauk.stats.unintelligence = -2;
	memcpy((char*)&current->current_character,(char*)&current->adaer_lerauk,sizeof(character_t));
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
