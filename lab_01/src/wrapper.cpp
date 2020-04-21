#include "wrapper.h"

int function_moving_wrapper(figure_s *figure_temp, args_s arguments)
{
	return function_moving(figure_temp, arguments.args);
}

int function_scale_wrapper(figure_s *figure_temp, args_s arguments)
{
	return function_scale(figure_temp, arguments.args);
}

int function_rotate_wrapper(figure_s *figure_temp, args_s arguments)
{
	return function_rotate(figure_temp, arguments.args);
}

int fill_figure_wrapper(figure_s **figure_p, file_name_s file_name)
{
	return fill_figure(figure_p, file_name.name);
}