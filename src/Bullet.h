#pragma once
#include "ofMain.h"

class Bullet{
public:
	ofPoint pos;//�e�̈ʒu
	float  speed;//�e�̃X�s�[�h
	float width;//�e�̕��i�����蔻������邽�߂̘g�j
	bool from_player;//player����o�Ă邩�ǂ����𔻒肳����bool�l

	void setup(bool f_p,ofPoint p,float s,ofImage*bullet_image);
	void update();
	void draw();

	ofImage*img;

	

};