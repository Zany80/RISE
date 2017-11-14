#pragma once

#include <array.h>

typedef struct {
	char name[32];
	// index in array
	char stat;
	float bonus;
} bonus_t ;

typedef struct {
	char name[32];
	sprite_t sprite;
	char atk;
	char dmg;
	array_t bonuses;
} weapon_t;
