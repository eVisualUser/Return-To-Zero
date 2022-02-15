#pragma once

#include "data.h"

typedef enum {
	Doctor=0,
	Mechanician=1,
	Geologist=2,
} Spec;

typedef struct {
	int job;

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
