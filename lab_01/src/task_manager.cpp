#include <stdio.h>

#include "task_manager.h"

int task_manager(event_s &event, int command)
{
    int err = OK;
    static figure_s *figure = create_figure(); // (x, y, z, 1)

    switch (command)
    {
    case MOVING:
        err = function_moving(figure, event.args);
        break;
    case ROTATE:
        err = function_rotate(figure, event.args);
        break;
    case SCALE:
        err = function_scale(figure, event.args);
        break;
    case LOAD_FILE:
        err = fill_figure(figure, event.file_name);
        if (err)
            return err;
        err = update_projections(event.projections, figure);
        break;
    }

    fill_projections(event.projections, figure);

    return err;
}