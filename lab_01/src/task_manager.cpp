#include <stdio.h>

#include "task_manager.h"

int task_manager(figure_s *projections, event_s &event, const int command)
{
	int err = OK;
	static figure_s *figure = create_figure(); // (x, y, z, 1)
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
		err = update_projections(&projections, figure);
		// Избавиться от копирования. ok
		break;
	case QUIT:
		//  Чистить тут только figure. ok.
		//  event.projections Чистит в интерфейсе. ok.
		destruct_figure(figure);
		break;
	default:
		err = ERROR_COMMAND;
		break;
	}

	return err;
}