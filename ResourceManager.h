//
// Created by wailer on 16/03/2022.
//

#ifndef PROJECT_RESOURCEMANAGER_H
#define PROJECT_RESOURCEMANAGER_H

#include "allegro/AllegroBase.hpp"
#include <iostream>

// global path to 'sprites' folder, using ONLY FORWARD SLASHES
// in my case, this is "D:/All/Coding/C++/project/sprites/"
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

    ALLEGRO_BITMAP *sprite_player;

    ALLEGRO_BITMAP *sprite_platform;

};


#endif //PROJECT_RESOURCEMANAGER_H
