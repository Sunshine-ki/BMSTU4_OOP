#include "projections_cdio.h"
#include "constants.h"

projections_s *create_projections()
{
    projections_s *projections = (projections_s *)new projections_s[1];
    projections->count_connections = projections->count_points = 0;
    // printf("Я тут = %d = %d\n", projections->count_connections, projections->count_points);
    projections->list_connections = NULL;
    projections->list_points = NULL;
    return projections;
}

void fill_projections(projections_s *projections, figure_s *figure)
{
    for (int i = 0; i < projections->count_points; i++)
    {
        projections->list_points[i][X] = figure->list_points[i][X];
        projections->list_points[i][Y] = figure->list_points[i][Y];
    }
}

void print_projections(FILE *f, projections_s const *const projections)
{
    printf("count_points = %d\n", projections->count_points);
    for (int i = 0; i < projections->count_points; i++)
        fprintf(f, "%lf %lf\n", projections->list_points[i][X],
                projections->list_points[i][Y]);

    fprintf(f, "\n");
    for (int i = 0; i < projections->count_connections; i++)
        fprintf(f, "%d %d\n", projections->list_connections[i][0],
                projections->list_connections[i][1]);
}

void destruct_projections(projections_s *projections)
{
    printf("count_points = %d\n ", projections->count_points);
    for (int i = 0; i < projections->count_points; i++)
        if (projections->list_points[i] != NULL)
            delete[] projections->list_points[i];

    for (int i = 0; i < projections->count_connections; i++)
        if (projections->list_connections[i])
            delete[] projections->list_connections[i];

    if (projections->list_points)
        delete[] projections->list_points;

    if (projections->list_connections)
        delete[] projections->list_connections;
}

int update_projections(projections_s *projections, figure_s const *const figure)
{
    int rc = 0;

    destruct_projections(projections);
    // printf("update_projections = %d", figure->count_points);
    projections->list_points = (double **)new double **[figure->count_points];
    projections->count_points = figure->count_points;

    for (int i = 0; i < projections->count_points; i++)
    {
        projections->list_points[i] = (double *)new double *[COUNT_COORDINATES - 1];
        projections->list_points[i][0] = projections->list_points[i][1] = 0;
    }

    projections->list_connections = (int **)new int **[figure->count_connections];
    projections->count_connections = figure->count_connections;

    for (int i = 0; i < projections->count_connections; i++)
    {
        projections->list_connections[i] = (int *)new int *[2];
        projections->list_connections[i][0] = figure->list_connections[i][0];
        projections->list_connections[i][1] = figure->list_connections[i][1];
    }

    return rc;
}