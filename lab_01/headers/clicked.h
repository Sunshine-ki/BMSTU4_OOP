#ifndef _CLICKED_H_

#define _CLICKED_H_

#include <gtk/gtk.h>
#include "struct.h"

void function_upload_file(GtkButton *b, my_struct_s *my_struct);

void on_button1_clicked(GtkButton *b, my_struct_s *my_struct);

// double *parse_data(my_struct_s *my_struct);

// int task_manager(GtkButton *b, my_struct_s *my_struct);

#endif