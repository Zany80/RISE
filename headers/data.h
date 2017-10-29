#pragma once

#include <screens.h>

typedef struct {
	screen_t current_screen;
	char misc_data[256];
} save_file_t;

typedef struct {
	unsigned char save_flags;
	save_file_t current_save;
	save_file_t save_files[3];
	save_file_t * last_save_file;
} data_t;

data_t *getData();

void initData();
void newGame();
