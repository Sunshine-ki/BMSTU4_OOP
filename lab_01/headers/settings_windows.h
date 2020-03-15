#ifndef _SETTINGS_WINDOWS_H_

#define _SETTINGS_WINDOWS_H_

#include <gtk/gtk.h>

#include "struct.h"

void window_settings(GtkBuilder *builder, GtkWidget **window_p);

void button_settings(GtkBuilder *builder, GtkWidget **button1_p, GtkWidget **button2_p, GtkWidget **button3_p);

void actions_settings(GtkBuilder *builder, my_struct_s &moving_s, my_struct_s &rotate_s, my_struct_s &scale_s);

#endif