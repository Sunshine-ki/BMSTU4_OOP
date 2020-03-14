#include "settings_windows.h"

void window_settings(GtkBuilder *builder, GtkWidget **window_p)
{
    GtkWidget *window = *window_p;

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    gtk_window_set_title(GTK_WINDOW(window), "Автокад");
    gtk_window_set_keep_above(GTK_WINDOW(window), TRUE); // Чтобы всегда было активно.

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    *window_p = window;
}

void button_settings(GtkBuilder *builder, GtkWidget **button1_p, GtkWidget **button2_p, GtkWidget **button3_p)
{
    *button1_p = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    *button2_p = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
    *button3_p = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
}