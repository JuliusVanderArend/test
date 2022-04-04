#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#include "Scene.h"
#include "Utility.h"

class TextBox : public Object {
public:
	std::string text;
	std::string output;
	sf::RenderWindow* window;
	sf::RectangleShape rect;
	sf::Text textOutput;
	sf::Text exitText;
	sf::Font font;
	Renderer* renderer;
	Player* player;
	int* activeScenePtr;
	int targetScene;
	int currentChar = 0;
	int time = 0;
	int sceneSwitchcounter = -1;
	bool active = false;
	//int objectsIndex;
	TextBox(sf::RenderWindow* window_in, int targetScene_in, int* activeScenePtr_in,Renderer* renderer_in,Player* player_in) {
		player = player_in;
		window = window_in;
		targetScene = targetScene_in;
		activeScenePtr = activeScenePtr_in;
		renderer = renderer_in;
		font.loadFromFile("color basic.ttf");
		//objectsIndex = objectsIndex_in;
		rect.setSize(sf::Vector2f(80, 45));
		rect.setFillColor(sf::Color(0, 0, 0, 100));
		rect.setPosition(sf::Vector2f(window->getSize().x / 40, window->getSize().y / 40));
		textOutput.setPosition(sf::Vector2f(window->getSize().x / 40+1, window->getSize().y / 40+1));
		textOutput.setFont(font);
		textOutput.setCharacterSize(100);
		textOutput.setScale(sf::Vector2f(0.02,0.02));
		textOutput.setFillColor(sf::Color(30, 255, 30, 255));

		exitText.setPosition(sf::Vector2f(window->getSize().x / 40 + 1, window->getSize().y / 40 + 42));
		exitText.setFont(font);
		exitText.setCharacterSize(50);
		exitText.setScale(sf::Vector2f(0.02, 0.02));
		exitText.setFillColor(sf::Color(30, 255, 30, 255));
		exitText.setString("PRESS E TO EXIT");
		tag = "textbox";
	}
	void start() {

	}
	void update() {
		if (sceneSwitchcounter > -1) {
			sceneSwitchcounter--;
		}
		if (sceneSwitchcounter == 0) {
			*activeScenePtr = targetScene;
			targetScene = -1;
		}
		if (active) {
			if (time % 2 == 0 && currentChar < text.length()) {
				std::transform(output.begin(), output.end(), output.begin(), ::toupper);
				output += text.at(currentChar);
				currentChar++;
				if (currentChar % 50 == 0) {
					output += "\n";
				}
				textOutput.setString(output);
				//std::cout << output << std::endl;
			}
			time++;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			active = false;
			currentChar = 0;
			output = "";
			if (targetScene != -1) {
				sceneSwitchcounter = 20;
				renderer->transition(100);
			}
		}
	}
	void draw() {
		if (active) {
			window->draw(rect);
			window->draw(textOutput);
			window->draw(exitText);
		}
	}
};
