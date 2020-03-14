#include "constants.h"
#include "paint.h"

// Рисуем контур.
void draw_contour(cairo_t *cr, int width, int height)
{
    cairo_set_line_width(cr, 1); // Толщина линии.
    cairo_set_source_rgb(cr, BLUE);

    cairo_move_to(cr, 0, 0);
    cairo_line_to(cr, width, 0);

    cairo_move_to(cr, width, 0);
    cairo_line_to(cr, width, height);

    cairo_move_to(cr, width, height);
    cairo_line_to(cr, 0, height);

    cairo_move_to(cr, 0, height);
    cairo_line_to(cr, 0, 0);

    cairo_stroke(cr);
}

// Рисуем оси.
void draw_coordinate_axes(cairo_t *cr, int width, int height)
{
    cairo_set_line_width(cr, 1);
    cairo_set_source_rgb(cr, BLUE);

    cairo_move_to(cr, 0, height / 2);
    cairo_line_to(cr, width, height / 2);

    cairo_move_to(cr, width / 2, 0);
    cairo_line_to(cr, width / 2, height);

    cairo_move_to(cr, width, 0);
    cairo_line_to(cr, 0, height);

    cairo_stroke(cr);
}

// Рисуем фигуру.
void draw_figure(cairo_t *cr, figure_s *figure, int width, int height)
{
    int index1, index2;

    cairo_set_source_rgb(cr, TURQUOISE);
    for (int i = 0; i < figure->count_connections; i++)
    {
        index1 = figure->list_connections[i][0];
        index2 = figure->list_connections[i][1];
        cairo_move_to(cr, figure->list_points[index1][0] + width / 2, -figure->list_points[index1][1] + height / 2);
        cairo_line_to(cr, figure->list_points[index2][0] + width / 2, -figure->list_points[index2][1] + height / 2);
    }
    cairo_stroke(cr);
}

gboolean on_draw1_draw(GtkWidget *widget, cairo_t *cr, projections_s *projections)
{
    static int a = 5;
    a += 50;

    guint width = gtk_widget_get_allocated_width(widget);
    guint height = gtk_widget_get_allocated_height(widget);

    cairo_set_line_width(cr, 1);
    cairo_set_source_rgb(cr, BLUE);

    cairo_move_to(cr, width / 2, height / 2);
    cairo_line_to(cr, a, a);

    draw_contour(cr, width, height);
    draw_coordinate_axes(cr, width, height);
    // draw_figure(cr, my_struct->figure, width, height);

    return FALSE;
}