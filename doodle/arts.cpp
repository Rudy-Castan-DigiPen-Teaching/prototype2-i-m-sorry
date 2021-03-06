//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020

#include "arts.h"
void arts::PlaySound(int index)
{
    for (auto& sound : Sounds)
    {
        if (sound.getStatus() != sf::SoundSource::Playing)
        {
            sound.setBuffer(SoundBuffers[index]);
            sound.play();
            return;
        }
    }
    Sounds.emplace_back(SoundBuffers[index]);
    Sounds.back().play();
}

void arts::LoadSound(const std::string& file_path)
{
    SoundBuffers.emplace_back();
    sf::SoundBuffer& buffer = SoundBuffers.back();
    if (!buffer.loadFromFile(file_path))
    {
        helper::error("failed to load " + file_path);
    }
}

void arts::setup()
{
    LoadSound("assets/Rock.wav");
    LoadSound("assets/Pistol.ogg");
    LoadSound("assets/Barrier.wav");
    LoadSound("assets/Laser.wav");
    LoadSound("assets/Nuclear.ogg");
    LoadSound("assets/Not_enough.wav");
}