#pragma once
#include "Object.h"
#include "Light.h"
#include "Renderer.h"
#include "SceneState.h"

class Particle : public Object {
public:
	Light light;
	sf::Vector2f vel;
	Renderer renderer;
	Particle(sf::Vector2f pos_in) {
		position = pos_in;
		start();
	}
	void start() {
		light = Light(position, sf::Vector3f(1.0, 0.0, 0.0), 1000000000);
	}
	void update() {
		vel.y += 0.1;
		position += vel;
		light.position = position;
		//std::cout << renderer.lights[0].position.y << std::endl;
		//renderer.addLight(light);
		//renderer.lights[1] = light;
	}

};