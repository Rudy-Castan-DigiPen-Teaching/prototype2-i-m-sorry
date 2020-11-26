//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#pragma once
#include <iostream>
#include <doodle/doodle.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <map>
#include <SFML/Audio.hpp>
#include "pos.h"
using namespace std;
using namespace doodle;

namespace helper {
    extern double getDegree(double x, double y);
    extern double getDistance(Pos pos1, Pos pos2);
    extern void error(const std::string& s);
}

enum class Bullet_Type
{
    Rock,
    Pistol,
    Barrier,
    Laser,
    Nuclear
};

enum class MenuType
{
    Splash,
    Purchase,
    In_Game,
    Game_Over,
    Quit
};


inline MenuType MENU{ MenuType::Splash };
inline map<double, Bullet_Type> index_type_map;
constexpr int STARTMONEY{ 500 };
inline int MONEY{ STARTMONEY };
inline int LEVEL{1};


