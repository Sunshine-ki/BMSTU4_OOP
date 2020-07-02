#pragma once

class Controller
{
private:
	// Тут должны быть менеджеры.
public:
	void draw();
	void addFigure();
	void addCamera();
	void addScene();
	void transformCamera();
	void transformModel();
	void transformScene();
};