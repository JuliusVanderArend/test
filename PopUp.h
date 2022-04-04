#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class PopUp : public Object {
public:
	std::string string;
	int timeOffset;
	int currentTime = 0;
	sf::RenderWindow* window;
	sf::Text text;
	sf::Font font;
	PopUp(std::string string_in, int timeOffset_in, sf::RenderWindow* window_in) {
		window = window_in;
		string = string_in;
		timeOffset = timeOffset_in;
		font.loadFromFile("color basic.ttf");
		text.setFont(font);
		text.setString(string);
		text.setCharacterSize(200);
		text.setScale(sf::Vector2f(0.02, 0.02));
		text.setPosition(sf::Vector2f(10, 10));
		text.setFillColor(sf::Color(255, 255, 255, 0));

	}
	void update() {
		if (currentTime - timeOffset > 0 && currentTime - timeOffset<240) {
			if (currentTime-timeOffset < 60) {
				text.setFillColor(sf::Color(255, 255, 255, (currentTime-timeOffset)* 4.25));
			}
			else if (currentTime - timeOffset > 60 && currentTime - timeOffset < 180) {
				text.setFillColor(sf::Color(255, 255, 255, 255));
			}
			else {
				text.setFillColor(sf::Color(255, 255, 255, (60-(currentTime - timeOffset-180)) * 4.25));
			}
		}
		else {
			text.setFillColor(sf::Color(255, 255, 255, 0));
		}
		currentTime++;
	}
	void draw() {
		window->draw(text);
	}
	void start() {
	
	}
};