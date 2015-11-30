#include "Boss.h"

void Boss::setup(ofImage*boss_image){
	pos.x=ofGetWidth()/2;
	pos.y=0;
	img=boss_image;
	width=img->width;
	speed_x=10;
	speed_y=10;
	bullet_speed=1;
	lives=100;//‘Ì—Í
    start_shoot = ofGetElapsedTimef();
}

void Boss::update(){
	if(lives>=50){
	if(pos.y>=0&&pos.y<=200){
		pos.y=pos.y+1;
	}
	else if(pos.y=200){
	pos.x=pos.x+speed_x;

	if(pos.x<0+width/2){
		speed_x=speed_x*-1;
	}
	if(pos.x>ofGetWidth()-width/2){
		speed_x=speed_x*-1;
	}
	}
}else if(lives<50&&lives>=1){
	pos.x=pos.x+speed_x;
	pos.y=pos.y+speed_y;

	if(pos.x<0){
		speed_x=speed_x*-1;
	}
	if(pos.x>ofGetWidth()){
		speed_x=speed_x*-1;
	}
	if(pos.y<80){
		speed_y=speed_y*-1;
	}
	if(pos.y>ofGetHeight()/2.5){
		speed_y=speed_y*-1;
	}
}else{

		pos.y=pos.y-0.3;
	}
}

void Boss::draw(){
	img->draw(pos.x-width/2,pos.y-width/2);
}

bool Boss::shot(){
	if(lives>=50){
	
	   if (ofGetElapsedTimef() - start_shoot >ofRandom(0.2,0.7)) {
       start_shoot = ofGetElapsedTimef();
       return true;
   }
	}
	
	if(lives<50){
	   if (ofGetElapsedTimef() - start_shoot >ofRandom(0.1,0.3)) {
       start_shoot = ofGetElapsedTimef();
       return true;
   }
	}
   return false;
}
