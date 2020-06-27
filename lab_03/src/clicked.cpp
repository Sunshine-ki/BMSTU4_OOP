#include <iostream>

using namespace std;

#include "parse_data.h"
#include "clicked.h"

enum Command {
    MOVE = 1, ROTATE, SCALE, LOAD_FILE
};

int parseData(int args[3], GtkWidget *entries[3])
{
	char userAnswer[64];

	for (size_t i = 0; i < 3; i++)
	{
		strcpy(userAnswer, gtk_entry_get_text(GTK_ENTRY(entries[i])));
		if (!strcmp(userAnswer, ""))
			return ERROR_EMPTY_INPUT;
		if (strpbrk(userAnswer, STRING_ERROR_INPUT) != NULL)
			return ERROR_INPUT_SYMBOL;
		args[i] = atof(userAnswer);
	}

	return OK;
}

void clicked(GtkButton *b, myWindows &userWindows)
{
	int command = atoi(gtk_button_get_label(GTK_BUTTON(b)));
	int args[3] = {0};

	switch (command)
	{
	case Command::MOVE:
		cout << "MOVE\n";
		parseData(args, userWindows.entryMove);
		break;
	case Command::ROTATE:
		cout << "ROTATE\n";
		parseData(args, userWindows.entryRotate);
		break;
	case Command::SCALE:
		cout << "SCALE\n";
		parseData(args, userWindows.entryScale);
		break;
	case Command::LOAD_FILE:
		cout << "LOAD_FILE\n";
		char name[64];
		strcpy(name, gtk_entry_get_text(GTK_ENTRY(userWindows.entryFileName)));
		cout << name;
		break;
	default:
		cout << "I don't know this command \n";
		break;
	}

	// for (size_t i = 0; i < 3; i++)
	// 	cout << args[i] << " ";
	
	gtk_widget_queue_draw(userWindows.canvas);
}
