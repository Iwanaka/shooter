#pragma once
#include "ofMain.h"

class Bullet{
public:
	ofPoint pos;//弾の位置
	float  speed;//弾のスピード
	float width;//弾の幅（あたり判定をつけるための枠）
	bool from_player;//playerから出てるかどうかを判定させるbool値

	void setup(bool f_p,ofPoint p,float s,ofImage*bullet_image);
	void update();
	void draw();

	ofImage*img;

	

};