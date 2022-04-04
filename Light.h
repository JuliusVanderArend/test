#ifndef LIGHT_H
#define LIGHT_H
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Renderer.h"
class Light {
public:
	sf::Vector2f position;
	sf::Vector3f color;
	float intensity;
	Light() {
		//default constructor
		position = sf::Vector2f(0, 0);
		color = sf::Vector3f(0, 0 ,0);
		intensity = 0;
	}
	Light(sf::Vector2f position_in,sf::Vector3f color_in,float intensity_in) {
		position = position_in;
		color = color_in;
		intensity = intensity_in;
	}
};


#endif