#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Object.h"
#include "Renderer.h"

class Scene {
public:
	Object* objects[128];
	Renderer* renderer;
	int index;
	std::string name; 
	sf::Sprite background;
	Scene* leftScene = nullptr;
	Scene* rightScene = nullptr;
	Scene(Renderer* renderer_in, int index_in,std::string name_in) {
		renderer = renderer_in;
		index = index_in;
		name = name_in;
		start();
	}
	Scene() {
		//defualt
	}
	void start() {

	}
	void update() {
		//std::cout << "scene update" << std::endl;
		//renderer->drawBG(bgSprite);
		for (int i = 0; i < 128; i++) {
			objects[i]->update();
		}
		for (int i = 0; i < 128; i++) {
			objects[i]->draw();
		}
	}
private:
};