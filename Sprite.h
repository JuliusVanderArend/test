#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include "Material.h"

class Sprite {
public:
	sf::Texture texture;
	sf::Texture normal;
	sf::Sprite sprite;
	Material material;
	Sprite() {
		// default material
	}
	Sprite(sf::Texture texture_in,sf::Texture normal_in,Material material_in) {
		texture = texture_in;
		normal = normal_in;
		material = material_in;

		sprite.setTexture(texture);
	}
	Sprite(sf::Texture texture_in, Material material_in) {
		texture = texture_in;
		material = material_in;

		sprite.setTexture(texture);
	}
};

#endif