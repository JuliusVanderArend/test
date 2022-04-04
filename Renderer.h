#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Light.h"
#include <iostream>

class Renderer {
public:
	sf::RenderWindow *window;
	sf::Shader** shaders;
	Light lights[128];
	int lightPointer = 0;
	sf::Vector2f lightPos;
	int dipToBlack = 0;
	int dipToBlackStartCounter = 0;
	sf::RectangleShape screenRect;
	Renderer() {
		//default constructor
	}
	Renderer(sf::RenderWindow *window_in,sf::Shader** shaders_in) {
		window = window_in;
		shaders = shaders_in;
		screenRect.setSize(sf::Vector2f(160,90));
		screenRect.setPosition(sf::Vector2f(0, 0));
	}
	void setupFrame() {
		sf::Vector2f pos[128];
		sf::Vector3f col[128];
		float intensity[128];
		for (int i = 0; i < 128; i++) {
			if (i < lightPointer) {//<=?
				pos[i].x = lights[i].position.x;
				pos[i].y = window->getSize().y - lights[i].position.y * window->getSize().y / 90;
				col[i] = lights[i].color;
				intensity[i] = lights[i].intensity;
			}
			else {
				pos[i].x =0;
				pos[i].y = 0;
				col[i] = sf::Vector3f(0,0,0);
				intensity[i] = 0;
			}
		}
		for (int i = 0; i < 2; i++) {
			shaders[i]->setUniformArray("lightPos", pos, 128);
			shaders[i]->setUniformArray("lightI", intensity, 128);
			shaders[i]->setUniformArray("lightCol", col, 128);
			shaders[i]->setUniform("screenSize", sf::Vector2f(window->getSize().x, window->getSize().y));
		}
		lightPointer = 0;
	}
	void draw(Sprite sprite) {
		sprite.material.init();// bad performance?
		window->draw(sprite.sprite,sprite.material.shader);
		//sf::CircleShape circle;
		//circle.setRadius(4);
		//circle.setOutlineColor(sf::Color::Red);
		//circle.setOutlineThickness(1);
		//circle.setPosition(sprite.sprite.getPosition());
		//window->draw(circle);
	}
	void afterDraw() {
		if (dipToBlack > 0) {
			if (dipToBlackStartCounter > 0) {
				screenRect.setFillColor(sf::Color(0, 0, 0, (20-dipToBlackStartCounter) * 12.75));
			}
			else if(dipToBlack<20){
				screenRect.setFillColor(sf::Color(0, 0, 0, dipToBlack * 12.75));
			}
			else {
				screenRect.setFillColor(sf::Color(0, 0, 0, 255));
			}
			window->draw(screenRect);
		}
		dipToBlack--;
		dipToBlackStartCounter--;
	}
	//void drawBG(sf::Sprite bgSprite) {
	//	window->draw(bgSprite);
	//	//sf::CircleShape circle;
	//	//circle.setRadius(4);
	//	//circle.setOutlineColor(sf::Color::Red);
	//	//circle.setOutlineThickness(1);
	//	//circle.setPosition(10,10);
	//	//window->draw(circle);
	//	//std::cout << "drawBG" << std::endl;
	//}
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
	void transition(int frames) {
		dipToBlackStartCounter = 20;
		dipToBlack = frames;
	}
	


};

#endif 