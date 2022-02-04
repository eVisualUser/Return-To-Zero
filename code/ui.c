#include "ui.h"

void printch(char ch, CharStyle style)
{
	if(style.bold)
		printf("\033[%dm", TEXT_BOLD);
	if(style.underline)
		printf("\033[%dm", TEXT_UNDERLINE);
	if(style.positive == false)
		printf("\033[%dm", TEXT_NEGATIVE);

	printf("\033[%dm\033[%dm%c\033[0m", style.color, style.bg_color, ch);
}

void print(char* text, CharStyle style)
{

	for(int i = 0; text[i] != '\0'; i++)
	{
		printch(text[i], style);
	}
}

void print_art(char* achar, int x, int y, int fg, int bg)
{
	FILE* fachar;

	fopen_s(&fachar, achar, "r");

	if (fachar == NULL)
	{
		printf("%s not found", achar);
		exit(-1);
	}

	printf("\033[%im\033[%im", fg, bg);

	int buffer_lenght = 255;
	char* buffer = malloc(buffer_lenght);

	int log_x = x;
	while(fgets(buffer, buffer_lenght, fachar) != NULL)
	{
		move_cursor(x, y++);

		for(int i = 0; buffer[i] != '\0'; i++)
		{
			move_cursor(x++, y);
			printf("\b%c", buffer[i]);
		}
	}
	x = log_x;
	
	// Reset console color
	printf("\033[%im\033[%i", COLOR_WHITE_FG, COLOR_BLACK_BG);

	free(buffer);
	fclose(fachar);
}

void print_borders(CharStyle border_cs)
{
	int x = 0;

	// Top Border
	for(int i = 0; i < WINDOW_SIZE_X; i++)
	{
		move_cursor(x, 0);
		printch(' ', border_cs);
		x++;
	}

	x = 0;

	// Bottom Border
	for(int i = 0; i < WINDOW_SIZE_X; i++)
	{
		move_cursor(x, (int)WINDOW_SIZE_Y);
		printch(' ', border_cs);
		x++;
	}
}

void print_button(Button btn, bool select, CharStyle style, int y)
{
	move_cursor((int)(WINDOW_SIZE_X/2-sizeof(btn.text)), y);
	
	if(select)
		style.positive = false;

	print(btn.text, style);
}

int clamp_int(int base, int min, int max)
{
	if(base > max)
		base = max;
	else if (base < min)
		base = min;

	return base;
}

void print_buttons(Button* btn, int count, CharStyle style, int y, int index)
{
	int base = y;
	for(int i = 0; i <= count; i++)
	{
		print_button(btn[i], index == i ? true : false, style, base += 2);
	}
}

Button make_button(char* text, char* action, char* cond)
{
	Button result;

	result.text = text;
	result.action = action;
	result.cond = cond;

	return result;
}
