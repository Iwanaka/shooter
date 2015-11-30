#include "ofMain.h"

class Boss{
public:
	ofPoint pos;
	float speed_x;
	float speed_y;
	float bullet_speed;
	float width;

	float start_shoot;

	int lives;

	void setup(ofImage*boss_image);
	void update();
	void draw();
	
	bool shot();

	ofImage*img;

};