#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Sprite.h"
#include "Renderer.h"
#include "Light.h"
#include "Scene.h"

class Player :public Object {
public:
	Sprite sprite;
	Renderer* renderer;
	Light light;

	float speed=1;
	int timeInCurrentScene = 0;
	int animTime = 0;
	float vy = 0;
	bool isCutscene = false;
	void start() {
		std::cout << "default function 2 electric boogaloo";
		tag = "player";
		light = Light(position, sf::Vector3f(1.0, 0.5, 0.2), 9000);
	}
	void update(Scene* activeScene) {
		timeInCurrentScene++;
		if (!isCutscene) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position.x + speed + 10 < 160) {
				position.x += speed;
				animTime++;
				if (sprite.sprite.getScale() == sf::Vector2f(-1, 1)) {
					position.x -= 10;
				}
				sprite.sprite.setScale(1, 1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x - speed > 0) {
				position.x -= speed;
				animTime++;
				if (sprite.sprite.getScale() == sf::Vector2f(1, 1)) {
					position.x += 10;
				}
				sprite.sprite.setScale(-1, 1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				vy = -1;
			}
		}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		//	position.y += speed;
		//}
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		//	position.y -= speed;
		//}
		position.y += vy;
		vy += 0.163;
		if (position.y >54) {
			vy = 0;
			position.y = 54;
		}
		//std::cout << position.y << std::endl;
		sprite.sprite.setPosition(position);
		light.position = sf::Vector2f(position.x, position.y);
		//renderer->addLight(light);
	}
	void draw() {
		sprite.sprite.setTextureRect(sf::IntRect(10 * (static_cast <int> (std::floor(animTime*0.12)) % 4), 0, 10, 25));
		renderer->draw(sprite);
	}
	Player(Sprite sprite_in,Renderer* renderer_in) {
		sprite = sprite_in;
		renderer = renderer_in;
		start();
	}
	Player() {
		start();
		//default constructor
	}
};
#pragma once
