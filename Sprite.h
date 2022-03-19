#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include "Material.h"

class Sprite {
public:
	sf::Sprite sprite;
	Material material;
	int shaderIndex = 0;

	Sprite() {
		// default material
		//init();
	}
	Sprite(Material  material_in) {
		material = material_in;
		sprite.setTexture(material.texture);

	}
};

#endif