#include "ofApp.h"

void ofApp::check_bullet_collisions(){
	for(int i=0;i<bullets.size();i++){
		//自機から出た弾なら
		if(bullets[i].from_player){
			if(ofDist(bullets[i].pos.x , bullets[i].pos.y , boss_1.pos.x , boss_1.pos.y)<(bullets[i].width + boss_image.width)/5){
				bullets.erase(bullets.begin()+i);
				enemy_Break.loadSound("enemy_break.mp3");
				enemy_Break.play();
				boss_1.lives--;
				
				if(boss_1.lives==0){
					score+=1000;
				}
				return;
			}

			//敵への当たり判定
			for(int e=enemies.size()-1; e>=0; e--){
				//ofDist(x1,y1,x2,y2)距離を測定している

				if(ofDist(bullets[i].pos.x , bullets[i].pos.y , enemies[e].pos.x , enemies[e].pos.y)<(bullets[i].width + enemies[e].width)/2){
					bullets.erase(bullets.begin()+i);
					enemy_Break.loadSound("enemy_break.mp3");
					enemy_Break.play();
					enemies.erase(enemies.begin()+e); //当たったn番目のenemyを消す					
					score+=10;//scoreに10を足す
				return;//関数を抜ける※これがないとエラーが起こる
				}
			}
		}else{
			//自分の当たり判定枠組み
			if(ofDist(bullets[i].pos.x,bullets[i].pos.y,player_1.pos.x,player_1.pos.y)<(bullets[i].width+player_1.width)/4){
					bullets.erase(bullets.begin()+i);
					player_1.lives--;//player_1.livesからマイナスする
					player_Dmage.loadSound("player_dmage.mp3");
					player_Dmage.play();

					if(player_1.lives<=0){//ライフが0になればend画面へ
						game_state="end";
						mainSound.stop();
						endingSong.loadSound("end.mp3");
						endingSong.play();
					}
			}
		}
    }
}