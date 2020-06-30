#include <iostream>

using namespace std; 

#include "windows.h"

#include "figure.h"

#include "builder.h"

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

void test()
{
	shared_ptr<BaseFigureBuilder> builder(new FigureBuilder());
	shared_ptr<Director> director(new Director(builder));

	std::vector<Point> points;
	std::vector<Link> links;

	for (size_t i = 0; i < 5; i++)
	{
		Point p(i ,i,i);
		Link l(i + 1, i + 1); 
		points.push_back(p);
		links.push_back(l);
	}

	shared_ptr<Figure> result = director->createFigure(points, links);
	
	result->print();

	// Figure figure;
	// Point p;
	// Link l;
	// for (size_t i = 0; i < 5; i++)
	// {
	// 	p.set(i,i,i);
	// 	l.set(i,i);
	// 	figure.addPoint(p);
	// 	figure.addLink(l);
	// }
	// figure.print();


	////////////
	//


	// Figure figure;
	
	// figure.setPoints(points);
	// figure.setLinks(links);

	// vector<Point> pointsResult = figure.getPoints(); 
	// vector<Link> linksResult = figure.getLinks(); 

	// for (size_t i = 0; i < 5; i++)
	// {
	// 	cout  << pointsResult[i].getX() << " ";
	// 	cout  << linksResult[i].getFirst() << endl;
	// }

	
	// // for transform
	// cout << endl;

	// for (size_t i = 0; i < pointsResult.size(); i++)
	// {
	// 	double x = pointsResult[i].getX();
	// 	pointsResult[i].set(x-10,10,10);
	// }

	// figure.setPoints(pointsResult);


	// for (size_t i = 0; i < 5; i++)
	// {
	// 	cout  << pointsResult[i].getX() << " ";
	// 	// cout  << linksResult[i].getFirst() << endl;
	// }


	// cout << endl;

	// // Clone.

	// shared_ptr<BaseFigure> figureClone = figure.clone();

	// vector<Point> pointsResultClone = figure.getPoints(); 
	// vector<Link> linksResultClone = figure.getLinks(); 

	// for (size_t i = 0; i < 5; i++)
	// {
	// 	cout  << pointsResultClone[i].getX() << " ";
	// 	cout  << linksResultClone[i].getFirst() << endl;
	// }
	// cout << endl;
}


void signal_connect(GtkBuilder *builder, GtkWidget *window)
{
	test();

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