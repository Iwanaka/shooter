#include "Life.h"

//ライフ回復アイテム
void Life::setup(ofImage*life_image){

	pos.x=ofRandom(0,ofGetWidth());
	pos.y=0;
	img=life_image;
	width=img->width;
	speed=2;//降ってくる早さ
}
void Life::update(){

	pos.y+=speed;//上から降ってくる
}
void Life::draw(){

	img->draw(pos.x-width/2,pos.y-width/2);
}