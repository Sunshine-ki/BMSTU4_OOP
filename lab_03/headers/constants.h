#pragma once

enum Errors
{
	EMPTY_INPUT,
	INPUT_SYMBOL
};

enum Command
{
	MOVE = 1,
	ROTATE,
	SCALE,
	LOAD_FILE
};

#define STRING_ERROR_INPUT "qwertyuiop[]asdfghjkl;'zxcvbnm/QWERTYUIOPLKJHGFDSAZXCVBNM."

#define GLADE_FILE "glade_file/part1.glade"
#define MODE_READ "r"

#define BLUE 0, 0, 255
#define TURQUOISE 0, 255, 255 // Бирюзовый.

#define OK 0