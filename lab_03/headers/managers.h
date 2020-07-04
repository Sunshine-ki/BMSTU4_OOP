#pragma once 

#include <iterator>
#include <iostream>
#include <vector>
#include <memory>

#include "scene.h"
#include "constants.h"

class SceneManager: public Scene
{
private:
    Scene _scene;
    int _curCam = -1, _curFigure = -1, _curScene = 0;
public:
	void addComponent(std::shared_ptr<Object> obj);
	std::shared_ptr<Object> getComponent(TypeObject typeObj);

};
