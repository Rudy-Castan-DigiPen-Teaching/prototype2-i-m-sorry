#pragma once
#include "main_header.h"

class Enemy
{
private:
	Pos position{ 0,0 };
	Pos velocity{ 0,0 };

public:
	void move(double dt);
	double get_position_x();
	double get_position_y();
};