#include "main.h"

// Write with "Sublime Text".
// Tabulation size set as 4.

int main(int argc, char** argv) {

	if(argc > 1)
		return EXIT_SUCCESS;

	Uconfig ucfg; // Store inputs configuration

	Uinput uip; // Store a boolean for each input (ok, exit, up, down)

	set_uconfig_from_file(&ucfg, "input\0");

	/* Game Loop */

	CharStyle title_style;
	title_style.bold = true;
	title_style.underline = false;
	title_style.color = COLOR_WHITE_FG;
	title_style.bg_color = COLOR_RED_BG;
	title_style.positive = true;

	CharStyle page_title_style;
	page_title_style.bold = true;
	page_title_style.underline = true;
	page_title_style.color = COLOR_WHITE_FG;
	page_title_style.bg_color = COLOR_BLACK_BG;
	page_title_style.positive = true;

	CharStyle page_text_style;
	page_text_style.bold = false;
	page_text_style.underline = false;
	page_text_style.color = COLOR_GREEN_FG;
	page_text_style.bg_color = COLOR_BLACK_BG;
	page_text_style.positive = true;

	CharStyle input_style;
	input_style.bold = true;
	input_style.underline = false;
	input_style.color = COLOR_LIGHT_MAGENTA_FG;
	input_style.bg_color = COLOR_BLACK_BG;
	input_style.positive = true;

	Player player;
	player.job = Doctor;

	#if BUTTONS
		long excepted_buttons = 0;
		long button_index = 0;
	#endif // BUTTONS

	Page page = create_page();
	load_page_toml(&page, str_crop(get_first_page()));

	/* BUTTON TEST */

	while(uip.exit == false)
	{
		/* Update */

		#if BUTTONS
		Button* btns = malloc(sizeof(Button)*(page.btns_count+1));
		#endif // BUTTONS		

		#if BUTTONS
		if(uip.up)
			button_index--;
		else if (uip.down)
			button_index++;

		button_index = clamp_int(button_index, 0, page.btns_count-excepted_buttons);
		#endif // BUTTONS
		/* PRINT */
		system("cls");

		// Print Inputs
		#if AINPUTS

		char* text_input_up = malloc(10);
		sprintf(text_input_up, "UP %c", ucfg.up);
		char* text_input_down = malloc(10);
		sprintf(text_input_down, "Down %c", ucfg.down);
		char* text_input_ok = malloc(10);
		sprintf(text_input_ok, "OK %c", ucfg.ok);

		move_cursor(0, 2);
		print(text_input_up, input_style);
		move_cursor(0, 3);
		print(text_input_down, input_style);
		move_cursor(0, 4);
		print(text_input_ok, input_style);

		free(text_input_up);
		free(text_input_down);
		free(text_input_ok);

		#endif // ATEXT

		// Border
		print_borders(title_style);

		#if ATITLE
		// Title
		move_cursor((int)(WINDOW_SIZE_X/2-sizeof("Return To Zero\0")/2), 0);
		print("Return To Zero\0", title_style);
		#endif // ATITLE

		#if BUTTONS
		// Buttons
		// Convert PageButton to Button
		// Apply The Condition
		excepted_buttons = 0;
		for(int i = 0; i <= page.btns_count; i++)
		{
			if(test_cond(page.btns[i].condition, player))
			{
				btns[i] = make_button(page.btns[i].text, page.btns[i].action, page.btns[i].condition);
			}
			else
				excepted_buttons++;
		}
		
		print_buttons(btns, page.btns_count-excepted_buttons, title_style, 20, button_index);
		#endif // BUTTONS

		#if ATEXT
		// Exit Text
		move_cursor(WINDOW_SIZE_X/2, WINDOW_SIZE_Y);
		char* exit_btn_text_buffer = malloc(250);
		sprintf(exit_btn_text_buffer, "[%c] Exit", ucfg.exit);
		print(exit_btn_text_buffer, title_style);
		free(exit_btn_text_buffer);
		#endif // ATEXT

		#if ATITLE
		// Page Title
		move_cursor((int)WINDOW_SIZE_X/2-(int)sizeof(page.title)/2, 10);
		print(page.title, page_title_style);
		#endif // ATITLE

		#if ATEXT
		// Page Text
		print_fmt_text(page.text, page_text_style, WINDOW_SIZE_X/3-(int)sizeof(page.text)/2, WINDOW_SIZE_Y/4, WINDOW_SIZE_X, WINDOW_SIZE_Y);
		#endif // ATEXT

		/* INPUT */
		reset_user_buffer(&uip);
		set_uconfig_from_file(&ucfg, "input\0");
		update_user_buffer(&uip, &ucfg);

		// When a button is activated
		if(uip.ok)
		{
			int args_count = 0;
			char** extracted_args = extract_args(btns[button_index].action, &args_count);

			for(int i = 0; i <= args_count; i++)
			{
				printf("%s", extracted_args[i]);
				execute_cmd(extracted_args[i], &page);
			}
		}
	}

	return EXIT_SUCCESS;
}
