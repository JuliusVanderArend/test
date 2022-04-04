#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#include "Renderer.h"

class SpriteOBJ : public Object {
public:
	Sprite sprite;
	Renderer* renderer;
	SpriteOBJ(sf::Vector2f pos,Sprite sprite_in, Renderer* renderer_in) {
		sprite = sprite_in;;
		renderer = renderer_in;
		tag = "sprite";
		position = pos;
		sprite.sprite.setPosition(position);
	}
	void update() {
		
	}
	void draw() {
		renderer->draw(sprite);
	}
};
