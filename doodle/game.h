//Daehyeon Kim, Hyeong Ahn, Sunwoo Lee
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
	int remaning_enemy = 0;
	int timer = 0;
	int enemy_interver{ 400 };
public:
	arts art;
	void start_level();
	void next_level();
	void new_level();
	void push_bullets(Bullet_Type bulletType);
	void push_enemy();
	void move_enmey();
	void erase_bullet();
	void erase_enemy();

	void draw_bullets();
	void draw_aim();
	void draw_cards();
	void draw_enemy();

	void EraseEnemieByCollision();

};