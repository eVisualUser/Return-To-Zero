#pragma once

#include "data.h"

typedef enum {
	Doctor,
	Engineer,
	Geologist,
} Speciality;

typedef struct {
	Speciality job;

	// Stats
	int food;
	int weight;
	int speed;
	int social;

	// Tools
	int syringe;
	int grapple_hook;
	int pickaxe;
	int carbon_boots;
	int flare;
	int spanner;
	int book;

	// Logs
	bool son_saved;

} Player;

Player create_player();
