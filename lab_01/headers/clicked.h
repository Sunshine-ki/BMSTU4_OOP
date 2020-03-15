#ifndef _CLICKED_H_

#define _CLICKED_H_

#include <gtk/gtk.h>
#include <string.h>

#include "task_manager.h"
#include "projections.h"

#include "error_constants.h"
#include "constants.h"
#include "struct.h"

void function_upload_file(GtkButton *b, my_struct_s *my_struct);

void on_button_clicked(GtkButton *b, my_struct_s *my_struct);

#endif