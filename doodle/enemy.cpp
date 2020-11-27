//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#include "enemy.h"

void Enemy::move(double dt)
{
	if (dt < 0)
	{
		helper::error("Deltatime cannot be negatve");
	}
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
	if (width < 0 || width > Width)
	{
		helper::error("X position out of range");
	}
	if (height < 0 || height > Height)
	{
		helper::error("Y position out of range");
	}
	position.x = width;
	position.y = height;
}
void Enemy::set_velocity(double vel)
{
	if (vel < 0)
	{
		helper::error("Velocity cannot be negative");
	}
	velocity.x = vel;
}
void Enemy::set_size(double sz)
{
	if (sz < 0)
	{
		helper::error("Ellipse radius cannot be negative");
	}
	size = sz;
}
void Enemy::set_color(Color ene_color)
{
	constexpr int MAX_COLOR{255};
	constexpr int MIN_COLOR{0};
	if (ene_color.alpha < 0 || ene_color.alpha > MAX_COLOR)
	{
		helper::error("Alpha value does not exist");
	}
	if (ene_color.red < MIN_COLOR || ene_color.red > MAX_COLOR)
	{
		helper::error("Red value does not exist");
	}
	if (ene_color.green < MIN_COLOR || ene_color.green > MAX_COLOR)
	{
		helper::error("Green value does not exist");
	}
	if (ene_color.blue < MIN_COLOR || ene_color.blue > MAX_COLOR)
	{
		helper::error("Blue value does not exist");
	}
	color = ene_color;
}

void Enemy::set_health(int heal)
{
	if (heal < 0)
	{
		helper::error("Health cannot be negative");
	}
	health = heal;
}
void Enemy::health_decrease()
{
	health--;
}