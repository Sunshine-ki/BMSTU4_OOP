#include "projections.h"

int fill_projections(figure_s *projections, figure_s *figure)
{
    if (projections->count_points <= 0)
        return ERROR_COUNT_POINTS;
    for (int i = 0; i < projections->count_points; i++)
    {
        projections->list_points[i][X] = figure->list_points[i][X];
        projections->list_points[i][Y] = figure->list_points[i][Y];
    }
}

int update_projections(figure_s *projections, figure_s const *const figure)
{
    if (figure->count_points <= 0)
        return ERROR_COUNT_POINTS;

    destruct_figure(projections);
    projections->list_points = (double **)new double **[figure->count_points];
    projections->count_points = figure->count_points;

    for (int i = 0; i < projections->count_points; i++)
    {
        projections->list_points[i] = (double *)new double *[COUNT_COORDINATES - 1];
        projections->list_points[i][0] = projections->list_points[i][1] = 0;
    }

    if (figure->count_connections <= 0)
    {
        destruct_figure(projections);
        return ERROR_COUNT_CONNECTIONS;
    }
    projections->list_connections = (int **)new int **[figure->count_connections];
    projections->count_connections = figure->count_connections;

    for (int i = 0; i < projections->count_connections; i++)
    {
        projections->list_connections[i] = (int *)new int *[2];
        projections->list_connections[i][0] = figure->list_connections[i][0];
        projections->list_connections[i][1] = figure->list_connections[i][1];
    }

    return OK;
}