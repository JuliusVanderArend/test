#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#include "Renderer.h"

class LightOBJ : public Object {
public:
	Light light;
	Renderer* renderer;
	LightOBJ(Light light_in, Renderer* renderer_in) {
		position = light_in.position;
		light = light_in;
		renderer = renderer_in;
		tag = "light";
	}
	void update() {
		renderer->addLight(light);
	}
};