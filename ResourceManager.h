//
// Created by wailer on 16/03/2022.
//

#ifndef PROJECT_RESOURCEMANAGER_H
#define PROJECT_RESOURCEMANAGER_H

#include <cstdlib>
#include <iostream>

#include "allegro/AllegroBase.hpp"

typedef ALLEGRO_BITMAP* img;

// global path to 'sprites' folder, using ONLY FORWARD SLASHES
// in my case, this is "D:/All/Coding/C++/project/sprites/"
// on progmeistars courses "D:/Andrejs Pirozenoks/Lesson 8/DoodleJump/sprites/"
const std::string FILEPATH = "D:/All/Coding/C++/project/sprites/";

class ResourceManager {
private:
    ResourceManager();

public:
    static ResourceManager &Instance() {
        static ResourceManager instance;
        return instance;
    }

    ALLEGRO_FONT *font;

    img sprite_player_right;
    img sprite_player_left;
    img sprite_player_dead;

    img sprite_enemy_simple;
    img sprite_enemy_simple_victory;
    img sprite_enemy_simple_dead;

    img sprite_enemy_large;
    img sprite_enemy_large_victory;
    img sprite_enemy_large_dead;

    img sprite_enemy_small;
    img sprite_enemy_small_victory;
    img sprite_enemy_small_dead;

    img sprite_enemy_flying;
    img sprite_enemy_flying_victory;
    img sprite_enemy_flying_dead;

    img sprite_platform;
    img sprite_platform_fake;
    img sprite_platform_fake_broken;
    img sprite_platform_moving;

    img sprite_spring;
    img sprite_spring_triggered;
};

#endif //PROJECT_RESOURCEMANAGER_H
