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

int create_list_points(figure_s *figure)
{
	figure->list_points = (double **)new double **[figure->count_points];

	if (!figure->list_points)
		return ERROR_ALLOCATION_MEMORY;

	for (int i = 0; i < figure->count_points; i++)
	{
		figure->list_points[i] = (double *)new double *[COUNT_COORDINATES + 1];
		if (!figure->list_points[i])
			return ERROR_ALLOCATION_MEMORY;
	}

	return OK;
}

int fill_points(figure_s *figure, FILE *f)
{
	// Перенести считывание кол-во точек сюда. ok.
	// Разделить выделение памяти и считывание (цикл) (Разбить на функции) ok.
	// Из цикла выход один. ok.
	int rc = fscanf(f, "%d", &figure->count_points);
	if (rc != 1 || figure->count_points <= 0)
		return ERROR_COUNT_POINTS;

	int err = create_list_points(figure);
	if (err)
		return err;

	for (int i = 0; i < figure->count_points; i++)
	{
		rc = fscanf(f, "%lf %lf %lf", &figure->list_points[i][0],
					&figure->list_points[i][1], &figure->list_points[i][2]);
		if (rc != COUNT_COORDINATES)
			return ERROR_FILL_POINTS;

		figure->list_points[i][3] = 1;
	}

	return OK;
}

int create_list_connections(figure_s *figure)
{
	figure->list_connections = (int **)new int **[figure->count_connections];

	if (!figure->list_connections)
		return ERROR_ALLOCATION_MEMORY;

	for (int i = 0; i < figure->count_connections; i++)
	{
		figure->list_connections[i] = (int *)new int *[COUNT_CONNECTIONS];
		if (!figure->list_connections[i])
			return ERROR_ALLOCATION_MEMORY;
	}

	return OK;
}

int fill_connections(figure_s *figure, FILE *f)
{
	int rc = fscanf(f, "%d", &figure->count_connections);
	if (rc != 1 || figure->count_connections <= 0)
		return ERROR_COUNT_CONNECTIONS;

	int err = create_list_connections(figure);
	if (err)
		return err;

	for (int i = 0; i < figure->count_connections; i++)
	{
		rc = fscanf(f, "%d %d", &figure->list_connections[i][0],
					&figure->list_connections[i][1]);
		if (rc != COUNT_CONNECTIONS)
			return ERROR_FILL_CONNECTIONS;
	}

	return OK;
}

// Очистить тут!(А не в обертке) ok.
// fill_points !!! ok.
int fill(figure_s *figure, FILE *f)
{
	// Тоже в обертку ok.
	// err = считать кол-во точек ok.
	// if err return.. ok.
	int err = fill_points(figure, f);
	if (err)
	{
		destruct_figure(figure); // Не должно быть в цикле! ok.
		return err;
	}

	err = fill_connections(figure, f);
	if (err)
	{
		destruct_figure(figure);
		return err;
	}

	return OK;
}

int fill_figure(figure_s **figure_p, char *file_name) //char *file_name. ok.
{
	// Не портить данный если не выполнилось. ok.
	// Удаление и обертка. ok.
	FILE *f = fopen(file_name, MODE_READ);

	if (!f)
		return ERROR_OPEN_FILE;

	figure_s *figure_temp = create_figure();
	int err = fill(figure_temp, f);

	fclose(f);

	if (err)
		return err;

	destruct_figure(*figure_p);
	*figure_p = figure_temp;

	return err;
}