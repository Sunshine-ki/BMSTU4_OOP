#include <stdio.h>

#include "figure_cdio.h"

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

void destruct_list_connections(int ***list_connections_p, int const count_connections)
{
	int **list_connections = *list_connections_p;

	for (int i = 0; i < count_connections; i++)
		if (list_connections[i])
			delete[] list_connections[i];

	if (list_connections)
		delete[] list_connections;

	*list_connections_p = NULL;
}

void destruct_list_points(double ***list_points_p, int const count_points)
{
	double **list_points = *list_points_p;

	for (int i = 0; i < count_points; i++)
		if (list_points[i])
			delete[] list_points[i];

	if (list_points)
		delete[] list_points;

	*list_points_p = NULL;
}

void destruct_figure(figure_s *figure)
{
	destruct_list_points(&figure->list_points, figure->count_points);
	destruct_list_connections(&figure->list_connections, figure->count_connections);
}

int create_list_points(double ***list_points_p, int const count_points)
{
	double **list_points = *list_points_p;

	list_points = (double **)new double **[count_points];

	if (!list_points)
		return ERROR_ALLOCATION_MEMORY;

	for (int i = 0; i < count_points; i++)
	{
		list_points[i] = (double *)new double *[COUNT_COORDINATES + 1];
		if (!list_points[i])
			return ERROR_ALLOCATION_MEMORY;
	}

	*list_points_p = list_points;
	return OK;
}

int read_count(int &number, FILE *f)
{
	int err = OK;
	int rc = fscanf(f, "%d", &number);
	if (rc != 1 || number <= 0)
		err = ERROR_COUNT_POINTS;

	return err;
}

int read_point(double *list_points, FILE *f)
{
	int rc = OK;
	if (fscanf(f, "%lf %lf %lf", &list_points[0],
			   &list_points[1], &list_points[2]) != COUNT_COORDINATES)
		rc = ERROR_FILL_POINTS;
	list_points[3] = 1;

	return rc;
}

int fill_points(double ***list_points_p, int &count_points, FILE *f)
{
	double **list_points = *list_points_p;
	// Перенести считывание кол-во точек сюда. ok.
	// Разделить выделение памяти и считывание (цикл) (Разбить на функции) ok.

	// Обертки для fscanf (их тут 2). ok.
	int err = read_count(count_points, f);
	if (err)
		return ERROR_COUNT_POINTS;

	// Передавать не фигуру. ok.
	err = create_list_points(&list_points, count_points);
	if (err)
		return err;

	// К одному условию.(Один выход из цикла.) ok.
	for (int i = 0; i < count_points && !err; i++)
		err = read_point(list_points[i], f);

	if (err)
		destruct_list_points(&list_points, count_points);
	else
		*list_points_p = list_points;

	// Освобождать тут, если не выполнилось. ok.
	return err;
}

int create_list_connections(int ***list_connections_p, int const count_connections)
{
	int **list_connections = *list_connections_p;
	list_connections = (int **)new int **[count_connections];

	if (!list_connections)
		return ERROR_ALLOCATION_MEMORY;

	for (int i = 0; i < count_connections; i++)
	{
		list_connections[i] = (int *)new int *[COUNT_CONNECTIONS];
		if (!list_connections[i])
			return ERROR_ALLOCATION_MEMORY;
	}

	*list_connections_p = list_connections;
	return OK;
}

int read_connection(int *list_connections, FILE *f)
{
	int rc = OK;
	if (fscanf(f, "%d %d", &list_connections[0],
			   &list_connections[1]) != COUNT_CONNECTIONS)
		rc = ERROR_FILL_CONNECTIONS;
	return rc;
}

int fill_connections(int ***list_connections_p, int &count_connections, FILE *f)
{
	int **list_connections = *list_connections_p;

	int err = read_count(count_connections, f);
	if (err)
		return ERROR_COUNT_CONNECTIONS;

	err = create_list_connections(&list_connections, count_connections);
	if (err)
		return err;

	for (int i = 0; i < count_connections && !err; i++)
		err = read_connection(list_connections[i], f);

	if (err)
		destruct_list_connections(&list_connections, count_connections);
	else
		*list_connections_p = list_connections;

	return err;
}

// Очистить тут!(А не в обертке) ok.
// fill_points !!! ok.
int upload_file(figure_s *figure, FILE *f)
{
	// Тоже в обертку ok.
	// err = считать кол-во точек ok.
	// if err return.. ok.

	// fill_points(figure.points_count, figure.points, f); ok.
	int err = fill_points(&figure->list_points, figure->count_points, f);
	if (err)
	{
		// destruct_figure(figure); // Не должно быть в цикле! ok.
		return err;
	}

	// fill_points(figure.points_count, figure.points, f); ok.
	err = fill_connections(&figure->list_connections, figure->count_connections, f);
	if (err)
	{
		destruct_list_points(&figure->list_points, figure->count_points);
	}

	return err;
}

int fill_figure(figure_s **figure_p, char *file_name) //char *file_name. ok.
{
	// Не портить данный если не выполнилось. ok.
	// Удаление и обертка. ok.
	FILE *f = fopen(file_name, MODE_READ);

	if (!f)
		return ERROR_OPEN_FILE;

	figure_s *figure_temp = create_figure();
	int err = upload_file(figure_temp, f);

	fclose(f);

	if (err)
		return err;

	destruct_figure(*figure_p);
	*figure_p = figure_temp;

	return err;
}
