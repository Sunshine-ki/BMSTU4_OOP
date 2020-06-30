#pragma once

#include <gtk/gtk.h>

#include "constants.h"
#include "struct.h"

void draw_figure(cairo_t *cr, int width, int height);

void draw_coordinate_axes(cairo_t *cr, int width, int height);

void draw_contour(cairo_t *cr, int width, int height);

void draw(GtkWidget *widget, cairo_t *cr, int &a);
