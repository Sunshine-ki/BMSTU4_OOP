#include "settings_windows.h"
#include "constants.h"
#include "windows.h"
#include "clicked.h"
#include "paint.h"
#include "struct.h"
#include "task_manager.h"
#include "projections_cdio.h"

void actions_settings(GtkBuilder *builder, my_struct_s &moving_s, my_struct_s &rotate_s, my_struct_s &scale_s)
{
    const char *entry_names[9] = {"entry1", "entry2", "entry3",
                                  "entry4", "entry5", "entry6",
                                  "entry7", "entry8", "entry9"};

    for (int i = 0; i < 3; i++)
    {
        moving_s.entry[i] = GTK_WIDGET(gtk_builder_get_object(builder, entry_names[i]));
        rotate_s.entry[i] = GTK_WIDGET(gtk_builder_get_object(builder, entry_names[i + 3]));
        scale_s.entry[i] = GTK_WIDGET(gtk_builder_get_object(builder, entry_names[i + 6]));
    }
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

    scale_s.event.projections = (moving_s.event.projections = (rotate_s.event.projections = (upload_file.event.projections = create_projections())));

    button_settings(builder, &button1, &button2, &button3);

    button_upload_file = GTK_WIDGET(gtk_builder_get_object(builder, "upload_file"));

    actions_settings(builder, moving_s, rotate_s, scale_s);

    upload_file.entry_name_file = GTK_WIDGET(gtk_builder_get_object(builder, "entry_name_file"));

    g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(on_button1_clicked), &moving_s);
    g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(on_button1_clicked), &rotate_s);
    g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(on_button1_clicked), &scale_s);

    g_signal_connect(G_OBJECT(button_upload_file), "clicked", G_CALLBACK(function_upload_file), &upload_file);

    upload_file.event.projections->count_points = 0;
    printf("AA%dAA ", upload_file.event.projections->count_points);

    g_signal_connect(G_OBJECT(upload_file.canvas), "draw", G_CALLBACK(on_draw1_draw), moving_s.event.projections);

    gtk_widget_show(window);

    gtk_main();
}

void create_windows()
{

    GtkWidget *window;
    GtkBuilder *builder;

    builder = gtk_builder_new_from_file(GLADE_FILE);

    window_settings(builder, &window);

    signal_connect(builder, window);
}
