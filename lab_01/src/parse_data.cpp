#include "parse_data.h"

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
        my_struct->event.arguments.args[i] = atof(user_answer);
    }

    return OK;
}