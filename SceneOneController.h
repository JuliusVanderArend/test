#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Player.h"
#include "Renderer.h"

class SceneOneController : public Object {
public:
	Player* player;
	Renderer* renderer;
	int* activeScene;
	int targetScene;
	int time = 0;
	SceneOneController(Player* player_in,Renderer* renderer_in,int* activeScene_in, int targetScene_in) {
		player = player_in;
		renderer = renderer_in;
		activeScene = activeScene_in;
		targetScene = targetScene_in;
	}
	void update() {
		if (time < 3622) {
			if (time == 0) {
				player->position.x = 90;
				player->sprite.sprite.setScale(sf::Vector2f(-1, 1));
			}
			if (time < 1050) {
				player->isCutscene = true;
			}
			else {
				player->isCutscene = false;
			}
			if (time == 3600) {
				renderer->transition(100);
			}
			if (time > 3620) {
				*activeScene = targetScene;
			}
			time++;
		}
	}
	void draw() {

	}
	void start() {
		
	}
};