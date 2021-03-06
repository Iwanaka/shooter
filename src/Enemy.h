#pragma once
#include "ofMain.h"

class Enemy {
public:
   ofPoint pos;//Enemy出現位置
   float speed;//Enemyの速度
   float amplitude;//揺れ幅
   float width;//Enemyの当たり判定枠
   
   float start_shoot;
   float shoot_interval;
   
   void setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage * enemy_image);
   void update();
   void draw();
   void end();
   bool time_to_shoot();
   
   ofImage * img;
};