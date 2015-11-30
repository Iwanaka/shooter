#include "Bullet.h"

void Bullet::setup(bool f_p,ofPoint p,float s,ofImage*bullet_image){

	from_player=f_p;//bool値、ofApp.cppと関連付けて、' 'がされたらtrueとなる設定がされている。
	pos=p;//Bulletの相対位置
	speed=s+3;//弾の速度
	img=bullet_image;
	width=img->width;//Bulletの幅をwidthとしimgの幅としている

}

void Bullet::update(){
	if(from_player){
		pos.y-=speed;//playerの出す弾は-y軸に進む
	}else{
		pos.y+=speed;//それ以外は+y軸に進む
	}
}
void Bullet::draw(){
	img->draw(pos.x-width/2,pos.y-width/2);
}