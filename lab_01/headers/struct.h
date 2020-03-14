#ifndef _STRUCT_H_

#define _STRUCT_H_

#include <gtk/gtk.h>

typedef struct projections_s
{
    int count_points;
    int count_connections;
    double **list_points;
    int **list_connections;
} projections_s;

typedef struct figure_s
{
    int count_points;
    int count_connections;
    double **list_points;
    int **list_connections;
} figure_s;

typedef struct event_s
{
    char file_name[64];
    double args[3];
    projections_s *projections;
} event_s;

typedef struct
{
    GtkWidget *canvas;
    GtkWidget *entry[3];
    GtkWidget *entry_name_file;
    figure_s figure;
    // projections_s *projections;
    event_s event;
} my_struct_s;

#endif