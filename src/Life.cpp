#include "Life.h"

//���C�t�񕜃A�C�e��
void Life::setup(ofImage*life_image){

	pos.x=ofRandom(0,ofGetWidth());
	pos.y=0;
	img=life_image;
	width=img->width;
	speed=2;//�~���Ă��鑁��
}
void Life::update(){

	pos.y+=speed;//�ォ��~���Ă���
}
void Life::draw(){

	img->draw(pos.x-width/2,pos.y-width/2);
}