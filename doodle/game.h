#pragma once
#include "bullet.h"
#include "enemy.h"
#include "arts.h"
class GameScene
{
private:
	vector<Bullet> bullets;
	vector<Enemy> enemies;
	int remaning_enemy = LEVEL * 3;
	int timer = 0;
public:
	arts art;
	void next_level();
	void new_level();
	void push_bullets(Bullet_Type bulletType);
	void push_enemy(Enemy_Type enemyType);
	void move_enmey();
	void erase_bullet();
	void erase_enemy();

	void draw_bullets();
	void draw_aim();
	void draw_cards();
	void draw_enemy();

	void EraseEnemieByCollision();

};