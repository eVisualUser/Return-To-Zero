#include "player.h"

Player create_player()
{
	Player result;
	result.job = Doctor;

	// Stats
	result.food = 0;
	result.weight = 0;
	result.speed = 0;
	result.social = 0;

	// Tools
	result.syringe = 0;
	result.grapple_hook = 0;
	result.pickaxe = 0;
	result.carbon_boots = 0;
	result.flare = 0;
	result.spanner = 0;
	result.book = 0;

	// Logs
	result.son_saved = false;

	return result;
}
