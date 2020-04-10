#ifndef _CONSTANTS_H_

#define _CONSTANTS_H_

#define STRING_ERROR_INPUT "qwertyuiop[]asdfghjkl;'zxcvbnm/"

#define GLADE_FILE "glade_file/part1.glade"
#define MODE_READ "r"

#define OK 0

#define MOVING 1
#define ROTATE 2
#define SCALE 3
#define LOAD_FILE 4
#define FILL_PROJECTIONS 5
#define UPDATE_PROJECTIONS 6
#define QUIT 7

#define X 0
#define Y 1
#define Z 2

#define N 4

#define COUNT_COORDINATES 3
#define COUNT_CONNECTIONS 2

#define BLUE 0, 0, 255
#define TURQUOISE 0, 255, 255 // Бирюзовый.

#define MATRIX_SCALE(a, b, c)                                    \
	{                                                            \
		{a, 0, 0, 0}, {0, b, 0, 0}, {0, 0, c, 0}, { 0, 0, 0, 1 } \
	}

#define MATRIX_MOVING(a, b, c)                                   \
	{                                                            \
		{1, 0, 0, a}, {0, 1, 0, b}, {0, 0, 1, c}, { 0, 0, 0, 1 } \
	}

#define MATRIX_ROTATE_X(a)                                                            \
	{                                                                                 \
		{1, 0, 0, 0}, {0, cos(a), sin(a), 0}, {0, -sin(a), cos(a), 0}, { 0, 0, 0, 1 } \
	}

#define MATRIX_ROTATE_Y(a)                                                            \
	{                                                                                 \
		{cos(a), 0, -sin(a), 0}, {0, 1, 0, 0}, {sin(a), 0, cos(a), 0}, { 0, 0, 0, 1 } \
	}

#define MATRIX_ROTATE_Z(a)                                                            \
	{                                                                                 \
		{cos(a), sin(a), 0, 0}, {-sin(a), cos(a), 0, 0}, {0, 0, 1, 0}, { 0, 0, 0, 1 } \
	}

#endif
