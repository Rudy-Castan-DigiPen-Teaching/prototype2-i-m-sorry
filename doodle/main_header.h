#pragma once
#include <iostream>
#include <doodle/doodle.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <map>
#include "pos.h"
using namespace std;
using namespace doodle;
extern double getDegree(double x, double y);
inline bool IsMouseReleased = false;
inline int MONEY{ 2000 };

enum class Bullet_Type
{
    Pistol,
    Artillery,
    Fireball,
    Laser,
    Nuclear
};

enum class MenuType
{
    Purchase,
    In_Game,
    Game_Over
};

enum class Enemy_Type
{

};



inline map<double, Bullet_Type> index_type_map;

