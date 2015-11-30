#include "ofApp.h"

//-------------------------------------------------------------
void ofApp::update_bullets(){
	
	for(int i=0;i<bullets.size();i++){//sizeは最大要素数
		bullets[i].update();

		//画面外にはみ出た弾を消している
		if(bullets[i].pos.y-bullets[i].width/2<0 || bullets[i].pos.y+bullets[i].width/2>ofGetHeight()){
			bullets.erase(bullets.begin()+i);
		}//eraseは要素配列内の削除、beginは配列の先頭を示す
	}
	check_bullet_collisions();
}

//--------------------------------------------------------------
void ofApp::update_bonuses(){
	//ボーナス取得によるライフ回復
	//画面外に出たら消す
	for(int i=bonuses.size()-1;i>0;i--){
		if(bonuses[i].pos.y+bonuses[i].width/2>ofGetHeight()){
			bonuses.erase(bonuses.begin()+i);
		}
	}
			//当たり判定,bonuses[i].update();の記述場所に注意！！
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
	//ライフ表示(ここは残機表示なので自機画像を表示している)
	for(int i=0;i<player_1.lives;i++){//player_1.livesの数を読み込む
		player_image.draw(ofGetWidth()-(i*player_image.width)-100,ofGetHeight()/1.1);
	}
	//ボスの体力を表示すると重くなる…
	for(int i=0;i<boss_1.lives;i++){
		boss_power.draw(-350,ofGetHeight()/2.5-(i*boss_bullet_image2.width/3));
	}
}
//--------------------------------------------------------------
void ofApp::draw_score(){//スコア表示
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

	ofSetFrameRate(60);//1秒のフレーム数
	game_state="start";//スタート画面を描画
	score=0;//スコアの初期値

	openingSong.loadSound("opening.mp3");
	openingSong.setLoop(true);
	openingSong.play();

	max_enemy_amplitude=3.0;//Enemy.hの変数
	max_enemy_shoot_interval=1.5;//Enemy.hの変数
	

	life_image.loadImage("enegy.png");//回復アイテムImage
	enemy_image.loadImage("enemyship.png");//敵Image
	player_image.loadImage("mainship1.png");//操作自分機Image
	enemy_bullet_image.loadImage("enemybullt.png");//敵の弾
	player_bullet_image.loadImage("shot1.png");//自分の弾
	start_screen.loadImage("space.jpg");//最初の画面
	tutorial_screen.loadImage("tutorial.jpg");
	game_screen.loadImage("stardust.png");//ゲーム背景
	end_screen.loadImage("congruent_outline.png");//終わりの画面
	boss_bullet_image.loadImage("atari.png");//ボス弾
	boss_bullet_image2.loadImage("08.png");
	boss_power.loadImage("power.png");
	boss_image.loadImage("Boss.png");//bossイメージ

	boss_1.setup(&boss_image);
	player_1.setup(&player_image);//player.setupに返す

	score_font.loadFont("verdana",48);//スコアフォント
	explain_font.loadFont("verdana",24);//説明フォント
}

//--------------------------------------------------------------
void ofApp::update(){

	if(game_state=="start"){//スタート画面の更新描画

	}else if(game_state=="tutorial"){

	}else if(game_state=="game"){//ゲーム画面の更新描画
		player_1.update();
		update_bullets();
		update_bonuses();
        boss_1.update();

		//ボスの動き、弾バリエーション
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

		//敵出現
		for(int i=0;i<enemies.size();i++){
			enemies[i].update();

			if(enemies[i].time_to_shoot()){
			Bullet b;//time_to_shot関数にて一瞬だけtrueにしている
			b.setup(false,enemies[i].pos,enemies[i].speed,&enemy_bullet_image);
			bullets.push_back(b);
            }
      }
		for(int i=enemies.size()-1;i>0;i--){
			//画面外に出たら消す
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

		start_screen.draw(0,0,ofGetWidth(),ofGetHeight());//初期画面の描画
		draw_score();//score表示

	}else if(game_state=="tutorial"){
		tutorial_screen.draw(0,0,ofGetWidth(),ofGetHeight());

	}else if(game_state=="game"){//ゲーム画面の描画

		game_screen.draw(0,0,ofGetWidth(),ofGetHeight());
		player_1.draw();//player1を表示
		draw_lives();//draw_livesを表示
		draw_score();//score表示
		boss_1.draw();


		//Enemyのvectorによる配列
		for(int i=0;i<enemies.size();i++){
			enemies[i].draw();
		}
		//Bulletのvectorによる配列
		for(int i=0;i<bullets.size();i++){
			bullets[i].draw();
		}
		//bonusesのvectorによる配列
		for(int i=0;i<bonuses.size();i++){
			bonuses[i].draw();
		}

	}else if(game_state=="end"){//終了画面の描画
		end_screen.draw(0,0,ofGetWidth(),ofGetHeight());
		draw_score();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//Playerへキー操作のtrueを渡す
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
		//Bulletのsetupと関連づけている。発射場所の相対位置
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
			level_controller.setup(ofGetElapsedTimeMillis());//相対数eに開始してからの時間を取得している
		}
	}else if(game_state=="game"){//Playerへキー操作のfalseを渡す
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