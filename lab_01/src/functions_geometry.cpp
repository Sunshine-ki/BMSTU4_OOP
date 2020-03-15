#include "functions_geometry.h"

int check_args(double *args)
{
    if (args[0] == 0 && args[1] == 0 && args[2] == 0)
        return ERROR_CHECK;
    return OK;
}

double *multiplication(double **point_p, double transform_matrix[N][N])
{
    double *point = *point_p;

    double *vector_res = (double *)new double *[N];

    for (int i = 0; i < N; i++)
    {
        vector_res[i] = 0;
        for (int k = 0; k < N; k++)
            vector_res[i] += transform_matrix[i][k] * point[k];
    }

    delete[] point;
    return vector_res;
}

int function_moving(figure_s *figure_temp, double *args)
{
    if (check_args(args))
        return ERROR_CHECK;

    double matrix_moving[N][N] = MATRIX_MOVING(args[0], args[1], args[2]);

    for (int i = 0; i < figure_temp->count_points; i++)
        figure_temp->list_points[i] = multiplication(&figure_temp->list_points[i], matrix_moving);

    return OK;
}

int function_scale(figure_s *figure_temp, double *args)
{
    if (check_args(args))
        return ERROR_CHECK;

    double matrix_scale[N][N] = MATRIX_SCALE(args[0], args[1], args[2]);

    for (int i = 0; i < figure_temp->count_points; i++)
        figure_temp->list_points[i] = multiplication(&figure_temp->list_points[i], matrix_scale);

    return OK;
}

int function_rotate(figure_s *figure_temp, double *args)
{
    if (check_args(args))
        return ERROR_CHECK;

    for (int i = 0; i < 3; i++)
        args[i] *= M_PI / 180;

    double matrix_rotate_x[N][N] = MATRIX_ROTATE_X(args[0]);
    double matrix_rotate_y[N][N] = MATRIX_ROTATE_Y(args[1]);
    double matrix_rotate_z[N][N] = MATRIX_ROTATE_Z(args[1]);

    for (int i = 0; i < figure_temp->count_points; i++)
    {
        figure_temp->list_points[i] = multiplication(&figure_temp->list_points[i], matrix_rotate_x);
        figure_temp->list_points[i] = multiplication(&figure_temp->list_points[i], matrix_rotate_y);
        figure_temp->list_points[i] = multiplication(&figure_temp->list_points[i], matrix_rotate_z);
    }

    return OK;
}