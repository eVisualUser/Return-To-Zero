#include "cmd.h"

int gen_new_luck()
{
	return rand() % 6 + 1;
}

void execute_cmd(char* cmd, Page* page, Player* player)
{
	int count = 0;
	char** args = extract_args(cmd, &count);
	for(int i = 0; i < count; i++)
	{
		if(str_match(args[i], "debug"))
			printf("DEBUG\n");
		else if(args[i][0] == 'g' && args[i][1] == 'o' && args[i][2] == 't' && args[i][3] == 'o')
		{
			goto_cmd(args[i], page);
		}
		else if (str_match(args[i], "reset"))
		{
			player->job = Doctor;
			player->food = 0;
			player->weight = gen_new_luck() + 2;
			player->speed = gen_new_luck() + 4;
			player->social = 2;
			player->syringe = 0;
			player->grapple_hook = 0;
			player->pickaxe = 0;
			player->carbon_boots = 0;
			player->flare = 0;
			player->spanner = 0;
			player->book = 0;
			player->son_saved = false;
			player->hability = gen_new_luck() + 6;
			player->luck = gen_new_luck() + 6;
			player->energy = gen_new_luck() + gen_new_luck() + 10;
			player->binocular = 0;
			player->talk_cap = false;
		}
		else if (str_match(args[i], "quit"))
		{
			exit(0);
		}
		else if(str_match(args[i], "start"))
		{
			load_page_toml(page, get_first_page());
		}
		else if(str_match(args[i], "doc"))
		{
			player->job = Doctor;
		}
		else if(str_match(args[i], "mec"))
		{
			player->job = Mechanician;
		}
		else if(str_match(args[i], "geo"))
		{
			player->job = Geologist;
		}
		else if(str_match(args[i], "+food"))
		{
			player->food++;
		}
		else if(str_match(args[i], "-food"))
		{
			player->food--;
		}
		else if(str_match(args[i], "+binocular"))
		{
			player->binocular++;
		}
		else if(str_match(args[i], "-binocular"))
		{
			player->binocular--;
		}
		else if(str_match(args[i], "+energy"))
		{
			player->energy++;
		}
		else if(str_match(args[i], "-energy"))
		{
			player->energy--;
		}
		else if(str_match(args[i], "+weight"))
		{
			player->weight++;
		}
		else if(str_match(args[i], "-weight"))
		{
			player->weight--;
		}
		else if(str_match(args[i], "+speed"))
		{
			player->speed++;
		}
		else if(str_match(args[i], "-speed"))
		{
			player->speed--;
		}
		else if(str_match(args[i], "+luck"))
		{
			player->luck++;
		}
		else if(str_match(args[i], "-luck"))
		{
			player->luck--;
		}
		else if(str_match(args[i], "+hability"))
		{
			player->hability++;
		}
		else if(str_match(args[i], "-hability"))
		{
			player->hability--;
		}
		else if(str_match(args[i], "-weight"))
		{
			player->weight--;
		}
		else if(str_match(args[i], "+social"))
		{
			player->social++;
		}
		else if(str_match(args[i], "-social"))
		{
			player->social--;
		}
		else if(str_match(args[i], "+syringe"))
		{
			player->syringe += 1;
		}
		else if(str_match(args[i], "-syringe"))
		{
			player->syringe -= 1;
		}
		else if(str_match(args[i], "+spanner"))
		{
			player->spanner++;
		}
		else if(str_match(args[i], "-spanner"))
		{
			player->spanner--;
		}
		else if(str_match(args[i], "+pickaxe"))
		{
			player->pickaxe++;
		}
		else if(str_match(args[i], "-pickaxe"))
		{
			player->pickaxe--;
		}
		else if(str_match(args[i], "+book"))
		{
			player->book++;
		}
		else if(str_match(args[i], "-book"))
		{
			player->book--;
		}
		else if(str_match(args[i], "son_saved"))
		{
			player->son_saved = true;
		}
		else if(str_match(args[i], "talk_cap"))
		{
			player->talk_cap = true;
		}
	}
	free(args);
}

