#ifndef _PROJECTIONS_H_

#define _PROJECTIONS_H_

#include "struct.h"
#include "constants.h"

#include "figure_cdio.h"

int fill_projections(figure_s *projections, figure_s figure);

int update_projections(figure_s *projections, figure_s const figure);

#endif