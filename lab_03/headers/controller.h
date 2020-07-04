#pragma once

#include <iostream>
#include <memory>
#include <string.h>

#include "managers.h"
#include "loader.h"

class Controller
{
private:
	SceneManager _sceneManager;
	std::shared_ptr<Loader> _loader;
	// Тут должны быть менеджеры.
public:
	Controller();// : loaderFile(new FileLoader()) {}
	void draw();
	void addFigure(std::string fileName);
	void addCamera(std::string fileName);
	void addScene(std::string fileName);
	void transformCamera();
	void transformModel();
	void transformScene();
};