bool test_cond(char* cond, Player player, int luck)
{
	char* ccond = str_crop(cond);
	
	bool result = true;

	int count = 0;
	char** args = extract_args(ccond, &count);
	for(int i = 0; i < count; i++)
	{
		if(str_match(args[i], "doc")) 
		{
			if(player.job == Doctor) {
				result = true;
			}
		}
		else if(str_match(args[i], "!doc")) 
		{
			if(player.job == Doctor) {
				result = false;
			}
		}
		else if(str_match(args[i], "mec")) 
		{
			if(player.job == Mechanician) result = true;
			else result = false;
		}
		else if(str_match(args[i], "!mec")) 
		{
			if(player.job == Mechanician) result = false;
		}
		else if(str_match(args[i], "geo")) 
		{
			if(player.job == Geologist) result = true;
			else result = false;
		}
		else if(str_match(args[i], "!geo")) 
		{
			if(player.job == Geologist) result = false;
		}
		else if(str_match(args[i], "luck_high"))
		{
			if (luck >= 5)
				result = false;
			else result = true;
		}
		else if(str_match(args[i], "luck_med"))
		{
			if (luck >= 3)
				result = false;
			else result = true;
		}
		else if (str_match(args[i], "!luck_med"))
		{
			if (luck < 3)
				result = false;
		}
		else if (str_match(args[i], "luck_low"))
		{
			if (luck >= 2)
				result = false;
		}
		else if (str_match(args[i], "!luck_low"))
		{
			if (luck < 2)
				result = false;
		}
		else if (str_match(args[i], "!luck_high"))
		{
			if (luck <= 5)
				result = false;
		}
		else if (str_match(args[i], "luck"))
		{
			if (player.luck > 0)
				result = false;
		}
		else if (str_match(args[i], "!luck"))
		{
			if (player.luck == 0)
				result = false;
		}
		else if (str_match(args[i], "hability"))
		{
			if (player.hability > 0)
				result = false;
		}
		else if (str_match(args[i], "!hability"))
		{
			if (player.hability == 0)
				result = false;
		}
		else if (str_match(args[i], "binocular"))
		{
			if (player.binocular > 0)
				result = false;
		}
		else if (str_match(args[i], "!binocular"))
		{
			if (player.binocular == 0)
				result = false;
		}
		else if (str_match(args[i], "food"))
		{
			if (player.food > 0)
				result = false;
		}
		else if (str_match(args[i], "!food"))
		{
			if (player.food == 0)
				result = false;
		}
		else if (str_match(args[i], "weight"))
		{
			if (player.weight > 0)
				result = false;
		}
		else if (str_match(args[i], "!weight"))
		{
			if(player.weight == 0)
				result = false;
		}
		else if (str_match(args[i], "speed"))
		{
			if(player.speed > 0)
				result = false;
		}
		else if (str_match(args[i], "!speed"))
		{
			if(player.speed == 0)
				result = false;
		}
		else if (str_match(args[i], "energy"))
		{
			if(player.energy > 0)
				result = false;
		}
		else if (str_match(args[i], "!energy"))
		{
			if(player.energy == 0)
				result = false;
		}
		else if (str_match(args[i], "social"))
		{
			if(player.weight > 0)
				result = false;
		}
		else if (str_match(args[i], "!social"))
		{
			if(player.social == 0)
				result = false;
		}
		else if (str_match(args[i], "syringe"))
		{
			if(player.syringe == 0)
				result = false;
		}
		else if (str_match(args[i], "!syringe"))
		{
			if(player.syringe > 0)
				result = false;
		}
		else if (str_match(args[i], "grapple_hook"))
		{
			if(player.grapple_hook > 0)
				result = false;
		}
		else if (str_match(args[i], "!grapple_hook"))
		{
			if(player.grapple_hook == 0)
				result = false;
		}
		else if (str_match(args[i], "pickaxe"))
		{
			if(player.pickaxe > 0)
				result = false;
		}
		else if (str_match(args[i], "!pickaxe"))
		{
			if(player.pickaxe == 0)
				result = false;
		}
		else if (str_match(args[i], "carbon_boots"))
		{
			if(player.carbon_boots > 0)
				result = false;
		}
		else if (str_match(args[i], "!carbon_boots"))
		{
			if(player.carbon_boots == 0)
				result = false;
		}
		else if (str_match(args[i], "flare"))
		{
			if(player.flare > 0)
				result = false;
		}
		else if (str_match(args[i], "!flare"))
		{
			if(player.flare == 0)
				result = false;
		}
		else if (str_match(args[i], "spanner"))
		{
			if(player.spanner > 0)
				result = false;
		}
		else if (str_match(args[i], "!spanner"))
		{
			if(player.spanner == 0)
				result = false;
		}
		else if (str_match(args[i], "book"))
		{
			if(player.book > 0)
				result = false;
		}
		else if (str_match(args[i], "!book"))
		{
			if(player.book == 0)
				result = false;
		}
		else if(str_match(args[i], "son_saved"))
		{
			if(player.son_saved)
				result = false;
		}
		else if(str_match(args[i], "!son_saved"))
		{
			if(!player.son_saved)
				result = false;
		}
		else if(str_match(args[i], "talk_cap"))
		{
			if(player.talk_cap)
				result = false;
		}
		else if(str_match(args[i], "!talk_cap"))
		{
			if(!player.talk_cap)
				result = false;
		}
	}
	free(args);
	return result;
}

char** extract_args(char* cmd, int* count)
{
	int arg_count = 0;

	for(int i = 0; cmd[i] != '\0'; i++) {
		if (cmd[i] == ';') {
			arg_count += 1;
		}
	}

	*count = arg_count;

	char** result = malloc(arg_count);
	
	for (int i = 0; i < arg_count; i++) {
		result[i] = malloc(arg_count);
	}

	for (int i = 0; i < arg_count; i++)
	{
		char* tmp = strdup(cmd);
		result[i] = (char*)getfield(tmp, i+1);
	}

	return result;
}

char* str_crop(char* base)
{
	int size = 0;
	for(int i = 0; base[i] != '\0'; i++) {size++;}

	char* result = malloc(size);

	for(int i = 0; i <= size; i++)
	{
		result[i] = base[i];
	}

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
	char id[3];

	id[0] = cmd[5];
	id[1] = cmd[6];
	id[2] = cmd[7];

	char* file = get_page_by_id(id);

	load_page_toml(page, (file == NULL ? "./pages/failed.toml" : file));
}

size_t str_get_size(char* str)
{
	size_t result = 0;
	for(size_t i = 0; str[i] != '\0'; i++)
	{
		result++;
	}
	return result+1;
}
