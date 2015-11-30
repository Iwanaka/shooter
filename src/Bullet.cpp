#include "Bullet.h"

void Bullet::setup(bool f_p,ofPoint p,float s,ofImage*bullet_image){

	from_player=f_p;//bool�l�AofApp.cpp�Ɗ֘A�t���āA' '�����ꂽ��true�ƂȂ�ݒ肪����Ă���B
	pos=p;//Bullet�̑��Έʒu
	speed=s+3;//�e�̑��x
	img=bullet_image;
	width=img->width;//Bullet�̕���width�Ƃ�img�̕��Ƃ��Ă���

}

void Bullet::update(){
	if(from_player){
		pos.y-=speed;//player�̏o���e��-y���ɐi��
	}else{
		pos.y+=speed;//����ȊO��+y���ɐi��
	}
}
void Bullet::draw(){
	img->draw(pos.x-width/2,pos.y-width/2);
}