#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Light.h"
class Player :public Object {
public:
	Object** objects;
	Sprite sprite;
	Renderer* renderer;
	Light light;

	float speed=1;

	void start() {
		std::cout << "default function 2 electric boogaloo";
		tag = "player";
		light = Light(position, sf::Vector3f(1.0, 1.0, 1.0), 100);
	}
	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			position.x += speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			position.x -= speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			position.y += speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			position.y -= speed;
		}
		sprite.sprite.setPosition(position);
		light.position = position;
		renderer->lights[renderer->lightPointer+1] = light;
		//renderer->addLight(light);
	}
	void draw() {
		renderer->draw(sprite);
	}
	Player(Object** objects_in,Sprite sprite_in,Renderer* renderer_in) {
		objects = objects_in;
		sprite = sprite_in;
		renderer = renderer_in;
		start();
	}
	Player() {
		start();
		//default constructor
	}
};
#pragma once
