#pragma once
#include "ofMain.h"


class Player{
public:
	ofPoint pos;//x,y描画位置
	float width,height,speed;
	int lives;//ライフ数

	//keyのtrue,false値
	bool is_left_pressed,is_right_pressed,is_down_pressed,is_up_pressed;

	void setup(ofImage*player_image);
	void update();
	void draw();

	ofImage*img;

};