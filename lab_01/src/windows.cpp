#include "windows.h"

void create_windows()
{
	GtkWidget *window;
	GtkBuilder *builder;

	builder = gtk_builder_new_from_file(GLADE_FILE);

	window_settings(builder, &window);

	signal_connect(builder, window);
}

void destroy_windows(GtkWidget *widget, my_struct_s *my_struct)
{
	task_manager(my_struct->projections, my_struct->event, QUIT);
	destruct_figure(my_struct->projections);
	gtk_main_quit();
}

void signal_connect(GtkBuilder *builder, GtkWidget *window)
{
	GtkWidget *button1, *button2, *button3;
	GtkWidget *button_upload_file;

	my_struct_s moving_s; // Структура для перемещения.
	my_struct_s rotate_s; // Структура для вращения.
	my_struct_s scale_s;  // Структура для масштибирования.
	my_struct_s upload_file;

	upload_file.canvas = (moving_s.canvas = (rotate_s.canvas = (scale_s.canvas = GTK_WIDGET(gtk_builder_get_object(builder, "canvas")))));

	scale_s.projections = (moving_s.projections = (rotate_s.projections = (upload_file.projections = create_figure())));

	button_settings(builder, &button1, &button2, &button3);

	button_upload_file = GTK_WIDGET(gtk_builder_get_object(builder, "upload_file"));

	actions_settings(builder, moving_s, rotate_s, scale_s);

	upload_file.entry_name_file = GTK_WIDGET(gtk_builder_get_object(builder, "entry_name_file"));

	g_signal_connect(window, "destroy", G_CALLBACK(destroy_windows), &moving_s);

	g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(on_button_clicked), &moving_s);
	g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(on_button_clicked), &rotate_s);
	g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(on_button_clicked), &scale_s);

	g_signal_connect(G_OBJECT(button_upload_file), "clicked", G_CALLBACK(function_upload_file), &upload_file);

	g_signal_connect(G_OBJECT(upload_file.canvas), "draw", G_CALLBACK(draw), moving_s.projections);

	gtk_widget_show(window);

	gtk_main();
}