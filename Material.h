#ifndef MATERIAL_H
#define MATERIAL_H


#include <SFML/Graphics.hpp>
class Material {
public:
	sf::Shader *shader;
	Material() {
		//defualt constructor
	}
	Material(sf::Shader *shader_in) {
		shader = shader_in;
	}
};

#endif