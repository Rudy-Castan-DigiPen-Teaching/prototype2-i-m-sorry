//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#pragma once
#include "bullet.h"
#include "enemy.h"
#include "arts.h"
class GameScene
{
private:
	vector<Bullet> bullets;
	vector<Enemy> enemies;
	vector<int> eraseB;
	vector<int> over_limitB;
    vector<int> eraseE;
	int remaining_enemy{ 0 };
	int timer{ 0 };
	int enemy_interver{ 400 };

public:
	void start_level();
	void next_level();
	void new_level();
	void reset_game();
	void push_bullets(Bullet_Type bulletType);
	void push_enemy();
	void move_enmey();
	void bullet_limit();

	void draw_bullets();
	void draw_aim();
	void draw_cards();
	void draw_enemy();
	void game_over();

	void EraseByCollision();
};