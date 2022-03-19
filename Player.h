#include "Object.h"

class Player :public Object {
public:
	void start() {
		std::cout << "default function 2 electric boogaloo";
	}
	void update() {
		std::cout << "I have added da aditional functionality yaaaaaaa.";
	}
};
#pragma once
