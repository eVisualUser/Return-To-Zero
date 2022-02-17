#include "main.h"

// Write with "Sublime Text".
// Tabulation size set as 4.

int main(int argc, char** argv) {

	if(argc > 1)
		return EXIT_SUCCESS;

	Uconfig ucfg; // Store inputs configuration

	Uinput uip; // Store a boolean for each input (ok, exit, up, down)

	/* Game Loop */

	CharStyle title_style;
	title_style.bold = true;
	title_style.underline = false;
	title_style.color = COLOR_WHITE_FG;
	title_style.bg_color = COLOR_RED_BG;
	title_style.positive = true;

	CharStyle title_style_active;
	title_style_active.bold = true;
	title_style_active.underline = false;
	title_style_active.color = COLOR_YELLOW_FG;
	title_style_active.bg_color = COLOR_RED_BG;
	title_style_active.positive = true;

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

	Player player;

	#if BUTTONS
		long button_index = 0;
	#endif // BUTTONS

	Page page = create_page();
	load_page_toml(&page, str_crop(get_first_page()));

	/* BUTTON TEST */

	while(uip.exit == false)
	{
		/* Update */

		int luck_val = gen_new_luck();	

		#if BUTTONS
		if(uip.up)
			button_index--;
		else if (uip.down)
			button_index++;

		#endif // BUTTONS
		/* PRINT */
		#ifdef _WIN32
			system("cls");
		#elif
			system("cls");
		#else
			system("clear");
		#endif

		// Border
		print_borders(title_style);

		// Print Inputs
		#if AINPUTS

		move_cursor(0, WINDOW_SIZE_Y);
		print("[Up]", uip.up ? title_style_active : title_style);
		move_cursor(5, WINDOW_SIZE_Y);
		print("[Down]", uip.down ? title_style_active : title_style);
		move_cursor(11, WINDOW_SIZE_Y);
		print("[Ok]", uip.ok ? title_style_active : title_style);

		#endif // ATEXT

		#if ATITLE
		// Title
		move_cursor((int)(WINDOW_SIZE_X/2-sizeof("Return To Zero\0")/2), 0);
		print("Return To Zero\0", title_style);
		#endif // ATITLE

		#if BUTTONS
		// Buttons
		// Convert PageButton to Button
		// Apply The Condition
		int page_btn_count = page.btns_count;
		int real_btn_count = 0;

		for(int i = 0; i <= page_btn_count; i++)
		{
			if(test_cond(page.btns[i].condition, player, luck_val))
			{
				real_btn_count++;
			}
		}

		Button* btns = malloc(sizeof(Button)*(real_btn_count+1));

		int loaded_btns = 0;
		for(int i = 0; i <= page_btn_count; i++)
		{
			if(test_cond(page.btns[i].condition, player, luck_val))
			{
				btns[loaded_btns] = make_button(page.btns[i].text, page.btns[i].action, page.btns[i].condition);
				loaded_btns++;
			}
		}


		button_index = clamp_int(button_index, 0, real_btn_count-1);

		print_buttons(btns, real_btn_count-1, title_style, WINDOW_SIZE_Y/2.5, button_index);
		#endif // BUTTONS
		
		#if ATITLE
		// Page Title
		move_cursor((int)WINDOW_SIZE_X/2-(int)sizeof(page.title)/2, WINDOW_SIZE_Y/10);
		print(page.title, page_title_style);
		#endif // ATITLE
		
		#if ATEXT
		// Page Text
		print_fmt_text(page.text, page_text_style, WINDOW_SIZE_X/2-(int)sizeof(page.text)*2, WINDOW_SIZE_Y/7, WINDOW_SIZE_X, WINDOW_SIZE_Y);
		#endif // ATEXT

		/* INPUT */
		reset_user_buffer(&uip);
		update_user_buffer(&uip, &ucfg);

		// When a button is activated
		if(uip.ok)
		{
			execute_cmd(btns[button_index].action, &page, &player);
		}

	}

	return EXIT_SUCCESS;
}
