#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Object.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Player.h"
#include "Utility.h"
#include "Scene.h"
#include "TextBox.h"
#include "NoteBox.h"

class Computer : public Object{
public:
	float sizeX;
	float sizeY;
	sf::RenderWindow* window;
	Renderer* renderer;
	Player* player;
	Sprite sprite;
	std::string text;
	TextBox* textBox;
	NoteBox* noteBox;
	bool isInteracted = false;
	bool useNote = false;

	Computer(sf::Vector2f position_in,float sizeX_in,float sizeY_in, sf::RenderWindow* window_in,Renderer* render_in,Player* player_in,Sprite sprite_in,TextBox* textbox_in) {
		position = position_in;
		sizeX = sizeX_in;
		sizeY = sizeY_in;
		window = window_in;
		renderer = render_in;
		player = player_in;
		sprite = sprite_in;
		textBox = textbox_in;
		sprite.sprite.setTextureRect(sf::IntRect(0, sprite.sprite.getTextureRect().top, sprite.sprite.getTextureRect().width, sprite.sprite.getTextureRect().height));
	}
	Computer(sf::Vector2f position_in, float sizeX_in, float sizeY_in, sf::RenderWindow* window_in, Renderer* render_in, Player* player_in, Sprite sprite_in, NoteBox* noteBox_in) {
		position = position_in;
		sizeX = sizeX_in;
		sizeY = sizeY_in;
		window = window_in;
		renderer = render_in;
		player = player_in;
		sprite = sprite_in;
		noteBox = noteBox_in;
		sprite.sprite.setTextureRect(sf::IntRect(0, sprite.sprite.getTextureRect().top, sprite.sprite.getTextureRect().width, sprite.sprite.getTextureRect().height));
		useNote = true;
	}
	void interact() {
		//int index = getObjectSlot(scene->objects);
		std::cout << "interact" << std::endl;
		if (useNote) {
			noteBox->active = true;
		}
		else {
			textBox->active = true;
		}
		isInteracted = true;
	}

	void update() {
		//scene->objects[0]->position.y += 0.1;
		sf::Vector2f mousePos = getMousePos(window);
		//std::cout << mousePos.y << std::endl;
		if (colRectPoint(mousePos.x,mousePos.y,position.x,position.y,position.x+sizeX,position.y+sizeY) && !player->isCutscene) {
			sprite.sprite.setTextureRect(sf::IntRect(sprite.sprite.getTextureRect().width , sprite.sprite.getTextureRect().top, sprite.sprite.getTextureRect().width , sprite.sprite.getTextureRect().height));
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				interact();
			}
		}
		else {
			sprite.sprite.setTextureRect(sf::IntRect(0, sprite.sprite.getTextureRect().top, sprite.sprite.getTextureRect().width , sprite.sprite.getTextureRect().height));
		}
		sprite.sprite.setPosition(position);
	}
	void draw() {

		renderer->draw(sprite);

	}
};