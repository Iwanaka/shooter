#include "LevelController.h"

void LevelController::setup(float e){//eはofAppで経過時間取得を宣言している
	start_time_enemy=0;
	start_time_enegy=0;
	interval_time=500.0;//Enemyの現れるまでの秒数、500の場合0.5秒ごとに敵が現れる
	item_time=10000.0;
}

bool LevelController::should_spawn(){

	if(ofGetElapsedTimeMillis()-start_time_enemy>interval_time){//経過時間に対してintervalの方が数値が大きければ実行
		start_time_enemy=ofGetElapsedTimeMillis()+10;//starttimeに経過時間を代入
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


