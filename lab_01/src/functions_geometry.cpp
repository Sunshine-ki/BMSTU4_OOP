#include "functions_geometry.h"

int check_args(double *args)
{
	if (args[0] == 0 && args[1] == 0 && args[2] == 0)
		return ERROR_CHECK;
	return OK;
}

void convert_degrees(double *args)
{
	for (int i = 0; i < 3; i++)
		args[i] *= M_PI / 180;
}

void copy_vector(double *vector_1, double vector_2[N])
{
	for (int i = 0; i < N; i++)
		vector_1[i] = vector_2[i];
}

void multiplication(double *point, double transform_matrix[N][N])
{
	double vector_res[N] = ZERO_VECTOR;

	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++)
			vector_res[i] += transform_matrix[i][k] * point[k];

	copy_vector(point, vector_res);
}

int function_moving(figure_s *figure_temp, double *args)
{
	if (check_args(args))
		return ERROR_CHECK;

	double matrix_moving[N][N] = MATRIX_MOVING(args[0], args[1], args[2]);

	for (int i = 0; i < figure_temp->count_points; i++)
		multiplication(figure_temp->list_points[i], matrix_moving);

	return OK;
}

int function_scale(figure_s *figure_temp, double *args)
{
	if (check_args(args))
		return ERROR_CHECK;

	double matrix_scale[N][N] = MATRIX_SCALE(args[0], args[1], args[2]);

	for (int i = 0; i < figure_temp->count_points; i++)
		multiplication(figure_temp->list_points[i], matrix_scale);

	return OK;
}

int function_rotate(figure_s *figure_temp, double *args)
{
	if (check_args(args))
		return ERROR_CHECK;

	// Переводим в градусы.
	convert_degrees(args);

	double matrix_rotate_x[N][N] = MATRIX_ROTATE_X(args[0]);
	double matrix_rotate_y[N][N] = MATRIX_ROTATE_Y(args[1]);
	double matrix_rotate_z[N][N] = MATRIX_ROTATE_Z(args[1]);

	for (int i = 0; i < figure_temp->count_points; i++)
	{
		multiplication(figure_temp->list_points[i], matrix_rotate_x);
		multiplication(figure_temp->list_points[i], matrix_rotate_y);
		multiplication(figure_temp->list_points[i], matrix_rotate_z);
	}

	return OK;
}