#include "ofMain.h"

class LevelController{
public:
	float start_time_enemy;
	float start_time_enegy;
	float interval_time;//敵の出現頻度
	float item_time;


	void setup(float e);//ここのeはofAoo.cppのkeyReleasedに繋がる
	bool should_spawn();
	bool Item_spawn();
};