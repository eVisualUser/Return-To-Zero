#pragma once

#include "player.h"
#include "data.h"

#define INTER_ARG ';'

/* CONDITIONS */
#define COND_NONE "none"
#define COND_DOC "doc"
#define COND_ENG "eng"
#define COND_GEO "geo"

#include <stdbool.h>
#include <malloc.h>
#include <string.h>

// Execute a command
// Called at the end of the loop, if the OK button is pressed
void execute_cmd(char* cmd, Page* page);

// Return true if the condition is valid
// Called at the button creation
bool test_cond(char* cond, Player player);

// Seperate each args into an array
char** extract_args(char* cmd, int* count);

// Return a char* resized
char* str_crop(char* base);

// Return true if two char* is equal until a '\0' is find
bool str_match(char* a, char* b);

// Set the next page load by the games
void goto_cmd(char* cmd, Page* page);
