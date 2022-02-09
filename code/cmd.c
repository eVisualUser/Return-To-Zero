#include "cmd.h"

int gen_new_luck()
{
	return rand() % 6 + 1;
}

void execute_cmd(char* cmd, Page* page, Player* player)
{
	if(str_match(str_crop(cmd), "debug"))
		printf("DEBUG\n");
	else if(cmd[0] == 'g' && cmd[1] == 'o' && cmd[2] == 't' && cmd[3] == 'o')
	{
		goto_cmd(cmd, page);
	}
	else if (str_match(str_crop(cmd), "quit"))
	{
		exit(0);
	}
	else if(str_match(str_crop(cmd), "start"))
	{
		load_page_toml(page, get_first_page());
	}
	else if(str_match(str_crop(cmd), "doc"))
	{
		player->job = Doctor;
	}
	else if(str_match(str_crop(cmd), "eng"))
	{
		player->job = Engineer;
	}
	else if(str_match(str_crop(cmd), "geo"))
	{
		player->job = Geologist;
	}
	else if(str_match(str_crop(cmd), "+food"))
	{
		player->food++;
	}
	else if(str_match(str_crop(cmd), "-food"))
	{
		player->food--;
	}
	else if(str_match(str_crop(cmd), "+weight"))
	{
		player->weight++;
	}
	else if(str_match(str_crop(cmd), "-weight"))
	{
		player->weight--;
	}
	else if(str_match(str_crop(cmd), "-speed"))
	{
		player->speed--;
	}
	else if(str_match(str_crop(cmd), "+social"))
	{
		player->social++;
	}
	else if(str_match(str_crop(cmd), "-social"))
	{
		player->social--;
	}
	else if(str_match(str_crop(cmd), "+syringe"))
	{
		player->syringe++;
	}
	else if(str_match(str_crop(cmd), "-syringe"))
	{
		player->syringe--;
	}
	else if(str_match(str_crop(cmd), "+spanner"))
	{
		player->spanner++;
	}
	else if(str_match(str_crop(cmd), "-spanner"))
	{
		player->spanner--;
	}
	else if(str_match(str_crop(cmd), "+book"))
	{
		player->book++;
	}
	else if(str_match(str_crop(cmd), "-book"))
	{
		player->book--;
	}
}

bool test_cond(char* cond, Player player, int luck)
{
	char* ccond = str_crop(cond);

	int count = 0;
	char** args = extract_args(ccond, &count);
	for(int i = 0; i <= count; i++)
	{
		if(str_match(args[i], COND_NONE)) return true;
		if(str_match(args[i], COND_DOC)) 
		{
			if(player.job == Doctor) return true;
			else return false;
		}
		else if(str_match(args[i], COND_ENG)) 
		{
			if(player.job == Engineer) return true;
			else return false;
		}
		else if(str_match(args[i], COND_GEO)) 
		{
			if(player.job == Geologist) return true;
			else return false;
		}
		else if(str_match(args[i], "luck_high"))
		{
			if (luck >= 5)
				return false;
		}
		else if(str_match(args[i], "luck_med"))
		{
			if (luck >= 3)
				return false;
		}
		else if (str_match(args[i], "luck_low"))
		{
			if (luck >= 2)
				return false;
		}
		else if (str_match(args[i], "!luck_high"))
		{
			if (luck <= 5)
				return false;
		}
		else if (str_match(args[i], "!luck_med"))
		{
			if (luck <= 3)
				return false;
		}
		else if (str_match(args[i], "!luck_low"))
		{
			if (luck <= 2)
				return false;
		}
		else if (str_match(args[i], "food"))
		{
			if (player.food > 0)
				return false;
		}
		else if (str_match(args[i], "!food"))
		{
			if (player.food == 0)
				return false;
		}
		else if (str_match(args[i], "weight"))
		{
			if (player.weight > 0)
				return false;
		}
		else if (str_match(args[i], "!weight"))
		{
			if(player.weight == 0)
				return false;
		}
		else if (str_match(args[i], "speed"))
		{
			if(player.speed > 0)
				return false;
		}
		else if (str_match(args[i], "!speed"))
		{
			if(player.speed == 0)
				return false;
		}
		else if (str_match(args[i], "social"))
		{
			if(player.weight > 0)
				return false;
		}
		else if (str_match(args[i], "!social"))
		{
			if(player.social == 0)
				return false;
		}
		else if (str_match(args[i], "syringe"))
		{
			if(player.syringe > 0)
				return false;
		}
		else if (str_match(args[i], "!syringe"))
		{
			if(player.syringe == 0)
				return false;
		}
		else if (str_match(args[i], "grapple_hook"))
		{
			if(player.grapple_hook > 0)
				return false;
		}
		else if (str_match(args[i], "!grapple_hook"))
		{
			if(player.grapple_hook == 0)
				return false;
		}
		else if (str_match(args[i], "pickaxe"))
		{
			if(player.pickaxe > 0)
				return false;
		}
		else if (str_match(args[i], "!pickaxe"))
		{
			if(player.pickaxe == 0)
				return false;
		}
		else if (str_match(args[i], "carbon_boots"))
		{
			if(player.carbon_boots == 0)
				return false;
		}
		else if (str_match(args[i], "!carbon_boots"))
		{
			if(player.carbon_boots == 0)
				return false;
		}
		else if (str_match(args[i], "flare"))
		{
			if(player.flare > 0)
				return false;
		}
		else if (str_match(args[i], "!flare"))
		{
			if(player.flare == 0)
				return false;
		}
		else if (str_match(args[i], "spanner"))
		{
			if(player.spanner > 0)
				return false;
		}
		else if (str_match(args[i], "!spanner"))
		{
			if(player.spanner == 0)
				return false;
		}
		else if (str_match(args[i], "book"))
		{
			if(player.book > 0)
				return false;
		}
		else if (str_match(args[i], "!book"))
		{
			if(player.book == 0)
				return false;
		}
	}
	return true;
}

char** extract_args(char* cmd, int* count)
{
	char** result = malloc(10*10);
	
	char* buffer = malloc(100);
	int buffer_idx = 0;
	int result_idx = 0;
	for(int i = 0; cmd[i] != '\0'; i++)
	{
		if(cmd[i] != ';')
		{
			buffer[buffer_idx] = cmd[i];
			buffer_idx++;
		} else if(cmd[i] != '\0') {
			buffer[buffer_idx] = '\0';
			result[result_idx] = buffer;
			result_idx++;
			buffer_idx = 0;
			count++;
		}
	}

	free(buffer);
	
	return result;
}

char* str_crop(char* base)
{
	int size = 0;
	for(int i = 0; base[i] != '\0'; i++)
	{
		size++;
	}
	char* result = malloc(size + 1);

	for(int i = 0; i < size; i++)
	{
		result[i] = base[i];
	}
	result[size + 1] = '\0';

	return result;
}

bool str_match(char* a, char* b)
{
	for(int i = 0; a[i] != '\0' && b[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void goto_cmd(char* cmd, Page* page)
{
	cmd = str_crop(cmd);
	char id[3];

	id[0] = cmd[5];
	id[1] = cmd[6];
	id[2] = cmd[7];

	char* file = get_page_by_id(id);

	load_page_toml(page, (file == NULL ? "./pages/failed.toml" : file));
}
