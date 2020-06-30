#include <iostream>

using namespace std;

#include "parse_data.h"
#include "clicked.h"

void clicked(GtkButton *b, myWindows &userWindows)
{
	int err;
	int command = atoi(gtk_button_get_label(GTK_BUTTON(b)));
	int args[3] = {0};

	switch (command)
	{
	case Command::MOVE:
		cout << "MOVE\n";
		err = parseData(args, userWindows.entryMove);
		if (err)
			cout << err << endl;
		break;
	case Command::ROTATE:
		cout << "ROTATE\n";
		err = parseData(args, userWindows.entryRotate);
		if (err)
			cout << err << endl;
		break;
	case Command::SCALE:
		cout << "SCALE\n";
		err = parseData(args, userWindows.entryScale);
		if (err)
			cout << err << endl;
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

	for (size_t i = 0; i < 3; i++)
		cout << args[i] << " ";

	gtk_widget_queue_draw(userWindows.canvas);
}
