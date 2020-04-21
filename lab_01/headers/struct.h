#ifndef _STRUCT_H_

#define _STRUCT_H_

#include <gtk/gtk.h>

typedef struct
{
	int count_points;
	int count_connections;
	double **list_points;
	int **list_connections;
} figure_s;

typedef struct
{
	char *name;
} file_name_s;

typedef struct
{
	double args[3];
} args_s;

typedef struct
{
	file_name_s file_name;
	args_s arguments;
} event_s;

typedef struct
{
	GtkWidget *canvas;
	GtkWidget *entry[3];
	GtkWidget *entry_name_file;
	figure_s *projections;
	event_s event;
} my_struct_s;

#endif