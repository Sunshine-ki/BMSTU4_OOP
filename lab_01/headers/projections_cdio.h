#ifndef _PROJECTIONS_CDIO_H_

#define _PROJECTIONS_CDIO_H_

#include "struct.h"

void fill_projections(projections_s *projections, figure_s *figure);

int update_projections(projections_s *projections, figure_s const *const figure);

void destruct_projections(projections_s *projections);

void print_projections(FILE *f, projections_s const *const projections);

projections_s *create_projections();

#endif