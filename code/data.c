#include "data.h"

Page create_page()
{
	Page page;

	page.title = malloc(PAGE_TITLE_LEN);
	page.text = malloc(PAGE_TEXT_LEN);
	page.btns = malloc(sizeof(PageButton)*10);
	page.btns_count = 0;

	return page;
}

void free_page(Page* page)
{
	free(page->text);
	free(page->title);
	free(page->btns);
}

void update_user_buffer(Uinput* uip, Uconfig* ucfg)
{
	char buffer = _getch();

	if(buffer == ucfg->right || buffer == 'D')
		uip->right = true;
	else if(buffer == ucfg->left || buffer == 'C')
		uip->left = true;
	else if(buffer == ucfg->up || buffer == 'H')
		uip->up = true;
	else if(buffer == ucfg->down || buffer == 'P')
		uip->down = true;
	else if(buffer == ucfg->ok || buffer == '\r')
		uip->ok = true;
	else if(buffer == ucfg->cancel)
		uip->cancel = true;
	else if(buffer == ucfg->save)
		uip->save = true;
	else if(buffer == ucfg->exit || buffer == '\033')
		uip->exit = true;
}

void reset_user_buffer(Uinput* uip)
{
	uip->right = false;
	uip->left = false;
	uip->up = false;
	uip->down = false;
	uip->ok = false;
	uip->cancel = false;
	uip->save = false;
	uip->exit = false;
}

void load_page_toml(Page* buffer, char* file)
{
	FILE* fp;
	const int err_buf_size = 200;
	char err_buf[err_buf_size];

	fopen_s(&fp, file, "r");

	if(!fp) 
	{
		printf("cannot open %s", file);
	}

	toml_table_t* conf = toml_parse_file(fp, err_buf, err_buf_size);
	
	fclose(fp);
	
	if(!conf) 
	{
		printf("cannot parse %s", file);
	}

	toml_table_t* info = toml_table_in(conf, "info");
	if(!info) 
	{
		printf("missing [info]");
	}

	toml_datum_t title = toml_string_in(info, "title");
	if(!title.ok)
	{
		printf("cannot read info.title");
	}

	toml_datum_t text = toml_string_in(info, "text");
	if(!text.ok)
	{
		printf("cannot read info.text");
	}

	buffer->title = (char*)title.u.s;
	buffer->text = (char*)text.u.s;

	toml_table_t* buttons = toml_table_in(conf, "buttons");
	if(!buttons)
	{
		printf("Missing Buttons");
	}

	bool done = false;
	for(int i = 0; done == false;i++)
	{
		const char* btn_key = toml_key_in(buttons, i);
		if(!btn_key)
		{
			break;
		}

		toml_array_t* btn = toml_array_in(buttons, btn_key);
		if(!btn)
		{
			break;
		}

		else {
			toml_datum_t btn_text = toml_string_at(btn, 0);
			if(!btn_text.ok)
			{
				break;
				printf("Missing text for button");
			}

			toml_datum_t btn_act = toml_string_at(btn, 1);
			if(!btn_text.ok)
			{
				break;
				printf("Missing action for button");
			}

			toml_datum_t btn_cond = toml_string_at(btn, 2);
			if(!btn_text.ok)
			{
				break;
				printf("Missing condition for button");
			}
			
			PageButton pb;
			pb.text = (char*)btn_text.u.s;
			pb.action = (char*)btn_act.u.s;
			pb.condition = (char*)btn_cond.u.s;

			buffer->btns[i] = pb;
			buffer->btns_count = i;
		}
	}

	toml_free(conf);
}

char* get_page_by_id(char id[3])
{
	FILE* stream = fopen("./pages/index.csv", "r");

	char* oid = malloc(100);
	char* path = malloc(100);

    char line[100];

    bool done = false;

    while (fgets(line, 1024, stream) && !done)
    {
        char* tmp = strdup(line);
        oid = getfield(tmp, 2);

        if(id[0] == oid[0] && id[1] == oid[1] && id[2] == oid[2])
        {
        	done = !done;
        	path = getfield(tmp, 1);
        }
        free(tmp);
    }

    path[strlen(path-1)] = '\0';

    printf("%s", path);
    return path;
}

char* get_first_page()
{
	FILE* stream = fopen("./pages/index.csv", "r");

	char* path = malloc(100);
	int size = 0;

    char line[100];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        path = getfield(tmp, 1);
        free(tmp);
        break;
    }

    return path;
}

char* cropper(char* base)
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

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
