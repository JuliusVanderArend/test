#pragma once
#include "Object.h"
#include "Light.h"
#include "Renderer.h"
#include "SceneState.h"
#include <stdlib.h>

class Particle : public Object {
public:
	std::string tag = "particle";

	Light light;
	sf::Vector2f vel;
	Renderer* renderer;
	Particle(sf::Vector2f pos_in) {
		position = pos_in;
		start();
	}
	void start() {
		light = Light(position, sf::Vector3f((rand()%255), (rand() % 255) , (rand() % 255)), 1);
	}
	void update() {
		vel.y += 0.01;
		vel.x += 0.002;
		position += vel;

		if (position.y > 1000) {
			position.y = 999.9;
			vel.y = -vel.y * 0.99;
		}
		if (position.y <0) {
			position.y = 0.01;
			vel.y = -vel.y * 0.99;
		}
		if (position.x > 1000) {
			position.x = 999.9;
			vel.x = -vel.x * 0.99;
		}
		if (position.x < 0) {
			position.x = 0.01;
			vel.x = -vel.x * 0.99;
		}



		light.position = position;
		renderer->addLight(light);
		//renderer->lights[1] = light;
	}

};