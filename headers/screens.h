#pragma once

typedef void (*screen_t)();
screen_t getCurrentScreen();
void setScreen(screen_t s);

void main_menu();
void select_file();
void intro_screen();
void awaken();
