#include "ofApp.h"

void ofApp::check_bullet_collisions(){
	for(int i=0;i<bullets.size();i++){
		//���@����o���e�Ȃ�
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

			//�G�ւ̓����蔻��
			for(int e=enemies.size()-1; e>=0; e--){
				//ofDist(x1,y1,x2,y2)�����𑪒肵�Ă���

				if(ofDist(bullets[i].pos.x , bullets[i].pos.y , enemies[e].pos.x , enemies[e].pos.y)<(bullets[i].width + enemies[e].width)/2){
					bullets.erase(bullets.begin()+i);
					enemy_Break.loadSound("enemy_break.mp3");
					enemy_Break.play();
					enemies.erase(enemies.begin()+e); //��������n�Ԗڂ�enemy������					
					score+=10;//score��10�𑫂�
				return;//�֐��𔲂��遦���ꂪ�Ȃ��ƃG���[���N����
				}
			}
		}else{
			//�����̓����蔻��g�g��
			if(ofDist(bullets[i].pos.x,bullets[i].pos.y,player_1.pos.x,player_1.pos.y)<(bullets[i].width+player_1.width)/4){
					bullets.erase(bullets.begin()+i);
					player_1.lives--;//player_1.lives����}�C�i�X����
					player_Dmage.loadSound("player_dmage.mp3");
					player_Dmage.play();

					if(player_1.lives<=0){//���C�t��0�ɂȂ��end��ʂ�
						game_state="end";
						mainSound.stop();
						endingSong.loadSound("end.mp3");
						endingSong.play();
					}
			}
		}
    }
}