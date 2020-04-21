#ifndef _WRAPPER_H_

#define _WRAPPER_H_

#include "struct.h"
#include "constants.h"
#include "error_constants.h"

#include "functions_geometry.h"
#include "figure_cdio.h"

int function_moving_wrapper(figure_s *figure_temp, args_s arguments);

int function_scale_wrapper(figure_s *figure_temp, args_s arguments);

int function_rotate_wrapper(figure_s *figure_temp, args_s arguments);

int fill_figure_wrapper(figure_s **figure_p, file_name_s file_name);

#endif