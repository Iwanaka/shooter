#include "LevelController.h"

void LevelController::setup(float e){//e‚ÍofApp‚ÅŒo‰ßŠÔæ“¾‚ğéŒ¾‚µ‚Ä‚¢‚é
	start_time_enemy=0;
	start_time_enegy=0;
	interval_time=500.0;//Enemy‚ÌŒ»‚ê‚é‚Ü‚Å‚Ì•b”A500‚Ìê‡0.5•b‚²‚Æ‚É“G‚ªŒ»‚ê‚é
	item_time=10000.0;
}

bool LevelController::should_spawn(){

	if(ofGetElapsedTimeMillis()-start_time_enemy>interval_time){//Œo‰ßŠÔ‚É‘Î‚µ‚Äinterval‚Ì•û‚ª”’l‚ª‘å‚«‚¯‚ê‚ÎÀs
		start_time_enemy=ofGetElapsedTimeMillis()+10;//starttime‚ÉŒo‰ßŠÔ‚ğ‘ã“ü
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


