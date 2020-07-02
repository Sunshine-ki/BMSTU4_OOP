#include "facade.h"

void Facade::executeCommand(std::shared_ptr<CommandBase> command)
{
	command->execute(controller);
}