//Dae Hyeon Kim, Hyoung Won An, Sun Woo Lee
//Prototype-2
//CS120(GAM100)
//Fall, 2020
#include "menu.h"

void BuyScene::buyBullet(KeyboardButtons button)
{
    if (button == KeyboardButtons::_1)
    {
        if (MONEY - 100 >= 0)
        {
            MONEY -= 100;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end()) //check if the key word(index) exists
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Rock));
                    bullet_count[0]++;
                    
                    break;
                }
            }
        }
        else
        {
            //not enough minerals 음성출력
        }
    }
    else if (button == KeyboardButtons::_2)
    {
        if (MONEY - 200 >= 0)
        {
            MONEY -= 200;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Pistol));
                    bullet_count[1]++;
                    
                    break;
                }
            }
        }
        else
        {
            // not enough minerals 음성출력
        }
    }
    else if (button == KeyboardButtons::_3)
    {
        if (MONEY - 250 >= 0)
        {
            MONEY -= 250;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Barrier));
                    bullet_count[2]++;
                    
                    break;
                }
            }
        }
        else
        {
            // not enough minerals 음성출력
        }
    }
    else if (button == KeyboardButtons::_4)
    {
        if (MONEY - 500 >= 0)
        {
            MONEY -= 500;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Laser));
                    bullet_count[3]++;
                    
                    break;
                }
            }
        }
        else
        {
            // not enough minerals 음성출력
        }
    }
    else if (button == KeyboardButtons::_5)
    {
        if (MONEY - 1000 >= 0)
        {
            MONEY -= 1000;
            while (true)
            {
                double index = random(0., 100.);
                if (index_type_map.find(index) == index_type_map.end())
                {
                    index_type_map.insert(make_pair(index, Bullet_Type::Nuclear));
                    bullet_count[4]++;
                    
                    break;
                }
            }
        }
        else
        {
            // not enough minerals 음성출력
        }
    }

}

void BuyScene::draw_button()
{
    double x{ Width / 10. };
    double x_increase{ Width / 6. };
    push_settings();
    set_font_size(30);
    set_fill_color(255);
    draw_rectangle(x, Height / 2, 200.);
    draw_text("1: Rock", x, Height / 2);
    set_fill_color(0, 255, 0, 255);
    draw_rectangle(x += x_increase, Height / 2, 200.);
    draw_text("2: Pistol", x, Height / 2);
    set_fill_color(0, 0, 255, 255);
    draw_rectangle(x += x_increase, Height / 2, 200.);
    draw_text("3: Barrier", x, Height / 2);
    set_fill_color(255, 0, 0, 255);
    draw_rectangle(x += x_increase, Height / 2, 200.);
    draw_text("4: Laser", x, Height / 2);
    set_fill_color(255, 255, 0, 255);
    draw_rectangle(x += x_increase, Height / 2, 200.);
    draw_text("5: Nuclear", x, Height / 2);
    pop_settings();
}

void BuyScene::draw_count()
{
    double x{ Width / 10. };
    double x_increase{ Width / 6. };

    push_settings();
    draw_text(to_string(bullet_count[0]), x, Height/2 -100.);
    draw_text(to_string(bullet_count[1]), x += x_increase, Height / 2 - 100.);
    draw_text(to_string(bullet_count[2]), x += x_increase, Height / 2 - 100.);
    draw_text(to_string(bullet_count[3]), x += x_increase, Height / 2 - 100.);
    draw_text(to_string(bullet_count[4]), x += x_increase, Height / 2 - 100.);
    pop_settings();
}

void BuyScene::reset_count()
{
    for (int i = 0; i < bullet_count.size(); i++)
    {
        bullet_count[i] = 0;
    }
}

void BuyScene::draw_info()
{
    push_settings();
    draw_text("Gold: " + to_string(MONEY), 0, Height - 100.);
    draw_text("Level: " + to_string(LEVEL), 0, Height - 200.);
    set_font_size(30);
    draw_text("Press S to Start new wave or Save ", 0, 200);
    draw_text("Press R to Restart new game ", 0, 100);
    draw_text("Press Q to Quit", 0, 0);

    draw_text("I'm sorry", Width * 3 / 4, Height / 4);
    draw_text("Dae Hyeon Kim", Width * 3 / 4, Height / 4 - 50);
    draw_text("Hyoung Won An", Width * 3 / 4, Height / 4 - 100);
    draw_text("Sun Woo Lee", Width * 3 / 4, Height / 4 - 150);
    pop_settings();
}