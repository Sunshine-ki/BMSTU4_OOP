#ifndef _FIGURE_CDIO_H_

#define _FIGURE_CDIO_H_

#include "error_constants.h"
#include "struct.h"
#include "constants.h"

figure_s *create_figure();

int fill_figure(figure_s *figure_temp);

void destruct_figure(figure_s *figure_temp);

void print_figure(FILE *f, figure_s const *const figure_temp);

int fill_connections(FILE *f, figure_s *figure);

int fill_point(FILE *f, figure_s *figure);

#endif