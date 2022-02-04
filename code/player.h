#pragma once

typedef enum {
	Doctor,
	Enginer,
	Geologist,
} Speciality;

typedef struct {
	Speciality job;

} Player;

Player create_player();
