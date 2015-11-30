#pragma once
#include "ofMain.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "LevelController.h"
#include "Life.h"
#include "Boss.h"


class ofApp : public ofBaseApp{
	public:
		void check_bullet_collisions();
		void update_bullets();
		void update_bonuses();
		void draw_lives();
		void draw_score();
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		float max_enemy_amplitude;
		float max_enemy_shoot_interval;

		string game_state;
		int score;

		vector<Bullet> bullets;
		vector<Enemy> enemies;
		vector<Life> bonuses;
		Player player_1;
		Boss boss_1;



		ofImage player_image;
		ofImage enemy_image;
		ofImage enemy_bullet_image;
		ofImage player_bullet_image;
		ofImage boss_bullet_image;
		ofImage boss_bullet_image2;
		ofImage boss_power;
		ofImage life_image;
		ofImage start_screen;
		ofImage tutorial_screen;
		ofImage game_screen;
		ofImage end_screen;
		ofImage boss_image;

		ofSoundPlayer mainSound;
		ofSoundPlayer playerShot;
		ofSoundPlayer openingSong;
		ofSoundPlayer endingSong;
		ofSoundPlayer enegy_Get;
		ofSoundPlayer enemy_Break;
		ofSoundPlayer player_Dmage;

		ofTrueTypeFont score_font;
		ofTrueTypeFont explain_font;

		LevelController level_controller;
};

