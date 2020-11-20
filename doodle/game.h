#pragma once
#include "bullet.h"
#include "enemy.h"
class GameScene
{
private:
	vector<Bullet> bullets;
	vector<Enemy> enemies;
public:
	void push_bullets(Bullet_Type bulletType);
	void push_enemy();
	void erase_bullet();
	void erase_enemy();

	void draw_bullets(Bullet_Type bulletType);
	void draw_aim();
	void draw_cards();
	void draw_enemy();
};