#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>

#include "toml.h"

#ifdef _WIN32
	#include <windows.h>
#elif _WIN64
	#include <conio.h>
#else
	#include <unistd.h>
#endif

#define PAGE_TITLE_LEN 100
#define PAGE_TEXT_LEN 250

#define move_cursor(x,y) printf("\033[%d;%dH", (y), (x))

typedef struct {
	char* text;
	char* action;
	char* condition;
} PageButton;

typedef struct {
	bool right;
	bool left;
	bool up;
	bool down;
	bool ok;
	bool cancel;
	bool save;
	bool exit;
} Uinput; // User Input Activated

typedef struct {
	char right;
	char left;
	char up;
	char down;
	char ok;
	char cancel;
	char save;
	char exit;
} Uconfig; // User Input Keys

// Contain all data of a page.
typedef struct {
	// Info
	char* title;
	char* text;
	PageButton* btns;
	int btns_count;
} Page;

// Get a field in a csv line
const char* getfield(char* line, int num);

// Use a .toml file to contain page info
void load_page_toml(Page* page, char* file);

// Read the index.csv to get the first page defined
char* get_first_page();

// init a page struct
Page create_page();

void free_page(Page* page);

// Check the user inputs
void update_user_buffer(Uinput* uip, Uconfig* ucfg);

// Use for the nex game loop iteration
void reset_user_buffer(Uinput* uip);

// Setup the key's from a file
void set_uconfig_from_file(Uconfig* ucfg, char* file);

// Read /pages/index.csv and 
char* get_page_by_id(char id[3]);

// Return a char* resized
char* cropper(char* base);

// Return a bool is a number between 0 and base is generated.
bool luck(int base);