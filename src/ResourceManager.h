//
// Created by wailer on 16/03/2022.
//

#ifndef PROJECT_RESOURCE_MANAGER_H
#define PROJECT_RESOURCE_MANAGER_H

#include <memory>

#include "allegro/AllegroBase.hpp"

typedef ALLEGRO_BITMAP *img;

// Relative path to the sprites folder.
const std::string FILEPATH = "sprites";

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

class str_exception : public std::exception {
   public:
    std::string string;
    str_exception(std::string s) : string(s) {}
    ~str_exception() throw() {}
    const char *what() const throw() { return string.c_str(); }
};

#endif  // PROJECT_RESOURCE_MANAGER_H
