#pragma once

typedef void (*screen_t)();
screen_t getCurrentScreen();
void setScreen(screen_t s);

void main_menu();
void select_file();
void intro_screen();
void awaken();
void to_your_feet();
void cell();
void examine_cookie();
void break_cookie();
void self_head_bash();
void head_bash_escape();
