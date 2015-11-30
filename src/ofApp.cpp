#include "ofApp.h"

//-------------------------------------------------------------
void ofApp::update_bullets(){
	
	for(int i=0;i<bullets.size();i++){//size�͍ő�v�f��
		bullets[i].update();

		//��ʊO�ɂ͂ݏo���e�������Ă���
		if(bullets[i].pos.y-bullets[i].width/2<0 || bullets[i].pos.y+bullets[i].width/2>ofGetHeight()){
			bullets.erase(bullets.begin()+i);
		}//erase�͗v�f�z����̍폜�Abegin�͔z��̐擪������
	}
	check_bullet_collisions();
}

//--------------------------------------------------------------
void ofApp::update_bonuses(){
	//�{�[�i�X�擾�ɂ�郉�C�t��
	//��ʊO�ɏo�������
	for(int i=bonuses.size()-1;i>0;i--){
		if(bonuses[i].pos.y+bonuses[i].width/2>ofGetHeight()){
			bonuses.erase(bonuses.begin()+i);
		}
	}
			//�����蔻��,bonuses[i].update();�̋L�q�ꏊ�ɒ��ӁI�I
	for(int i=0;i<bonuses.size();i++){
		bonuses[i].update();
		if(ofDist(player_1.pos.x,player_1.pos.y,bonuses[i].pos.x,
			bonuses[i].pos.y)<(player_1.width+bonuses[i].width)/2){
				bonuses.erase(bonuses.begin()+i);
				if(player_1.lives<5){
					player_1.lives++;
					enegy_Get.loadSound("enegy_Get.mp3");
					enegy_Get.play();
				}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_lives(){
	//���C�t�\��(�����͎c�@�\���Ȃ̂Ŏ��@�摜��\�����Ă���)
	for(int i=0;i<player_1.lives;i++){//player_1.lives�̐���ǂݍ���
		player_image.draw(ofGetWidth()-(i*player_image.width)-100,ofGetHeight()/1.1);
	}
	//�{�X�̗̑͂�\������Əd���Ȃ�c
	for(int i=0;i<boss_1.lives;i++){
		boss_power.draw(-350,ofGetHeight()/2.5-(i*boss_bullet_image2.width/3));
	}
}
//--------------------------------------------------------------
void ofApp::draw_score(){//�X�R�A�\��
	if(game_state=="start"){
		score_font.drawString("shooter game",50,92);
		explain_font.drawString("Please Key",50,142);
	
	}else if(game_state=="tutorial"){

	}else if(game_state=="game"){
		score_font.drawString(ofToString(score),30,72);
	

	}else if(game_state=="end"){
		float w=score_font.stringWidth(ofToString(score));
		float z=explain_font.stringWidth(ofToString("Thank you"));
		score_font.drawString(ofToString(score),ofGetWidth()/2-w/2,ofGetHeight()/2+100);
		explain_font.drawString("GAME OVER",ofGetWidth()/2-z/2,ofGetHeight()/2-40);
	}
}

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);//1�b�̃t���[����
	game_state="start";//�X�^�[�g��ʂ�`��
	score=0;//�X�R�A�̏����l

	openingSong.loadSound("opening.mp3");
	openingSong.setLoop(true);
	openingSong.play();

	max_enemy_amplitude=3.0;//Enemy.h�̕ϐ�
	max_enemy_shoot_interval=1.5;//Enemy.h�̕ϐ�
	

	life_image.loadImage("enegy.png");//�񕜃A�C�e��Image
	enemy_image.loadImage("enemyship.png");//�GImage
	player_image.loadImage("mainship1.png");//���쎩���@Image
	enemy_bullet_image.loadImage("enemybullt.png");//�G�̒e
	player_bullet_image.loadImage("shot1.png");//�����̒e
	start_screen.loadImage("space.jpg");//�ŏ��̉��
	tutorial_screen.loadImage("tutorial.jpg");
	game_screen.loadImage("stardust.png");//�Q�[���w�i
	end_screen.loadImage("congruent_outline.png");//�I���̉��
	boss_bullet_image.loadImage("atari.png");//�{�X�e
	boss_bullet_image2.loadImage("08.png");
	boss_power.loadImage("power.png");
	boss_image.loadImage("Boss.png");//boss�C���[�W

	boss_1.setup(&boss_image);
	player_1.setup(&player_image);//player.setup�ɕԂ�

	score_font.loadFont("verdana",48);//�X�R�A�t�H���g
	explain_font.loadFont("verdana",24);//�����t�H���g
}

//--------------------------------------------------------------
void ofApp::update(){

	if(game_state=="start"){//�X�^�[�g��ʂ̍X�V�`��

	}else if(game_state=="tutorial"){

	}else if(game_state=="game"){//�Q�[����ʂ̍X�V�`��
		player_1.update();
		update_bullets();
		update_bonuses();
        boss_1.update();

		//�{�X�̓����A�e�o���G�[�V����
		if(boss_1.lives>0){
			if(boss_1.shot()){
			if(boss_1.lives>=50){
		
			Bullet b;
			b.setup(false,boss_1.pos,boss_1.bullet_speed,&boss_bullet_image);
			bullets.push_back(b);
		        }
		if(boss_1.lives<50){
			Bullet b;
			b.setup(false,boss_1.pos,boss_1.bullet_speed,&boss_bullet_image2);
			bullets.push_back(b);
		}
			}

		//�G�o��
		for(int i=0;i<enemies.size();i++){
			enemies[i].update();

			if(enemies[i].time_to_shoot()){
			Bullet b;//time_to_shot�֐��ɂĈ�u����true�ɂ��Ă���
			b.setup(false,enemies[i].pos,enemies[i].speed,&enemy_bullet_image);
			bullets.push_back(b);
            }
      }
		for(int i=enemies.size()-1;i>0;i--){
			//��ʊO�ɏo�������
		    if(enemies[i].pos.y+enemies[i].width/2>ofGetHeight()){
			enemies.erase(enemies.begin()+i);
		  }
		}
		if(level_controller.should_spawn()==true){
			Enemy e;
			e.setup(max_enemy_amplitude,max_enemy_shoot_interval,&enemy_image);
			enemies.push_back(e);
		}
		if(level_controller.Item_spawn()==true){
			Life l;
			l.setup(&life_image);
			bonuses.push_back(l);
		}
		}
		else{
			for(int i=0;i<enemies.size();i++){
				enemies[i].end();
				if(boss_1.pos.y<0){
					game_state="end";
					mainSound.stop();
					endingSong.loadSound("end.mp3");
					endingSong.play();
				}
			}
		}
	}else if(game_state=="end"){
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if(game_state=="start"){

		start_screen.draw(0,0,ofGetWidth(),ofGetHeight());//������ʂ̕`��
		draw_score();//score�\��

	}else if(game_state=="tutorial"){
		tutorial_screen.draw(0,0,ofGetWidth(),ofGetHeight());

	}else if(game_state=="game"){//�Q�[����ʂ̕`��

		game_screen.draw(0,0,ofGetWidth(),ofGetHeight());
		player_1.draw();//player1��\��
		draw_lives();//draw_lives��\��
		draw_score();//score�\��
		boss_1.draw();


		//Enemy��vector�ɂ��z��
		for(int i=0;i<enemies.size();i++){
			enemies[i].draw();
		}
		//Bullet��vector�ɂ��z��
		for(int i=0;i<bullets.size();i++){
			bullets[i].draw();
		}
		//bonuses��vector�ɂ��z��
		for(int i=0;i<bonuses.size();i++){
			bonuses[i].draw();
		}

	}else if(game_state=="end"){//�I����ʂ̕`��
		end_screen.draw(0,0,ofGetWidth(),ofGetHeight());
		draw_score();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//Player�փL�[�����true��n��
	if(game_state=="game"){
		if(key==OF_KEY_LEFT){
			player_1.is_left_pressed=true;
	}
	if(key==OF_KEY_RIGHT){
			player_1.is_right_pressed=true;
	}
	if(key==OF_KEY_UP){
		player_1.is_up_pressed=true;
	}

	if(key==OF_KEY_DOWN){
		player_1.is_down_pressed=true;
	}

	if(key==' '){
		playerShot.loadSound("shot4.mp3");
		playerShot.play();
		//Bullet��setup�Ɗ֘A�Â��Ă���B���ˏꏊ�̑��Έʒu
		Bullet b;
		b.setup(true,player_1.pos,player_1.speed,&player_bullet_image);
		bullets.push_back(b);
	}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	if(game_state=="start"){
		if(key==' '){
		game_state="tutorial";
		
		}
	}else if(game_state=="tutorial"){
		if(key==' '){
			game_state="game";
			mainSound.loadSound("game_normal.mp3");
	        mainSound.setLoop(true);
	        mainSound.play();
		    openingSong.stop();
			level_controller.setup(ofGetElapsedTimeMillis());//���ΐ�e�ɊJ�n���Ă���̎��Ԃ��擾���Ă���
		}
	}else if(game_state=="game"){//Player�փL�[�����false��n��
		if(key==OF_KEY_LEFT){
			player_1.is_left_pressed=false;
		}
		if(key==OF_KEY_RIGHT){
			player_1.is_right_pressed=false;
		}
		if(key==OF_KEY_UP){
			player_1.is_up_pressed=false;
		}
		if(key==OF_KEY_DOWN){
			player_1.is_down_pressed=false;
		}
	}else if(game_state=="end"){
		if(key==' '){
			score=0;
			enemies.clear();
			bullets.clear();
			bonuses.clear();
			player_1.is_left_pressed=false;
			player_1.is_right_pressed=false;
			player_1.is_up_pressed=false;
			player_1.is_down_pressed=false;
			return ofApp::setup();
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}