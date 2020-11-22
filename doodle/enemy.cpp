#include "enemy.h"

void Enemy::move(double dt)
{
	position.x -= velocity.x * dt;
}
Pos Enemy::get_position() {
	return position;
}
double Enemy::get_size()
{
	return size;
}
Color Enemy::get_color()
{
	return color;
}
int Enemy::get_health()
{
	return health;
}
void Enemy::set_position(double width, double height)
{
	position.x = width;
	position.y = height;
}
void Enemy::set_velocity(double vel)
{
	velocity.x = vel;
}
void Enemy::set_size(double sz)
{
	size = sz;
}
void Enemy::set_color(Color ene_color)
{
	color = ene_color;
}

void Enemy::set_health(int heal)
{
	health = heal;
}
void Enemy::health_decrease()
{
	health--;
}