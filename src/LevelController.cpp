#include "LevelController.h"

void LevelController::setup(float e){//e��ofApp�Ōo�ߎ��Ԏ擾��錾���Ă���
	start_time_enemy=0;
	start_time_enegy=0;
	interval_time=500.0;//Enemy�̌����܂ł̕b���A500�̏ꍇ0.5�b���ƂɓG�������
	item_time=10000.0;
}

bool LevelController::should_spawn(){

	if(ofGetElapsedTimeMillis()-start_time_enemy>interval_time){//�o�ߎ��Ԃɑ΂���interval�̕������l���傫����Ύ��s
		start_time_enemy=ofGetElapsedTimeMillis()+10;//starttime�Ɍo�ߎ��Ԃ���
		return true;
	}
	return false;
}

bool LevelController::Item_spawn(){

	if(ofGetElapsedTimeMillis()-start_time_enegy>item_time){
		start_time_enegy=ofGetElapsedTimeMillis();
		return true;
	}
	return false;
}


