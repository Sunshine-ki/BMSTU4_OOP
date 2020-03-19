#include "parse_data.h"
#include "clicked.h"

void on_button_clicked(GtkButton *b, my_struct_s *my_struct)
{
	int command = atoi(gtk_button_get_label(GTK_BUTTON(b)));
	int err_answer = parse_data(my_struct);

	if (err_answer)
	{
		printf("ERROR = %d\n", err_answer);
		return;
	}

	int err = task_manager(my_struct->event, command);

	if (err)
	{
		printf("Ошибка: %d", err);
		return;
	}

	err = task_manager(my_struct->event, FILL_PROJECTIONS);

	if (err)
	{
		printf("Ошибка: %d\n", err);
		return;
	}

	gtk_widget_queue_draw(my_struct->canvas);
}

void function_upload_file(GtkButton *b, my_struct_s *my_struct)
{
	strcpy(my_struct->event.file_name, gtk_entry_get_text(GTK_ENTRY(my_struct->entry_name_file)));
	int command = atoi(gtk_button_get_label(GTK_BUTTON(b)));

	int err = task_manager(my_struct->event, command);

	if (err)
	{
		printf("Ошибка: %d\n", err);
		return;
	}

	// print_figure(stdout, my_struct->figure);

	err = task_manager(my_struct->event, FILL_PROJECTIONS);

	if (err)
	{
		printf("Ошибка: %d\n", err);
		return;
	}

	gtk_widget_queue_draw(my_struct->canvas);
}
