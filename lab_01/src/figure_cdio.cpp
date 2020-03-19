#include <stdio.h>

#include "figure_cdio.h"

void destruct_all(figure_s *figure, figure_s *projections)
{
	destruct_figure(figure);
	destruct_figure(projections);
}

figure_s *create_figure()
{
	figure_s *figure = (figure_s *)new figure_s[1];
	figure->count_connections = figure->count_points = 0;
	figure->list_connections = NULL;
	figure->list_points = NULL;
	return figure;
}

void print_figure(FILE *f, figure_s const *const figure, int flag)
{
	for (int i = 0; i < figure->count_points; i++)
	{
		fprintf(f, "%lf %lf ", figure->list_points[i][X],
				figure->list_points[i][Y]);

		if (flag)
			fprintf(f, "%lf", figure->list_points[i][Z]);

		fprintf(f, "\n");
	}

	fprintf(f, "\n");
	for (int i = 0; i < figure->count_connections; i++)
		fprintf(f, "%d %d\n", figure->list_connections[i][0],
				figure->list_connections[i][1]);
}

void destruct_figure(figure_s *figure)
{
	// if (figure->count_points <= 0)
	// return ERROR_COUNT_POINTS;
	for (int i = 0; i < figure->count_points; i++)
		if (figure->list_points[i])
			delete[] figure->list_points[i];

	// if (figure->count_connections <= 0)
	// return ERROR_COUNT_CONNECTIONS;
	for (int i = 0; i < figure->count_connections; i++)
		if (figure->list_connections[i])
			delete[] figure->list_connections[i];

	if (figure->list_points)
		delete[] figure->list_points;

	if (figure->list_connections)
		delete[] figure->list_connections;
}

int fill_point(figure_s *figure, FILE *f)
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

int fill_connections(figure_s *figure, FILE *f)
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

int fill(figure_s *figure, FILE *f)
{
	int rc;

	rc = fscanf(f, "%d", &figure->count_points);
	if (rc != 1 || figure->count_points <= 0)
		return ERROR_COUNT_POINTS;

	if (fill_point(figure, f))
		return ERROR_INPUT_POINTS;

	rc = fscanf(f, "%d", &figure->count_connections);
	if (rc != 1 || figure->count_connections <= 0)
		return ERROR_COUNT_CONNECTIONS;

	if (fill_connections(figure, f))
		return ERROR_INPUT_CONNECTIONS;

	return OK;
}

int fill_figure(figure_s **figure_p, char *file_name) //char *file_name. ok
{
	// Не портить данный если не выполнилось. ok.
	// удаление и обертка. ok.
	FILE *f = fopen(file_name, MODE_READ);
	int err = OK;

	if (!f)
		return ERROR_OPEN_FILE;

	figure_s *figure_temp = create_figure();
	err = fill(figure_temp, f);

	if (err)
	{
		destruct_figure(figure_temp);
	}
	else
	{
		destruct_figure(*figure_p);
		*figure_p = figure_temp;
	}

	fclose(f);

	return err;
}