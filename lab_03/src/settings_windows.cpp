#include "settings_windows.h"
#include "windows.h"

void actions_settings(GtkBuilder *builder, myWindows &userWindows)
{
	const char *entry_names[9] = {"entry1", "entry2", "entry3",
								  "entry4", "entry5", "entry6",
								  "entry7", "entry8", "entry9"};

	for (int i = 0; i < 3; i++)
	{
		userWindows.entryMove[i] = GTK_WIDGET(gtk_builder_get_object(builder, entry_names[i]));
		userWindows.entryRotate[i] = GTK_WIDGET(gtk_builder_get_object(builder, entry_names[i + 3]));
		userWindows.entryScale[i] = GTK_WIDGET(gtk_builder_get_object(builder, entry_names[i + 6]));
	}
	userWindows.choice = GTK_WIDGET(gtk_builder_get_object(builder, "entry_object"));
}

void window_settings(GtkBuilder *builder, GtkWidget **window_p)
{
	GtkWidget *window = *window_p;

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	gtk_window_set_title(GTK_WINDOW(window), "Автокад на паттернах");
	gtk_window_set_keep_above(GTK_WINDOW(window), TRUE); // Чтобы всегда было активно.

	*window_p = window;
}

void button_settings(GtkBuilder *builder, GtkWidget **button1_p, GtkWidget **button2_p, GtkWidget **button3_p)
{
	*button1_p = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
	*button2_p = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
	*button3_p = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
}