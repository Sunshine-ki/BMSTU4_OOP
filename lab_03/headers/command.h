#pragma once

#include <iostream>
#include <memory>

#include "controller.h"

class CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) = 0; // Controller
};

////////////////////////////////////

class AddFigureCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Загрузить фигуру" << std::endl;}
};

class AddCameraCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Загрузить камеру" << std::endl;}
};

class AddSceneCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Загрузить сцену" << std::endl;}
};

////////////////////////////////////

class MoveFigureCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Move figure" << std::endl;}
};

class RotateFigureCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Rotate figure" << std::endl;}
};

class ScaleFigureCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Scale figure" << std::endl;}
};

////////////////////////////////////

class MoveCameraCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Move camera" << std::endl;}
};

class RotateCameraCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Rotate camera" << std::endl;}
};

////////////////////////////////////

class MoveSceneCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Move Scene" << std::endl;}
};

class RotateSceneCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Rotate Scene" << std::endl;}
};

class ScaleSceneCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {std::cout << "Scale Scene" << std::endl;}
};

////////////////////////////////////

class DrawCommand: public CommandBase
{
public:
	virtual void execute(std::shared_ptr<Controller> controller) override {}
};