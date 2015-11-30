#include"Enemy.h"

//max_enemy�n�̒l��ofApp��setup�ɂċL�q���Ă���
void Enemy::setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage * enemy_image) {
	//�o���ʒu
   pos.x = ofRandom(0,ofGetWidth());
   pos.y = 0;
   img = enemy_image;
   width = img->width;//�����ŕ���img���Ƃ��Ă���
   speed = ofRandom(2,7);//�X�s�[�h�̊ɋ}
   amplitude =ofRandom(max_enemy_amplitude);//�ړ��̐G�ꕝ
   shoot_interval = ofRandom(0.5,max_enemy_shoot_interval);//�e�𔭎˂��鎞�ԍ�
   start_shoot = ofGetElapsedTimef();//ofGetElapsedTimef()�Ƃ͌o�ߎ��Ԃ����߂�

}
void Enemy::update() {
   pos.y += speed;
   pos.x += amplitude * sin(ofGetElapsedTimef());//amplitude��sin�̍��킹�Ŋɋ}�����Ă���
}
void Enemy::draw() {
   img->draw(pos.x - width/2, pos.y - width/2);
}
//�G�̎J��
void Enemy::end(){
	pos.y-=2;
}

bool Enemy::time_to_shoot() {

	//�o�ߎ��ԂɌo�ߎ��Ԃ������Ă��ꂪshoot_interval���l���傫�����true�l��
   if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
       start_shoot = ofGetElapsedTimef();
       return true;
   }
   return false;
}//ofGetElapsedTimef�͕b�P�ʂŁAofGetElapsedTimeMills�̓~���P�ʂŎ��Ԃ��擾