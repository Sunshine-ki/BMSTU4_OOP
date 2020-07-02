#include <iostream>

using namespace std; 

#include "windows.h"

using namespace std;

void create_windows()
{
	GtkWidget *window;
	GtkBuilder *builder;

	builder = gtk_builder_new_from_file(GLADE_FILE);

	window_settings(builder, &window);

	signal_connect(builder, window);
}

void destroy_windows(GtkWidget *widget)
{
	// task_manager(my_struct->projections, my_struct->event, QUIT);
	// destruct_figure(my_struct->projections);
	gtk_main_quit();
}


void signal_connect(GtkBuilder *builder, GtkWidget *window)
{
	myWindows userWindows;

	GtkWidget *button1, *button2, *button3;
	GtkWidget *button_upload_file;

	userWindows.canvas = GTK_WIDGET(gtk_builder_get_object(builder, "canvas"));

	button_settings(builder, &button1, &button2, &button3);

	button_upload_file = GTK_WIDGET(gtk_builder_get_object(builder, "upload_file"));

	actions_settings(builder, userWindows);
	
	userWindows.entryFileName = GTK_WIDGET(gtk_builder_get_object(builder, "entry_name_file"));

	// g_signal_connect(window, "destroy", G_CALLBACK(destroy_windows), &moving_s);
	g_signal_connect(window, "destroy", gtk_main_quit, NULL);

	g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(clicked), &userWindows);
	g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(clicked), &userWindows);
	g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(clicked), &userWindows);
	g_signal_connect(G_OBJECT(button_upload_file), "clicked", G_CALLBACK(clicked), &userWindows);


	// Тут нужно привязать менеджер сцены, так как он содержит объекты, которые нужно рисовать.
	int a = 1;
	g_signal_connect(G_OBJECT(userWindows.canvas), "draw", G_CALLBACK(draw), &a);

	gtk_widget_show(window);

	gtk_main();
}