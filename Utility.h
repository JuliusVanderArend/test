#pragma once
#include "Object.h"
#include <iostream>

class Filler :public Object {
public:
	Filler() {
		start();
	}
	void start() {
		tag = "filler";
	}
	void update() {

	}
	virtual void draw() {

	}
};


int getObjectSlot(Object* objects[]) {
	for (int i = 0; i < 128; i++) {
		if (objects[i]->tag=="filler") {
			return i;
		}
	}
	return -1;
}

float dist(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}
float dist(sf::Vector2f p1,sf::Vector2f p2) {
	return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}

bool colRectPoint(float px, float py, float x1, float y1, float x2, float y2) {
	if (px > x1 && px<x2 && py>y1 && py < y2) {
		return true;
	}
	else {
		return false;
	}
}

sf::Vector2f getMousePos(sf::RenderWindow* window) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	sf::Vector2u screensize = window->getSize();
	return sf::Vector2f(mousePos.x / (screensize.x / 160), mousePos.y / (screensize.y / 90));
}