
#include <iostream>
#include <string>

using namespace std;

#include "parse_data.h"
#include "clicked.h"

#include "command.h"

void moveClicked(double args[3], char charChoice, Facade &facade)
{
	cout << "MOVE\n";
	cout << "Args: " << args[0] << " " << args[1] << " " << args[2] << std::endl;
	cout << "Choice = " << charChoice << std::endl;

	if (charChoice == 'f')
	{
		// Фигура.
		std::shared_ptr<CommandBase> command(new MoveFigureCommand());
		facade.executeCommand(command);

	}
	else if(charChoice == 'c')
	{
		// Камера.
		std::shared_ptr<CommandBase> command(new MoveCameraCommand());
		facade.executeCommand(command);

	}
	else if(charChoice == 's')
	{
		// Сцена.
		std::shared_ptr<CommandBase> command(new MoveSceneCommand());
		facade.executeCommand(command);

	}

}

void scaleClicked(double args[3], char charChoice, Facade &facade)
{
	cout << "SCALE\n";
	cout << "Args: " << args[0] << " " << args[1] << " " << args[2] << std::endl;
	cout << "Choice = " << charChoice << std::endl;

	if (charChoice == 'f')
	{
		// Фигура.
		std::shared_ptr<CommandBase> command(new ScaleFigureCommand());
		facade.executeCommand(command);

	}
	else if(charChoice == 'c')
	{
		// Камера.
	}
	else if(charChoice == 's')
	{
		// Сцена.
		std::shared_ptr<CommandBase> command(new ScaleSceneCommand());
		facade.executeCommand(command);

	}

}

void rotateClicked(double args[3], char charChoice, Facade &facade)
{
	cout << "ROTATE\n";
	cout << "Args: " << args[0] << " " << args[1] << " " << args[2] << std::endl;
	cout << "Choice = " << charChoice << std::endl;

	if (charChoice == 'f')
	{
		// Фигура.
		std::shared_ptr<CommandBase> command(new RotateFigureCommand());
		facade.executeCommand(command);

	}
	else if(charChoice == 'c')
	{
		// Камера.
		std::shared_ptr<CommandBase> command(new RotateCameraCommand());
		facade.executeCommand(command);

	}
	else if(charChoice == 's')
	{
		// Сцена.
		std::shared_ptr<CommandBase> command(new RotateSceneCommand());
		facade.executeCommand(command);

	}

}

void loadClicked(string name, char charChoice, Facade &facade)
{
	cout << "LOAD_FILE\n";
	cout << "name = " << name << std::endl;
	cout << "Choice = " << charChoice << std::endl;

	if (charChoice == 'f')
	{
		// Фигура.
		std::shared_ptr<CommandBase> command(new AddFigureCommand(name));
		facade.executeCommand(command);

	}
	else if(charChoice == 'c')
	{
		// Камера.
		std::shared_ptr<CommandBase> command(new AddCameraCommand(name));
		facade.executeCommand(command);

	}
	else if(charChoice == 's')
	{
		// Сцена.
		std::shared_ptr<CommandBase> command(new AddSceneCommand(name));
		facade.executeCommand(command);

	}
}


void clicked(GtkButton *b, myWindows &userWindows)
{
	int err;
	int command = atoi(gtk_button_get_label(GTK_BUTTON(b)));
	double args[3] = {0};
	string userChoice =  gtk_entry_get_text(GTK_ENTRY(userWindows.choice));
	char charChoice = userChoice[0];
	string name;
	
	switch (command)
	{
	case Command::MOVE:
		err = parseData(args, userWindows.entryMove);
		if (err)
			cout << err << endl;
		moveClicked(args, charChoice, userWindows.facade);
		break;
	case Command::ROTATE:
		err = parseData(args, userWindows.entryRotate);
		if (err)
			cout << err << endl;
		rotateClicked(args, charChoice, userWindows.facade);
		break;
	case Command::SCALE:
		err = parseData(args, userWindows.entryScale);
		if (err)
			cout << err << endl;
		scaleClicked(args, charChoice, userWindows.facade);
		break;
	case Command::LOAD_FILE: 
		name =  gtk_entry_get_text(GTK_ENTRY(userWindows.entryFileName));
		loadClicked(name, charChoice, userWindows.facade);
		break;
	default:
		cout << "I don't know this command \n";
		break;
	}


	gtk_widget_queue_draw(userWindows.canvas);
}

