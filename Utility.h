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