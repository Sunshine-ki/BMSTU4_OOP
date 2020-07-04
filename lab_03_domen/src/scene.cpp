#include "scene.h"

Scene::Scene()
{
    std::shared_ptr<Object> newScene(new Composite());
	addComponent(newScene);
}

void Scene::addComponent(std::shared_ptr<Object> obj)
{
	if (obj->isComposite())
	{
		std::cout << "Добавили сцену\n" << std::endl;
		_curScene++;
		Component.push_back(obj);
		// std::cout << "aaa" << Component.size() << std::endl;
	}
	else 
	{
		if (_curScene == -1)
		{
			std::cout << "Добавили первую сцену\n";
			_curScene++;
			std::shared_ptr<Object> newScene(new Composite());
			Component.push_back(newScene);
		}
		std::cout << "Добавили компонент\n";
		Component[_curScene]->add(obj);
	}
	// std::cout << obj->isComposite() << std::endl;
	// std::cout << obj->isVisible() << std::endl;
}

std::shared_ptr<Object> Scene::getComponent(size_t index)
{
	if (index > _curScene)
	{
		std::cout << "Error getComponent";
		std::shared_ptr<Object> result;
		return result;
	}
	return Component[index];
}

size_t Scene::getCount()
{
	// std::cout << "_curScene = " << _curScene << std::endl; 
	// if (_curScene != -1)
	return Component[_curScene]->getSize();
}




// void Scene::print()
// {
// 	std::cout << _curScene; 
// }
