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
    inline double getDegree(double x, double y)
    {
        return atan2(x, y);
    }

    inline double getDistance(Pos pos1, Pos pos2)
    {
        double disX = pow(pos1.x - pos2.x, 2);
        double disY = pow(pos1.y - pos2.y, 2);
        return sqrt(disX + disY);
    }
    [[noreturn]] inline void error(const std::string& s) { throw std::runtime_error(s); }
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
constexpr Color BLACK{ 0 };
constexpr Color BULLET_1_COLOR{255};
constexpr Color BULLET_2_COLOR{ 0, 255, 0 };
constexpr Color BULLET_3_COLOR{ 0, 0, 255, 100 };
constexpr Color BULLET_4_COLOR{ 255, 0, 0 };
constexpr Color BULLET_5_COLOR{ 255, 255, 0 };

void setup();
constexpr int get_splash_time(int time);
