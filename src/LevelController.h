#include "ofMain.h"

class LevelController{
public:
	float start_time_enemy;
	float start_time_enegy;
	float interval_time;//“G‚ÌoŒ»•p“x
	float item_time;


	void setup(float e);//‚±‚±‚Ìe‚ÍofAoo.cpp‚ÌkeyReleased‚ÉŒq‚ª‚é
	bool should_spawn();
	bool Item_spawn();
};