#pragma once

#include "settings_windows.h"
#include "clicked.h"
#include "paint.h"

#include "constants.h"
#include "struct.h"

void create_windows();

void destroy_windows(GtkWidget *widget);

void signal_connect(GtkBuilder *builder, GtkWidget *window);
