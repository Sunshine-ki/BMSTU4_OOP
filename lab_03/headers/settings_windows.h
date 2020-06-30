#pragma once

#include <gtk/gtk.h>

#include "struct.h"

void window_settings(GtkBuilder *builder, GtkWidget **window_p);

void button_settings(GtkBuilder *builder, GtkWidget **button1_p, GtkWidget **button2_p, GtkWidget **button3_p);

void actions_settings(GtkBuilder *builder, myWindows &userWindows);
