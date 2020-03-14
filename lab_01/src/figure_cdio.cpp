#include <stdio.h>

#include "figure_cdio.h"

figure_s *create_figure()
{
    return new figure_s[1];
}

void print_figure(FILE *f, figure_s const *const figure)
{
    for (int i = 0; i < figure->count_points; i++)
        fprintf(f, "%lf %lf %lf\n", figure->list_points[i][X],
                figure->list_points[i][Y], figure->list_points[i][Z]);

    fprintf(f, "\n");
    for (int i = 0; i < figure->count_connections; i++)
        fprintf(f, "%d %d\n", figure->list_connections[i][0],
                figure->list_connections[i][1]);
}

void destruct_figure(figure_s *figure)
{
    for (int i = 0; i < figure->count_points; i++)
        if (figure->list_points[i])
            delete[] figure->list_points[i];

    for (int i = 0; i < figure->count_connections; i++)
        if (figure->list_connections[i])
            delete[] figure->list_connections[i];

    if (figure->list_points)
        delete[] figure->list_points;

    if (figure->list_connections)
        delete[] figure->list_connections;
}

int fill_figure(figure_s *figure)
{
    int rc;

    FILE *f = fopen(FILE_NAME, MODE_READ);

    if (!f)
        return ERROR_OPEN_FILE;

    rc = fscanf(f, "%d", &figure->count_points);
    if (rc != 1 || figure->count_points <= 0)
    {
        destruct_figure(figure);
        fclose(f);
        return ERROR_COUNT_POINTS;
    }

    if (fill_point(f, figure))
    {
        destruct_figure(figure);
        fclose(f);
        return ERROR_INPUT_POINTS;
    }

    rc = fscanf(f, "%d", &figure->count_connections);
    if (rc != 1 || figure->count_connections <= 0)
    {
        destruct_figure(figure);
        fclose(f);
        return ERROR_COUNT_CONNECTIONS;
    }

    if (fill_connections(f, figure))
    {
        destruct_figure(figure);
        fclose(f);
        return ERROR_INPUT_CONNECTIONS;
    }

    fclose(f);

    return 0;
}

int fill_point(FILE *f, figure_s *figure)
{
    figure->list_points = (double **)new double **[figure->count_points];

    if (!figure->list_points)
        return ERROR_FILL;

    for (int i = 0; i < figure->count_points; i++)
    {
        figure->list_points[i] = (double *)new double *[COUNT_COORDINATES + 1];
        if (!figure->list_points[i])
        {
            destruct_figure(figure);
            return ERROR_FILL;
        }
        if (fscanf(f, "%lf %lf %lf", &figure->list_points[i][0],
                   &figure->list_points[i][1],
                   &figure->list_points[i][2]) != COUNT_COORDINATES)
        {
            destruct_figure(figure);
            return ERROR_FILL;
        }
        figure->list_points[i][3] = 1;
    }

    return 0;
}

int fill_connections(FILE *f, figure_s *figure)
{
    figure->list_connections = (int **)new int **[figure->count_connections];

    if (!figure->list_connections)
        return ERROR_FILL;

    for (int i = 0; i < figure->count_connections; i++)
    {
        figure->list_connections[i] = (int *)new int *[2];
        if (!figure->list_connections[i])
        {
            destruct_figure(figure);
            return ERROR_FILL;
        }

        if (fscanf(f, "%d %d", &figure->list_connections[i][0],
                   &figure->list_connections[i][1]) != 2)
        {
            destruct_figure(figure);
            return ERROR_FILL;
        }
    }

    return 0;
}