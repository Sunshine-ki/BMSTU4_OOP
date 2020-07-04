#pragma once 

#include <iterator>
#include <iostream>
#include <vector>
#include <memory>

#include "objects.h"

using VectorComponent = std::vector<std::shared_ptr<Object>>;

class Scene
{
private:
	VectorComponent Component; // Вектор сцен.
    int _curScene = -1;
public:
	Scene();
	void addComponent(std::shared_ptr<Object> obj);
	std::shared_ptr<Object> getComponent(size_t index); // Возвращает сцену по индексу.
	size_t getCount(); // Возвращает кол-во элементов в текущей сцене.
	//
	void print();
};

