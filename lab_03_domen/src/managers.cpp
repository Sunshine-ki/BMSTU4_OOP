#include "managers.h"

void SceneManager::addComponent(std::shared_ptr<Object> obj)
{
	// std::cout << "COUNT = " << _scene.getCount() << std::endl;
	if (obj->isComposite())
	{
		_curCam = -1;
		_curFigure = -1;
		_curScene++;
	}
	else if (obj->isVisible())
	{
		// Добавление фигуры.
		std::cout << "Фигуру\n";
		_curFigure = _scene.getCount();
	}
	else
	{
		// Добавление камеры.
		std::cout << "Камеру\n";
		_curCam = _scene.getCount();
	}
	_scene.addComponent(obj);	
}

std::shared_ptr<Object> SceneManager::getComponent(TypeObject typeObj)
{
	// std::cout << "_curScene (int sceneManager) = " << _curScene << std::endl;
    // std::shared_ptr<Object> composit = scene.getComponent(0);

	if (typeObj == TypeObject::FIGURE)
	{
		if (_curFigure == -1)
		{
			std::shared_ptr<Object> t;
			return t;
		}
		std::cout << "getComponent (type: FIGURE)\n\n";
		std::cout << "_curFigure = " << _curFigure << "\n";

		auto temp = _scene.getComponent(_curScene);
		auto it = temp->begin();
		int i = 0;
		while (it != temp->end()) 
		{
			if (i == _curFigure)
				break;
			std::cout << "next it figure";
			it++;
			i++;
		}

		return *it;
	}
	else if (typeObj == TypeObject::CAMERA)
	{
		if (_curCam == -1)
		{
			std::shared_ptr<Object> t;
			return t;
		}
		std::cout << "getComponent (type: CAMERA)\n\n";
		std::cout << "!!! _curCam = " << _curCam << "\n";

		auto temp = _scene.getComponent(_curScene);
		auto it = temp->begin();
		int i = 0;
		while (it != temp->end()) 
		{
			if (i == _curCam)
				break;
			std::cout << "next it Cam";
			it++;
			i++;
		}

		return *it;
	}
	else
	{
		std::cout << "getComponent (type: SCENE)\n\n";
		std::cout << "!!! _curScene = " << _curScene << "\n";
		return _scene.getComponent(_curScene);
	}
}
