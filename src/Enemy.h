#pragma once
#include "ofMain.h"

class Enemy {
public:
   ofPoint pos;//EnemyoŒ»ˆÊ’u
   float speed;//Enemy‚Ì‘¬“x
   float amplitude;//—h‚ê•
   float width;//Enemy‚Ì“–‚½‚è”»’è˜g
   
   float start_shoot;
   float shoot_interval;
   
   void setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage * enemy_image);
   void update();
   void draw();
   void end();
   bool time_to_shoot();
   
   ofImage * img;
};