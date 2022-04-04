#pragma once

#include <SFML/Graphics.hpp>

#include "Object.h"
#include "Sprite.h"
#include "Renderer.h"

class NPC : public Object {
	std::string* lines;
	int* times;
	sf::RenderWindow* window;
	Renderer* renderer;
	Sprite sprite;
	std::string output;
	std::string currentLine = "";
	sf::Text textOutput;
	sf::Font font;
	sf::RectangleShape rect;
	int lineIndex = 0;
	int nLines;
	int stringIndex = 0;
	int time = 0;
	
public:
	NPC(sf::Vector2f pos_in,std::string* lines_in,int* times_in, int nLines_in,Renderer* renderer_in,sf::RenderWindow* window_in,Sprite sprite_in) {
		position = pos_in;
		lines = lines_in;
		times = times_in;
		window = window_in;
		nLines = nLines_in;
		renderer = renderer_in;
		sprite = sprite_in;
		sprite.sprite.setTextureRect(sf::IntRect(0, 0, 10, 25));
		font.loadFromFile("color basic.ttf");

		textOutput.setPosition(sf::Vector2f(position.x,position.y-10));
		textOutput.setFont(font);
		textOutput.setCharacterSize(100);
		textOutput.setScale(sf::Vector2f(0.02, 0.02));
		textOutput.setFillColor(sf::Color(0, 0, 0, 255));

		rect.setFillColor(sf::Color(255, 255, 255, 255));
		rect.setSize(sf::Vector2f(0, 0));
		sprite.sprite.setPosition(position);

	}
	void update() {
		if (times[lineIndex] == time) {
			currentLine = lines[lineIndex];
			lineIndex++;
			output = "";
			stringIndex = 0;
			rect.setSize(sf::Vector2f(40, ceil(static_cast<float>(currentLine.length()) / 20)*3+4));
		}
		if (currentLine != "" && stringIndex < currentLine.length()) {
			output += currentLine[stringIndex];
			//if ((stringIndex+1) % 20 == 0) {
			//	output += "\n";
			//}
			stringIndex++;
		}
		textOutput.setString(output);
		textOutput.setPosition(sf::Vector2f(position.x, position.y - 10));
		rect.setPosition(sf::Vector2f(position.x - 2, position.y - 12));
		time++;
	}
	void draw() {
		renderer->window->draw(rect);
		renderer->window->draw(textOutput);
		renderer->draw(sprite);
	}
	void start() {

	}
};