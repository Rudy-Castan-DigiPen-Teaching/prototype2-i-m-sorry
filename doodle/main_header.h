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

namespace helper {
    extern double getDegree(double x, double y);
    extern double getDistance(Pos pos1, Pos pos2);
}

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
    User_Info,
    Purchase,
    In_Game,
    Game_Over
};

enum class Enemy_Type
{
    Air,
    Ground
};


inline MenuType MENU{ MenuType::Purchase };
inline map<double, Bullet_Type> index_type_map;
constexpr int STARTMONEY{ 500 };
inline int MONEY{ STARTMONEY };
inline int LEVEL{1};


