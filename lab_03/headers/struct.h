#pragma once

#include <gtk/gtk.h>

#include "facade.h"

class myWindows
{
public:
	GtkWidget *canvas;
	GtkWidget *entryRotate[3];
	GtkWidget *entryScale[3];
	GtkWidget *entryMove[3];
	GtkWidget *entryFileName;
	GtkWidget *choice;
	Facade facade;
};

