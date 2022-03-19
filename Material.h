#ifndef MATERIAL_H
#define MATERIAL_H


#include <SFML/Graphics.hpp>
class Material {
public:
	sf::Shader *shader;
	sf::Texture texture;
	sf::Texture normal;
	void init() {
		shader->setUniform("normal", normal);
	}

	Material() {
		//defualt constructor
	}
	Material(sf::Shader* shader_in, sf::Texture texture_in, sf::Texture normal_in) {
		shader = shader_in;
		texture = texture_in;
		normal = normal_in;
		init();
	}
};

#endif