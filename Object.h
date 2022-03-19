#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SceneState.h"
class Object
{
public:
	sf::Vector2f position;
	Object() {
		start();
	}
	Object(sf::Vector2f position_in) {
		position = position_in;
		start();
	}

	virtual void start() {

	}
	virtual void update() {//scenestate afsjkskjfskjkskjsf

	}
};

