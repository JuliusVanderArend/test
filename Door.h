#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Object.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Utility.h"
#include "Player.h"

class Door : public Object {
public:
	Renderer* renderer;
	Sprite sprite;
	int* activeScenePtr;
	int targetSceneIndex;
	int sceneSwitchcounter = -1;
	Player* player;
	Door(sf::Vector2f position_in, Sprite sprite_in, Renderer* renderer_in, Player* player_in, int* activeScenePtr_in, int targetSceneIndex_in) {
		position = position_in;
		sprite = sprite_in;
		renderer = renderer_in;
		player = player_in;
		activeScenePtr = activeScenePtr_in;
		targetSceneIndex = targetSceneIndex_in;
		tag = "door";
	}
	void start() {

	}
	void draw() {
		if (position.x < 80) {
			sprite.sprite.setScale(sf::Vector2f(-1, 1));
		}
		else {
			sprite.sprite.setScale(sf::Vector2f(1, 1));
		}
		renderer->draw(sprite);
	}
	void update() {
		//std::cout << dist(position, player->position) << std::endl;
		/*if (dist(position, player->position)<10) {
			*activeScenePtr = targetSceneIndex;
			player->position = sf::Vector2f(30, player->position.y);
		}*/
		if (sceneSwitchcounter > -1) {
			sceneSwitchcounter--;
		}
		if (sceneSwitchcounter == 0) {
			*activeScenePtr = targetSceneIndex;
			player->timeInCurrentScene = 0;
			player->position = sf::Vector2f(30, player->position.y);
		}
		sf::Vector2f mousePos = getMousePos(renderer->window);
		//std::cout << mousePos.y << std::endl;
		if (colRectPoint(mousePos.x, mousePos.y, position.x-9, position.y, position.x + 9, position.y + 30) && dist(position, player->position) < 30 && player->timeInCurrentScene >10) {
			sprite.sprite.setTextureRect(sf::IntRect(18, 0, 18, 30));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sceneSwitchcounter = 20;
				renderer->transition(50);
			}
		}
		else {
			sprite.sprite.setTextureRect(sf::IntRect(0, 0, 18, 30));
		}
		sprite.sprite.setPosition(position);
	}
};
