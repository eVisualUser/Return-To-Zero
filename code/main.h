#define MAIN_H
#ifdef MAIN_H

#include "data.h"
#include "ui.h"
#include "text.h"
#include "cmd.h"

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#ifdef _WIN32
#include <Windows.h>
#include <Winuser.h>
#else
#include <unistd.h>
#endif

#define DEFAULT_PAGE_PATH "pages/central_hall.toml"

#define BUTTONS true // Buttons Printing
#define ATITLE true  // Titles 	Printing
#define ATEXT true   // Texts 	Printing
#define AINPUTS true // Inputs	Printing 

#endif // MAIN_H
