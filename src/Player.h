#pragma once
#include "ofMain.h"


class Player{
public:
	ofPoint pos;//x,y�`��ʒu
	float width,height,speed;
	int lives;//���C�t��

	//key��true,false�l
	bool is_left_pressed,is_right_pressed,is_down_pressed,is_up_pressed;

	void setup(ofImage*player_image);
	void update();
	void draw();

	ofImage*img;

};