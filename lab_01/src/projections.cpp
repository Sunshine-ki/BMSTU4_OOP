#include "projections.h"

int fill_projections(figure_s *projections, figure_s const *const figure)
{
    if (projections->count_points < 0)
        return ERROR_COUNT_POINTS;
    for (int i = 0; i < projections->count_points; i++)
    {
        projections->list_points[i][X] = figure->list_points[i][X];
        projections->list_points[i][Y] = figure->list_points[i][Y];
    }
    return OK;
}

int fill_count(figure_s *projections, figure_s const *const figure)
{
    if (figure->count_points <= 0)
        return ERROR_COUNT_POINTS;

    if (figure->count_connections <= 0)
        return ERROR_COUNT_CONNECTIONS;

    projections->count_points = figure->count_points;
    projections->count_connections = figure->count_connections;

    return OK;
}

int create_projections(figure_s *projections, figure_s const *const figure)
{
    projections->list_points = (double **)new double **[figure->count_points];
    if (!projections->list_points)
        return ERROR_ALLOCATION_MEMORY;

    for (int i = 0; i < projections->count_points; i++)
    {
        projections->list_points[i] = (double *)new double *[COUNT_COORDINATES - 1];
        if (!projections->list_points[i])
            return ERROR_ALLOCATION_MEMORY;
        projections->list_points[i][0] = projections->list_points[i][1] = 0;
    }

    projections->list_connections = (int **)new int **[figure->count_connections];
    if (!projections->list_connections)
        return ERROR_ALLOCATION_MEMORY;

    for (int i = 0; i < projections->count_connections; i++)
    {
        projections->list_connections[i] = (int *)new int *[2];
        if (!projections->list_connections[i])
            return ERROR_ALLOCATION_MEMORY;
    }

    return OK;
}

void copy_list_connections(figure_s *projections, figure_s const *const figure)
{

    for (int i = 0; i < projections->count_connections; i++)
    {
        projections->list_connections[i][0] = figure->list_connections[i][0];
        projections->list_connections[i][1] = figure->list_connections[i][1];
    }
}

int update_projections(figure_s **projections_p, figure_s const *const figure)
{
    figure_s *projections = *projections_p;
    destruct_figure(projections);
    int err = fill_count(projections, figure);
    if (err)
        return err;

    err = create_projections(projections, figure);
    if (err)
    {
        destruct_figure(projections);
        return err;
    }

    copy_list_connections(projections, figure);
    fill_projections(projections, figure);

    // *projections_p = projections;

    return OK;
}