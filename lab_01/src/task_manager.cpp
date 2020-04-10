#include <stdio.h>

#include "task_manager.h"

int task_manager(event_s &event, const int command)
{
	int err = OK;
	static figure_s *figure = create_figure(); // (x, y, z, 1)
											   // освобождать. ok
											   //data , command, struct. (?)
											   // figures/figure.txt
	switch (command)
	{
	case MOVING:
		err = function_moving_wrapper(figure, event.arguments);
		break;
	case ROTATE:
		err = function_rotate_wrapper(figure, event.arguments);
		break;
	case SCALE:
		err = function_scale_wrapper(figure, event.arguments);
		break;
	case LOAD_FILE:
		err = fill_figure_wrapper(&figure, event.file_name);
		break;
	case UPDATE_PROJECTIONS:
		err = update_projections(event.projections, figure);
	case FILL_PROJECTIONS:
		err = fill_projections(event.projections, figure);
		break;
	case QUIT:
		destruct_all(figure, event.projections);
		break;
	default: // конец. ok
		err = ERROR_COMMAND;
		break;
	}

	return err;
}