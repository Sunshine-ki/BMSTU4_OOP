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
void draw_figure(cairo_t *cr, figure_s *projections, int width, int height)
{
	int index1, index2;

	cairo_set_source_rgb(cr, TURQUOISE);
	for (int i = 0; i < projections->count_connections; i++)
	{
		index1 = projections->list_connections[i][0];
		index2 = projections->list_connections[i][1];
		cairo_move_to(cr, projections->list_points[index1][0] + width / 2, -projections->list_points[index1][1] + height / 2);
		cairo_line_to(cr, projections->list_points[index2][0] + width / 2, -projections->list_points[index2][1] + height / 2);
	}
	cairo_stroke(cr);
}

void draw(GtkWidget *widget, cairo_t *cr, figure_s *projections)
{
	guint width = gtk_widget_get_allocated_width(widget);
	guint height = gtk_widget_get_allocated_height(widget);

	draw_contour(cr, width, height);
	draw_coordinate_axes(cr, width, height);
	draw_figure(cr, projections, width, height);

	// print_figure(stdout, projections);
}