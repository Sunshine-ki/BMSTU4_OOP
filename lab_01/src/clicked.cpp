// #include "functions_geometry.h"
// #include "figure_cdio.h"

#include <stdio.h>

#include "clicked.h"
#include "task_manager.h"
#include "constants.h"
#include "figure_cdio.h"
#include "projections_cdio.h"

#include <math.h>
#include <string.h>

#define ERROR_EMPTY_INPUT -10
#define ERROR_INPUT_SYMBOL -11

#define STRING_ERROR_INPUT "qwertyuiop[]asdfghjkl;'zxcvbnm/"

int parse_data(my_struct_s *my_struct)
{
    char user_answer[64];

    for (int i = 0; i < 3; i++)
    {
        strcpy(user_answer, gtk_entry_get_text(GTK_ENTRY(my_struct->entry[i])));
        if (!strcmp(user_answer, ""))
            return ERROR_EMPTY_INPUT;
        if (strpbrk(user_answer, STRING_ERROR_INPUT) != NULL)
            return ERROR_INPUT_SYMBOL;
        // printf("%s \n", user_answer);
        my_struct->event.args[i] = atof(user_answer);
    }

    return OK;
}

void on_button1_clicked(GtkButton *b, my_struct_s *my_struct)
{
    int command = atoi(gtk_button_get_label(GTK_BUTTON(b)));
    int err_answer = parse_data(my_struct);

    if (err_answer)
    {
        printf("ERROR = %d\n", err_answer);
        return;
    }

    // for (int i = 0; i < 3; i++)
    //     printf("%lf \n", my_struct->event.args[i]);

    int err = task_manager(my_struct->event, command);

    if (err)
    {
        printf("Ошибка: %d", err);
        return;
    }

    // print_figure(stdout, my_struct->figure);
    // print_projections(stdout, my_struct->event.projections);

    gtk_widget_queue_draw(my_struct->canvas);
}

void function_upload_file(GtkButton *b, my_struct_s *my_struct)
{
    // printf("Загрузить файл.\n");
    strcpy(my_struct->event.file_name, gtk_entry_get_text(GTK_ENTRY(my_struct->entry_name_file)));
    // printf("NAME FILE %s\n", my_struct->event.file_name);

    int err = task_manager(my_struct->event, LOAD_FILE);

    if (err)
    {
        printf("Ошибка: %d", err);
        return;
    }

    // print_figure(stdout, my_struct->figure);

    gtk_widget_queue_draw(my_struct->canvas);
}
