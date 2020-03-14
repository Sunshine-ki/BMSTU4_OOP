#ifndef _SETTINGS_WINDOWS_H_

#define _SETTINGS_WINDOWS_H_

#include <gtk/gtk.h>

void window_settings(GtkBuilder *builder, GtkWidget **window_p);

void button_settings(GtkBuilder *builder, GtkWidget **button1_p, GtkWidget **button2_p, GtkWidget **button3_p);

#endif