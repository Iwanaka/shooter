#include"Enemy.h"

//max_enemy系の値はofAppのsetupにて記述している
void Enemy::setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage * enemy_image) {
	//出現位置
   pos.x = ofRandom(0,ofGetWidth());
   pos.y = 0;
   img = enemy_image;
   width = img->width;//ここで幅をimg分としている
   speed = ofRandom(2,7);//スピードの緩急
   amplitude =ofRandom(max_enemy_amplitude);//移動の触れ幅
   shoot_interval = ofRandom(0.5,max_enemy_shoot_interval);//弾を発射する時間差
   start_shoot = ofGetElapsedTimef();//ofGetElapsedTimef()とは経過時間をしめす

}
void Enemy::update() {
   pos.y += speed;
   pos.x += amplitude * sin(ofGetElapsedTimef());//amplitudeとsinの合わせで緩急をつけている
}
void Enemy::draw() {
   img->draw(pos.x - width/2, pos.y - width/2);
}
//敵の捌け
void Enemy::end(){
	pos.y-=2;
}

bool Enemy::time_to_shoot() {

	//経過時間に経過時間を引いてそれがshoot_intervalより値が大きければtrue値に
   if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
       start_shoot = ofGetElapsedTimef();
       return true;
   }
   return false;
}//ofGetElapsedTimefは秒単位で、ofGetElapsedTimeMillsはミリ単位で時間を取得