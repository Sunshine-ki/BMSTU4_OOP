#pragma once

#include <iostream>
#include <memory>

#include "command.h"
#include "controller.h"

class Facade
{
private:
	std::shared_ptr<Controller> controller; 
public:
	void executeCommand(std::shared_ptr<CommandBase> command);
};

