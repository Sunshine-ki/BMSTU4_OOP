#ifndef _FUNCTIONS_GEOMETRY_H_

#define _FUNCTIONS_GEOMETRY_H_

#include <math.h>

#include "struct.h"
#include "constants.h"
#include "error_constants.h"

#include "wrapper.h"

int function_moving(figure_s *figure_temp, double *args);

int function_rotate(figure_s *figure_temp, double *args);

int function_scale(figure_s *figure_temp, double *args);

#endif