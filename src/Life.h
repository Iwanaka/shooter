#pragma once
#include "ofMain.h"

class Life{
public:
	ofPoint pos;
	float speed;
	float width;

	void setup(ofImage*life_image);
	void update();
	void draw();

	ofImage*img;
};