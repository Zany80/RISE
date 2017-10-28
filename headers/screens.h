#pragma once

typedef void (*screen)();
screen getCurrentScreen();
void setScreen(screen s);

void main_menu();
void new_game();
