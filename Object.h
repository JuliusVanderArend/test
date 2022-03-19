#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Object
{
public:
	sf::Vector2f position;
	std::string tag = "default";
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

