#pragma once
#include "main_header.h"

class Enemy
{
private:
	Pos position{ 0,0 };
	Pos velocity{ 0,0 };
	double size{ 0 };
	Color color{ 0 };

public:
	void move(double dt);
	Pos get_position();
	double get_size();
	Color get_color();
	void set_position(double width, double height);
	void set_velocity(double vel);
	void set_size(double sz);
	void set_color(Color ene_color);
};