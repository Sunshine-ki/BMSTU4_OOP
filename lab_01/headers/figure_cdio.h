#ifndef _FIGURE_CDIO_H_

#define _FIGURE_CDIO_H_

#include "error_constants.h"
#include "struct.h"
#include "constants.h"

// 0 - projections (x, y)
// 1 - figure (x, y, z)
void print_figure(FILE *f, figure_s const *const figure_temp, int flag = 0);

int fill_figure(figure_s *figure_temp, char file_name[64]);

int fill_connections(figure_s *figure, FILE *f);

void destruct_figure(figure_s *figure_temp);

int fill_point(figure_s *figure, FILE *f);

figure_s *create_figure();

void destruct_all(figure_s *figure, figure_s *projections);

#endif