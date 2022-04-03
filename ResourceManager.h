//
// Created by wailer on 16/03/2022.
//

#ifndef PROJECT_RESOURCEMANAGER_H
#define PROJECT_RESOURCEMANAGER_H

#include <cstdlib>
#include <iostream>

#include "allegro/AllegroBase.hpp"

class ResourceManager {
private:
    ResourceManager();

public:
    static ResourceManager &Instance() {
        static ResourceManager instance;
        return instance;
    }

    ALLEGRO_FONT *font;

    ALLEGRO_BITMAP *sprite_player_right;
    ALLEGRO_BITMAP *sprite_player_left;

    ALLEGRO_BITMAP *sprite_enemy_simple;

    ALLEGRO_BITMAP *sprite_platform;

};

// global path to 'sprites' folder, using ONLY FORWARD SLASHES
// in my case, this is "D:/All/Coding/C++/project/sprites/"
// on progmeistars courses "D:/Andrejs Pirozenoks/Lesson 8/DoodleJump/sprites/"
const std::string FILEPATH = "D:/All/Coding/C++/project/sprites/";


#endif //PROJECT_RESOURCEMANAGER_H
