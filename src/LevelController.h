#include "ofMain.h"

class LevelController{
public:
	float start_time_enemy;
	float start_time_enegy;
	float interval_time;//�G�̏o���p�x
	float item_time;


	void setup(float e);//������e��ofAoo.cpp��keyReleased�Ɍq����
	bool should_spawn();
	bool Item_spawn();
};