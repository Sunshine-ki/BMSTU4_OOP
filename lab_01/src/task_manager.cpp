#include <stdio.h>

#include "task_manager.h"
#include "clicked.h"
#include "constants.h"
#include "figure_cdio.h"

// #include "functions_geometry.h"

int task_manager(event_s event, int command)
{
    int err = OK;
    static figure_s *figure = create_figure();

    switch (command)
    {
    case MOVING:
        // err = function_moving(my_struct->figure, parse_data(my_struct));
        printf("Вращай.\n");

        break;
    case ROTATE:
        // err = function_rotate(my_struct->figure, parse_data(my_struct));
        break;
    case SCALE:
        // err = function_scale(my_struct->figure, parse_data(my_struct));
        break;
    case LOAD_FILE:
        err = fill_figure(figure); // + NAME!!!
        break;
    }

    // print_figure(stdout, my_struct->figure);

    return err;
}