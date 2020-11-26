//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#pragma once
#include "main_header.h"



class BuyScene
{
private:
	array<int, 5> bullet_count{ 0 };
public:
	void buyBullet(KeyboardButtons button);
	void draw_button();
	void draw_count();
	void reset_count();
	void draw_info();
};