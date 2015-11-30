#pragma once
#include "ofMain.h"

class Enemy {
public:
   ofPoint pos;//Enemy�o���ʒu
   float speed;//Enemy�̑��x
   float amplitude;//�h�ꕝ
   float width;//Enemy�̓����蔻��g
   
   float start_shoot;
   float shoot_interval;
   
   void setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage * enemy_image);
   void update();
   void draw();
   void end();
   bool time_to_shoot();
   
   ofImage * img;
};