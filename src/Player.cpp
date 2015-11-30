#include "Player.h"

void Player::setup(ofImage*player_image){

	pos.x=ofGetWidth()/2;//�����`��|�C���g
	pos.y=ofGetHeight()/1.3;//�c���`��|�C���g
	img=player_image;
	width=img->width;//�`�敝
	height=img->height;//�`�捂��
	speed=10;//����
	lives=3;//���C�t�|�C���g
}

void Player::update(){
	//�ړ��g
	if(pos.x<20){
		pos.x=20;
	}else if(pos.x>ofGetWidth()-20){
		pos.x=ofGetWidth()-20;
	}else if(pos.y<ofGetHeight()/3){
		pos.y=ofGetHeight()/3;
	}else if(pos.y>ofGetHeight()/1.15){
		pos.y=ofGetHeight()/1.15;
	}

	//�L�[����
	if(is_left_pressed==true){
		pos.x=pos.x-speed;
	}else if(is_right_pressed==true){
		pos.x=pos.x+speed;
	}else if(is_up_pressed==true){
		pos.y=pos.y-speed;
	}else if(is_down_pressed==true){
		pos.y=pos.y+speed;
	}
	if(is_left_pressed==false){
		pos.x=pos.x;
	}else if(is_right_pressed==false){
		pos.x=pos.x;
	}else if(is_up_pressed==false){
		pos.y=pos.y;
	}else if(is_down_pressed==false){
		pos.y=pos.y;
	}
	if(is_left_pressed==true&&is_up_pressed==true){
		pos.x=pos.x-speed/2;
		pos.y=pos.y-speed/2;
	}else if(is_left_pressed==true&&is_down_pressed==true){
		pos.x=pos.x-speed/2;
		pos.y=pos.y+speed/2;
	}else if(is_right_pressed==true&&is_up_pressed==true){
		pos.x=pos.x+speed/2;
		pos.y=pos.y-speed/2;
	}else if(is_right_pressed==true&&is_down_pressed==true){
		pos.x=pos.x+speed/2;
		pos.y=pos.y+speed/2;
	}

	//�ړ��̃o�O�΍�
	if(pos.y<ofGetHeight()/3&&pos.x<20){
		is_up_pressed=false;
		is_left_pressed=false;
	}else if(pos.y<ofGetHeight()/3&&pos.x>ofGetWidth()-20){
		is_up_pressed=false;
		is_right_pressed=false;
	}else if(pos.y>ofGetHeight()/1.15&&pos.x<20){
		is_down_pressed=false;
		is_left_pressed=false;
	}else if(pos.y>ofGetHeight()/1.15&&pos.x>ofGetWidth()-20){
		is_down_pressed=false;
		is_right_pressed=false;
	}
}

void Player::draw(){
	//�@��,width/2�͕�����
	img->draw(pos.x-width/2,pos.y-width/2);
}




