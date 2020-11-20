#include "enemy.h"

void Enemy::move(double dt)
{
	position.x -= velocity.x * dt;
	position.y -= velocity.y * dt;
}
void die()
{
	
}
double Enemy::get_position_x() {
	return position.x;
}
double Enemy::get_position_y()
{
	return position.y;
}