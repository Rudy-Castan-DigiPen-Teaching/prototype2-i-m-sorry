//Daehyeon Kim, Hyeong Ahn, Sunwoo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#pragma once
#include "main_header.h"
struct arts
{
public:
    std::vector<sf::SoundBuffer> SoundBuffers{};
    std::vector<sf::Sound>       Sounds{};
    sf::Music                    music;
    void LoadSound(const std::string& file_path);
    void PlaySound(int index);
    void setup();
};

enum sounds {
    LaserSound
};