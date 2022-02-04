#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define COLOR_BLACK_FG 30
#define COLOR_BLACK_BG 40
#define COLOR_RED_FG 31
#define COLOR_RED_BG 41
#define COLOR_GREEN_FG 32
#define COLOR_GREEN_BG 42
#define COLOR_YELLOW_FG 33
#define COLOR_YELLOW_BG 43
#define COLOR_BLUE_FG 34
#define COLOR_BLUE_BG 44
#define COLOR_MAGENTA_FG 35
#define COLOR_MAGENTA_BG 45
#define COLOR_CYAN_FG 36
#define COLOR_CYAN_BG 46
#define COLOR_LIGHT_GRAY_FG 37
#define COLOR_LIGHT_GRAY_BG 47
#define COLOR_DARK_GRAY_FG 90
#define COLOR_DARK_GRAY_BG 100
#define COLOR_LIGHT_RED_FG 91
#define COLOR_LIGHT_RED_BG 101
#define COLOR_LIGHT_GREEN_FG 92
#define COLOR_LIGHT_GREEN_BG 102
#define COLOR_LIGHT_YELLOW_FG 93
#define COLOR_LIGHT_YELLOW_BG 103
#define COLOR_LIGHT_BLUE_FG 94
#define COLOR_LIGHT_BLUE_BG 104
#define COLOR_LIGHT_MAGENTA_FG 95
#define COLOR_LIGHT_MAGENTA_BG 105
#define COLOR_LIGHT_CYAN_FG 96
#define COLOR_LIGHT_CYAN_BG 106
#define COLOR_WHITE_FG 97
#define COLOR_WHITE_BG 107

#define TEXT_BOLD 1
#define TEXT_UNDERLINE 4
#define TEXT_NO_UNDERLINE 24 
#define TEXT_NEGATIVE 7
#define TEXT_POSITIVE 27
#define TEXT_DEFAULT 0

#define IO_CHAR_SIZE 100

#define WINDOW_SIZE_X 100
#define WINDOW_SIZE_Y 50

#define move_cursor(x,y) printf("\033[%d;%dH", (y), (x))

typedef struct {
	bool bold;
	bool underline;
	bool positive;
	int color;
	int bg_color;
} CharStyle;

typedef struct {
	CharStyle style;
	char value;
} ExtraChar;

typedef struct {
	char* text;
	char* action;
	char* cond;
} Button;

void print_borders(CharStyle border_cs);

void printch(char ch, CharStyle style);
void print(char* text, CharStyle style);

void print_art(char* achar, int x, int y, int fg, int bg);

int clamp_int(int base, int min, int max);

void print_button(Button btn, bool select, CharStyle style, int y);

void print_buttons(Button* btn, int count, CharStyle style, int y, int index);

Button make_button(char* text, char* action, char* cond);
