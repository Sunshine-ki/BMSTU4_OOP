#pragma once

enum Errors
{
	EMPTY_INPUT,
	INPUT_SYMBOL,
	OPEN_FILE
};

enum Command
{
	MOVE = 1,
	ROTATE,
	SCALE,
	LOAD_FILE
};

enum TypeObject {
    FIGURE,
    CAMERA,
    SCENE
};


#define STRING_ERROR_INPUT "qwertyuiop[]asdfghjkl;'zxcvbnm/QWERTYUIOPLKJHGFDSAZXCVBNM."

#define GLADE_FILE "glade_file/part1.glade"
#define MODE_READ "r"

#define BLUE 0, 0, 255
#define TURQUOISE 0, 255, 255 // Бирюзовый.

#define OK 0

#define MATRIX_SCALE(A, B, C) {A, 0, 0, 0, 0, B, 0, 0, 0, 0, C, 0, 0, 0, 0, 1}

#define MATRIX_MOVING(A, B, C) {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, A, B, C, 1};

#define MATRIX_ROTATE_X(A) {1, 0, 0, 0, 0, cos(A), sin(A), 0, 0, -sin(A), cos(A), 0, 0, 0, 0, 1}

#define MATRIX_ROTATE_Y(A) {cos(A), 0, -sin(A), 0, 0, 1, 0, 0, sin(A), 0, cos(A), 0 , 0, 0, 0, 1}

#define MATRIX_ROTATE_Z(A) {cos(A), sin(A), 0, 0, -sin(A), cos(A), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }