#include "cmd.h"

int gen_new_luck()
{
	return rand() % 6 + 1;
}

void execute_cmd(char* cmd, Page* page)
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
}

bool test_cond(char* cond, Player player, int luck)
{
	char* ccond = str_crop(cond);

	if(str_match(ccond, COND_NONE)) return true;
	if(str_match(ccond, COND_DOC)) 
	{
		if(player.job == Doctor) return true;
		else return false;
	}
	else if(str_match(ccond, COND_ENG)) 
	{
		if(player.job == Enginer) return true;
		else return false;
	}
	else if(str_match(ccond, COND_GEO)) 
	{
		if(player.job == Geologist) return true;
		else return false;
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
