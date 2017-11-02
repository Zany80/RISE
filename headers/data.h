#pragma once

#include <screens.h>

typedef struct {
	screen_t current_screen;
	char misc_data[256];
	char title[32];
	char subtitle[32];
} save_file_t;

typedef struct {
	unsigned char save_flags;
	save_file_t current_save;
	save_file_t save_files[3];
	char last_save_file;
} data_t;

data_t *getData();

void initData();
void newGame();
void loadGame();

void initFile(save_file_t *save_file);
void save(save_file_t *save_file);

void setTitle(const char *title);
void setSubtitle(const char *subtitle);
