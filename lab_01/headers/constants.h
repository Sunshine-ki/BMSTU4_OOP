#ifndef _CONSTANTS_H_

#define _CONSTANTS_H_

#define STRING_ERROR_INPUT "qwertyuiop[]asdfghjkl;'zxcvbnm/QWERTYUIOPLKJHGFDSAZXCVBNM."

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

#define MATRIX_SCALE(A, B, C)                                    \
	{                                                            \
		{A, 0, 0, 0}, {0, B, 0, 0}, {0, 0, C, 0}, { 0, 0, 0, 1 } \
	}

#define MATRIX_MOVING(A, B, C)                                   \
	{                                                            \
		{1, 0, 0, A}, {0, 1, 0, B}, {0, 0, 1, C}, { 0, 0, 0, 1 } \
	}

#define MATRIX_ROTATE_X(A)                                                            \
	{                                                                                 \
		{1, 0, 0, 0}, {0, cos(A), sin(A), 0}, {0, -sin(A), cos(A), 0}, { 0, 0, 0, 1 } \
	}

#define MATRIX_ROTATE_Y(A)                                                            \
	{                                                                                 \
		{cos(A), 0, -sin(A), 0}, {0, 1, 0, 0}, {sin(A), 0, cos(A), 0}, { 0, 0, 0, 1 } \
	}

#define MATRIX_ROTATE_Z(A)                                                            \
	{                                                                                 \
		{cos(A), sin(A), 0, 0}, {-sin(A), cos(A), 0, 0}, {0, 0, 1, 0}, { 0, 0, 0, 1 } \
	}

#define ZERO_VECTOR \
	{               \
		0, 0, 0, 0  \
	}

#endif
