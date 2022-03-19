#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Light.h"
#include <iostream>

class Renderer {
public:
	sf::RenderWindow *window;
	Light lights[128];
	int lightPointer = 0;
	sf::Vector2f lightPos;
	Renderer() {
		//default constructor
	}
	Renderer(sf::RenderWindow *window_in) {
		window = window_in;
	}
	void setupFrame(sf::Shader *shader) {
		sf::Vector2f pos[128];
		sf::Vector3f col[128];
		float intensity[128];
		for (int i = 0; i < 128; i++) {
			pos[i].x = lights[i].position.x;
			pos[i].y = 1000-lights[i].position.y;
			col[i] = lights[i].color;
			intensity[i] = lights[i].intensity;
		}
		shader->setUniformArray("lightPos", pos, 128);
		shader->setUniformArray("lightI", intensity, 128);
		shader->setUniformArray("lightCol", col, 128);
		lightPointer = 0;
	}
	void draw(Sprite sprite) {
		sprite.material.init();// bad performance?
		window->draw(sprite.sprite,sprite.material.shader);
	}
	void addLight(Light light) {
		lights[lightPointer] = light;
		lightPointer++;
		//std::cout << "x: " << light.position.x << " y: " << light.position.y << std::endl;
		//std::cout << lightPointer<<std::endl;
	}
	void debugLightsArray() {
		for (int i = 0; i < 128; i++) {
			std::cout << "x: " << lights[i].position.x << " y: " << lights[i].position.y << std::endl;
		}
	}


};

#endif 