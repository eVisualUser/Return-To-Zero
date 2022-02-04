#include "text.h"

void print_fmt_text(char* text, CharStyle cstyle, int x, int y, int wx_mx, int wy_mx)
{
	int array_len = 0;

	for(int i = 0; text[i] != '\0'; i++)
	{
		array_len = i;
	}

	/* PRINTING */

	move_cursor(x, y);

	int log_x = x;
	for(int i = 0; i < array_len; i++)
	{
		switch(text[i])
		{
			case '\0':
				goto ABORT_LOOP;
			case '$':
				x = log_x;
				move_cursor(x, y++);
				break;
			default:
				printch(text[i], cstyle);
				break;
		}
		move_cursor(x++, y);
	}
	ABORT_LOOP:
	log_x++;
}
