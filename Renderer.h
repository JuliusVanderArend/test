#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class Renderer {
public:
	sf::RenderWindow *window;
	Renderer() {
		//default constructor
	}
	Renderer(sf::RenderWindow *window_in) {
		window = window_in;
	}
	void draw(Sprite sprite) {
		window->draw(sprite.sprite,sprite.material.shader);
	}

};

#endif 