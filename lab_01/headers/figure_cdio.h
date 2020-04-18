#ifndef _FIGURE_CDIO_H_

#define _FIGURE_CDIO_H_

#include "error_constants.h"
#include "struct.h"
#include "constants.h"

#include "wrapper.h"

// 0 - projections (x, y)
// 1 - figure (x, y, z)
void print_figure(FILE *f, figure_s const *const figure_temp, int flag = 0);

int fill_figure(figure_s **figure_temp, char *file_name);

int fill_connections(int ***list_connections_p, int &count_connections, FILE *f);

void destruct_figure(figure_s *figure_temp);

int fill_points(double ***list_points_p, int &count_points, FILE *f);

int upload_figure(figure_s *figure, FILE *f);

figure_s *create_figure();

#endif